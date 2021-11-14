#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string str, bomb, answer;
  cin >> str >> bomb;
  
  int len = bomb.size();
  int slen = str.size();

  for(int i = 0; i < slen; i++) {
    answer+=str[i];
    // str이 아닌 answer.back()와 비교
    if(answer.back() == bomb[len-1] && i+1 >= len) {
      bool check = true;
      int alen = answer.size();
      for(int j = len-2; j >= 0; j--)
      {
        if(answer[alen-(len-j)] != bomb[j]) {
          check=false;
          break;
        }
      }
      if(check) {
        for(int j = 0; j < len; j++)
          answer.pop_back();
      }
    }
  }
    
  if(answer.empty()) {
    cout << "FRULA";
  }
  else
    cout << answer;
  return 0;

}
