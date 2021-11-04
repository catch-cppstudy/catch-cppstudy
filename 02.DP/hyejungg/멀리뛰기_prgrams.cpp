#include <string>
#include <vector>
using namespace std;

const int MOD = 1234567;

long long dp[2001] = {
    0,
};

long long solution(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    // return dp[n] % MOD; //실패 원인
    return dp[n];
}