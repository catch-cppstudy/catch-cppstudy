#include <iostream>
#include <cmath>

#define max(a, b) a > b ? a : b
using namespace std;

int main(){
  int pre, cur;
  cin >> pre;
  for(int i = 1; i < 10; i++) {
    cin >> cur;
    // 이전까지의 합과 현재까지의 합을 비교
    int cmp1 = abs(100-pre);
    int cmp2 = abs(100-(pre+cur));
    if(cmp1 < cmp2) break;
    else if (cmp1 == cmp2) {
      pre = max(pre, pre+cur);
      break;
    }
    else pre += cur;
  }
  cout << pre;
  return 0;
}