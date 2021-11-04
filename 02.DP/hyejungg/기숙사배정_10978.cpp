#include <iostream>
using namespace std;

long dp[21] = {
    0,
}; // int는 틀림(더해지는 수가 많이 커지는 것으로 추정..)

void init()
{
    dp[1] = 1;
    for (int i = 2; i < 21; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * i;
    }
}

int main(void)
{
    int N, T;
    cin >> T;

    init();

    while (T--)
    {
        cin >> N;
        cout << dp[N - 1] << "\n";
    }
}