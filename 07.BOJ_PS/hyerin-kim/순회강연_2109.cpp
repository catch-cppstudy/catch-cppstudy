#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define pii pair<int, int>

int main(){
  int n;
  vector<pii> work; // day, pay
  priority_queue<int, vector<int>, greater<int> > pq;

  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int pay, day; 
    scanf("%d%d", &pay, &day);
    work.push_back({day, pay});
  }
  sort(work.begin(), work.end());
  
  int answer = 0;
  for(int i = 0; i < n; i++) {
    pq.push(work[i].second);
    answer += work[i].second;
    if(pq.size() > work[i].first){
      answer -= pq.top();
      pq.pop();
    }
  }

  printf("%d", answer);

  return 0;
}