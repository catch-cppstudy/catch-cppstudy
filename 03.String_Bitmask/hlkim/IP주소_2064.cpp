#include <iostream>
#include <string>
#include <sstream>
using namespace std;

unsigned int ip[1001];

void printIP(unsigned int addr) {
  for(int i = 3; i >= 0; i--) {
    cout << ((addr&(0xFF << (8*i))) >> (8*i));
    if(i > 0) cout << ".";
  }
  cout << "\n";
}
void parsingIp(string s, int idx) {
  int cur = 0, pre = 0;
  for(int i = 0; i < 4; i++) {
    cur = s.find('.', pre);
    if(cur != string::npos || i == 3) {
      unsigned int octet = stoi(s.substr(pre, cur - pre));
      ip[idx] <<= 8;
      ip[idx] |= octet;
      pre = cur+1;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; 
  cin >> n; 
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    parsingIp(s, i);
  }

  // SUBNET MASK
  unsigned int subnet = 0;
  bool flag = false;
  for(int i = 31; i >= 0; i--) {
    unsigned int start = ip[0] & (1 << i);
    for(int j = 1; j < n; j++) {
      if(start != (ip[j] & (1 << i))) {
        flag = true;
        break;
      }   
    }
    if(flag)  break;
    subnet |= (1 << i); //자리수기억
  }

  printIP(subnet & ip[0]);
  printIP(subnet);
  return 0;
}


/*
3
194.85.160.177
194.85.160.183
194.85.160.178
*/
