//세정님 코드 손민수 ...
#include <iostream>
#include <string>
using namespace std;

// re는 유사회문 판단
int isPalindrome(string s, int re)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        { //회문 아님
            if (re == 0)
            {
                int len = end - start;
                //왼쪽, 오른쪽 한 개씩 삭제했을 때
                if (isPalindrome(s.substr(start + 1, len), 1) == 0 || isPalindrome(s.substr(start, len), 1) == 0)
                    return 1;
                else
                    return 2;
            }
            else
                return 2;
        }
        start++;
        end--;
    }
    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string s;
        cin >> s;
        cout << isPalindrome(s, 0) << "\n";
    }
    return 0;
}

//시간초과
#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string s)
{
    int answer = 0;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] == s[j])
        {
            continue;
        }
        else
        { //회문이 아님
            if (s[i + 1] != s[j] && s[i] != s[j - 1])
            { //하나를 삭제해도 회문 X
                answer = 2;
                break;
            }
            for (int k = 0; k < 2 && answer != 1; k++)
            {
                int start = i;
                int end = j;
                k == 0 ? start++ : end--;
                answer = 1;
                for (int st = start, en = end; st < en; st++, en--)
                {
                    if (s[st] != s[en])
                    {
                        answer = 2;
                        break;
                    }
                }
            }
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string s;
        cin >> s;
        cout << isPalindrome(s) << "\n";
    }

    return 0;
}