#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1000001;
const string target = "pPAp";

int n;
string str;

//완탐? DP?
int getpPapCnt()
{
    int cnt = 0;
    //문자열 처음부터 끝까지 탐색
    for (int i = 0; i < str.size(); i++)
    {
        if (str.substr(i, 4) == target)
        { // i번째부터 4글자의 글자가 펜-파인애플-애플-펜이면
            cnt++;
            i += 3; //탐색 할 i 재정의
        }
    }
    return cnt;
}

int main(void)
{
    cin >> n;
    cin >> str;

    //예외처리
    if (str.size() >= MAX)
        return -1;
    if (str.size() >= 4)
    {
        cout << getpPapCnt();
    }
    else
    {
        cout << 0;
    }
}
