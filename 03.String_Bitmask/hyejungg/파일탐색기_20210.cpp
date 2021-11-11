#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;

//숫자인지 문자인지 확인
bool isNumber(string s)
{
    if (s[0] >= '0' && s[0] <= '9')
        return true;
    return false;
}

bool cmp(vector<string> &a, vector<string> &b)
{
    int len = min(a.size(), b.size());

    for (int i = 0; i < len; i++)
    {
        //앞에는 숫자 뒤에는 문자일때
        if (isNumber(a[i]) && !isNumber(b[i]))
        {
            return true;
        }

        //앞에는 문자 뒤에는 숫자일때
        else if (!isNumber(a[i]) && isNumber(b[i]))
        {
            return false;
        }

        //둘다 숫자일때
        else if (isNumber(a[i]) && isNumber(b[i]))
        {
            int aZeroCnt = 0;
            int bZeroCnt = 0;
            string originA = "";
            string originB = "";

            for (int j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] == '0')
                    aZeroCnt++;
                else
                {
                    originA = a[i].substr(aZeroCnt, a[i].size() - aZeroCnt);
                    break;
                }
            }

            for (int j = 0; j < b[i].size(); j++)
            {
                if (b[i][j] == '0')
                    bZeroCnt++;
                else
                {
                    originB = b[i].substr(bZeroCnt, b[i].size() - bZeroCnt);
                    break;
                }
            }

            //같은 값을 가지는 숫자일때
            if (originA == originB)
            {
                //앞의 0의 개수가 적은것이 앞에온다
                if (aZeroCnt < bZeroCnt)
                    return true;

                else if (aZeroCnt > bZeroCnt)
                    return false;
            }

            //다른 값을 가지는 숫자일때
            else
            {

                if (originA.size() < originB.size())
                    return true;

                else if (originA.size() > originB.size())
                    return false;

                else //두 숫자가 같은 자리수일때
                {
                    for (int j = 0; j < originA.size(); j++)
                    {
                        if (originA[j] < originB[j])
                            return true;

                        else if (originA[j] > originB[j])
                            return false;
                    }
                }
            }
        }

        //둘다 문자일때
        else if (!isNumber(a[i]) && !isNumber(b[i]))
        {
            int i_len = min(a[i].size(), b[i].size());

            for (int j = 0; j < i_len; j++)
            {
                // a, b를 모두 소문자로 바꾼 뒤 오름차순 정렬
                if (tolower(a[i][j]) < tolower(b[i][j]))
                    return true;

                else if (tolower(a[i][j]) > tolower(b[i][j]))
                    return false;
                // a와 b가 모두 같은 글자라면
                else
                {
                    if ((a[i][j] >= 'A' && a[i][j] <= 'Z') && (b[i][j] >= 'a' && b[i][j] <= 'z')) //대문자를 앞으로
                        return true;
                    else if ((a[i][j] >= 'a' && a[i][j] <= 'z') && (b[i][j] >= 'A' && b[i][j] <= 'Z'))
                        return false;
                }
            }

            if (a[i].size() < b[i].size())
                return true;

            else if (a[i].size() > b[i].size())
                return false;
        }
    }

    if (a.size() < b.size())
        return true;

    else
        return false;

    return true;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<string> files[10000];

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        string temp = "";
        bool number = false;
        for (int j = 0; j < str.size(); j++)
        {
            if (islower(str[j]) || isupper(str[j]))
            {
                if (temp == "")
                {
                    temp += str[j];
                }

                else if (number) //숫자를 저장중 이었다면
                {
                    files[i].push_back(temp);

                    temp = "";
                    temp += str[j];
                }

                else if (!number) //영어 단어를 저장중이었다면
                {
                    temp += str[j];
                }

                number = false;
            }

            else if (isdigit(str[j]))
            {
                if (temp == "")
                {
                    temp += str[j];
                }

                else if (number) //숫자를 저장중 이었다면
                {
                    temp += str[j];
                }

                else if (!number) //영어 단어를 저장중이었다면
                {
                    files[i].push_back(temp);

                    temp = "";
                    temp += str[j];
                }
                number = true;
            }

            if (j == str.size() - 1 && temp.size() != 0)
                files[i].push_back(temp);
        }
    }
    sort(files, files + n, cmp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < files[i].size(); j++)
            cout << files[i][j];
        cout << "\n";
    }
}