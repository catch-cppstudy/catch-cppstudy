#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> dp[12]; 

//bool compare (string a, string b) { return a[i] == b[i] ? a < b : a[i] < b[i];} //중간에 문자 하나 비교해서 같으면 사전식, 다르면 문자로 정렬하기
int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, K;
  cin >> n >> K;
  // dp[i] : i를 만들 수 있는 식의 집합 (string)
  dp[1].push_back("1");
  
  dp[2].push_back("1+1");
  dp[2].push_back("2");
  
  dp[3].push_back("1+1+1");
  dp[3].push_back("1+2");
  dp[3].push_back("2+1");
  dp[3].push_back("3");

  for (int i = 4; i <= n; i++) {
    // i보다 1~3 만큼 작은 수의 dp 배열에 순차적으로 +3, +2, +1 문자열을 붙여준다.
    for(int j = 3; j >= 1; j--) {
      for(string k : dp[i-j]) {
        dp[i].push_back(k + "+" + to_string(j));
      }
    }
    stable_sort(dp[i].begin(), dp[i].end());
    /* DEBUG
    for(auto a : dp[i])
      cout << a << '\n';
    */

  }
  if(K > dp[n].size())
    cout << "-1\n";
  else cout << dp[n][K-1] << "\n";

  return 0;
}