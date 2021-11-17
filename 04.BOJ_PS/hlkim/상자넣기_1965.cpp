#include <stdio.h>
using namespace std;

int dp[1001];
int box[1001];
int main(){
  int n, mx = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &box[i]);
    dp[i] = 1;
  }
  for(int i = 1; i < n; i++) {
    for(int j = i-1; j >= 0; j--) {
      if(box[j] < box[i]) {
        /* 넣을 수 있는 상자를 발견하면, 
           그 순번이 가지고 있는 상자수가 자신이 보유한 상자수보다 크거나 같다면 +dp 배열 업데이트 
           작다면 이미 그 상자를 포함한 수를 더해준 것과 같음
        */
        if(dp[j] >= dp[i])  
          dp[i] = dp[j] + 1;
      }
    }
    if(mx < dp[i])  mx = dp[i];
  }
  printf("%d\n", mx);
  return 0;
}

