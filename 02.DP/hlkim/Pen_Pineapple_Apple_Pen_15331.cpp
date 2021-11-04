#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  string ppap = "pPAp";
  int n, answer = 0;
  string str;
  cin >> n >> str;

  for(int i = 0; i < n; i++) {
    if(str[i] == 'p') {
      bool flag = true;
      for (int j = 0; j < 4; j++)
      {
        if (str[j + i] != ppap[j])
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {
        answer += 1;
        i += 3;
      }
    }
  }

  cout << answer << "\n";
  return 0;
}