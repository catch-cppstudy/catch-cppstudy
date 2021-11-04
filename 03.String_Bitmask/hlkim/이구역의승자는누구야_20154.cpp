#include <iostream>
using namespace std;

int main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int stroke[28] = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
  int sum = 0;
  string str;
  cin >> str;
  for(int alpha = 0; alpha < str.size(); alpha++) {
    sum = (sum + stroke[str[alpha]-'A']) % 10;
  }
  if(sum % 2 == 1)  cout << "I'm a winner!\n";
  else cout << "You're the winner?\n";
  return 0;
}
