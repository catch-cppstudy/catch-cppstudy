#include <stdio.h>
using namespace std;

long long dp[22];
int main(){
  int t, n;
  scanf("%d", &t);
  // 완전 순열
  dp[1] = 0; dp[2] = 1;
  for(int i = 3; i <= 21; i++) {
      dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
  }
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
  }
  return 0;
}
