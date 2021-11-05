#include <iostream>
#include <string>
using namespace std;

int n;
bool flag;
int isPalindrome(string s)
{
  int len = s.size() - 1;
  
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != s[len - i])
    {
      string pseudo1 = s.substr(i, ((len - i) - (i)));  // 마지막 제외
      string pseudo2 = s.substr(i+1, ((len - i+1) - (i+1)));  // 첫문자 제외
      
      if(!flag) { // 첫번째로 들어갔을 때 
        flag = true;
        if (isPalindrome(pseudo1) == 0|| isPalindrome(pseudo2) == 0)  //둘 중 하나라도 팰린드롬 
          return 1;
        else return 2;
      }
      else return 2;  // 이미 삭제했는데,, 또 다른 조건이면 그냥 안되는거.
    }
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++) {
    string str;
    cin >> str;
    cout << isPalindrome(str) << '\n';
    flag = false;
  }

  return 0;
}
