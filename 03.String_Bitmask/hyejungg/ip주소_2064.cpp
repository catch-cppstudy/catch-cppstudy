#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int ipAddress[1000];

void print(int num) // 32비트짜리 숫자
{
    int shift = 24;
    for (int i = 0; i < 4; i++, shift -= 8) // 24, 16, 8, 0
    {
        // 8개 비트씩 10진수로 출력
        cout << ((num >> shift) & (1 << 8) - 1);
        if (i != 3)
            cout << '.';
    }
    cout << "\n";
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str, tmp;
        cin >> str;
        istringstream ss(str);
        while (getline(ss, tmp, '.'))
        {
            ipAddress[i] <<= 8;        // 1바이트 씩 자리 만들어 주기 (00000000)
            ipAddress[i] |= stoi(tmp); // |연산해서 해당 숫자를 비트로 표현
        }
    }

    // 1. 서브넷 마스크를 구한다.
    int subnet = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = 1 << i; //(1 << i를 이용하면 i번째 값을 찾을 수 있음)
        bool diff = false;

        for (int j = 1; j < n; j++)
        {
            //첫번째 ip주소와 이외 ip주소들을 비교하면서 다른 부분을 찾음
            if ((ipAddress[0] & bit) != (ipAddress[j] & bit))
            {
                diff = true; //다른 부분이 있다면
                break;
            }
        }
        if (diff)
            break;
        else //공통 부분을 1로 채움
            subnet |= bit;
    }

    // 2. 네트워크 주소, 서브넷 마스크를 구한다.
    print(ipAddress[0] & subnet); // IP주소 & 서브넷 마스크 = 네트워크 주소 (포함되는 IP주소가 가장 적은 네트워크를 구해야해서 [0])
    print(subnet);
}