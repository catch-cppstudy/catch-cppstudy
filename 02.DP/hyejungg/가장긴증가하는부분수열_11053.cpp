#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int n;
vector<int> sequence;

int main(void)
{
    int ans = 0;
    cin >> n;

    //예외처리
    if (n >= MAX)
    {
        return -1;
    }

    vector<int> dp(n + 1, 0); //연속된 수열 개수 저장
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sequence.push_back(num);

        int dpMax = 0;
        for (int j = 0; j < sequence.size(); j++)
        {
            if (sequence[i] > sequence[j])
            { //지금 입력한 값이 이전 값보다 크면서
                if (dpMax < dp[j])
                { // dp에 있는 값보다 크다면 dp 내 가장 큰 값 갱신
                    dpMax = dp[j];
                }
            }
        }
        dp[i] = dpMax + 1; // idx
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
