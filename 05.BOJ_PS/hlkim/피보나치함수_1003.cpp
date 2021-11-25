#include <stdio.h>
using namespace std;
//15:20
int dp[41][2];
int main(){
  dp[0][0] = 1; dp[0][1] = 0;
  dp[1][0] = 0; dp[1][1] = 1;

  for(int i = 2; i <= 40; i++)
  {
    dp[i][0] = dp[i-1][0] + dp[i-2][0];
    dp[i][1] = dp[i-1][1] + dp[i-2][1];
  }

  int t;
  scanf("%d", &t);
  
  while(t--) {
    int idx;
    scanf("%d", &idx);
    printf("%d %d\n", dp[idx][0], dp[idx][1]);
  }
  return 0;
}
