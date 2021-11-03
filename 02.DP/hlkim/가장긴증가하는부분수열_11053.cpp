#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001]; // 현재까지 만들 수 있는 최장 부분 수열의 숫자 갯수
int main(){
  int n, answer = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    dp[i] = 1;
  }

  for(int i = 0; i < n; i++) {
    int target = arr[i];
    // target을 가장 큰 수로 가지는 수열을 찾는다. (Top-down)
    for(int j = i-1; j >= 0; j--) 
      if(target > arr[j]) dp[i] = max(dp[j]+1, dp[i]);
   
    answer = max(dp[i], answer);
  }
  
  printf("%d\n", answer);
  return 0;
}
