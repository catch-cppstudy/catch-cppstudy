#include <string>
#include <vector>

using namespace std;
long long dp[2001];  // n을 1, 2로 만들 수 있는 경우의 수(가짓 수)
long long solution(int n) {
    long long answer = 0;
    
    dp[1] = 1; 
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] ) % 1234567;
    }
    answer = dp[n];
    return answer;
}