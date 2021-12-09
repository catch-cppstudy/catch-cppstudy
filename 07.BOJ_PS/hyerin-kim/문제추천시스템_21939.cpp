#include <iostream>
#include <queue>
//10:07
using namespace std;

#define pii pair<int, int>
int check[100001]; //현재 문제의 난이도 . 100001: solved
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, M;
  priority_queue<pii, vector<pii>, greater<pii> > minPq;
  priority_queue<pii> maxPq;

  cin >> N;
  while(N--) {
    int no, lank;
    cin >> no >> lank;
    minPq.push({lank, no}); maxPq.push({lank, no});
    check[no] = lank;
  }

  cin >> M;
  while(M--) {
    string cmd;
    cin >> cmd;
    if(cmd == "add") {
      int num, diffi;
      cin >> num >> diffi;
      minPq.push({diffi, num}); maxPq.push({diffi, num});
      check[num] = diffi;
    }
    else if (cmd == "recommend") {
      int idx;
      cin >> idx;
      if(idx == 1) {
        while(check[maxPq.top().second] != maxPq.top().first) {
          maxPq.pop();
        }
        cout << maxPq.top().second << "\n";
      }

      else if(idx == -1) {
        while(check[minPq.top().second] != minPq.top().first) {
          minPq.pop();
        }
        cout << minPq.top().second << "\n";
      }
    }
    else {
      int nu;
      cin >> nu;
      check[nu] = 100001;
    }
  }
  return 0;
}