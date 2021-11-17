#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> outdegree[32001];
int indegree[32001];

int main(){
  int n, m;
  int pre, cur;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &pre, &cur);
    outdegree[pre].push_back(cur);
    indegree[cur]+=1;
  }

  // indegree 세기
  queue<int> que;
  for(int i = 1; i <= n; i++){
    if(indegree[i] == 0)  que.push(i);
  }

  for(int i = 1; i <= n; i++) {
    if(que.empty()) break;
    int target = que.front();
    que.pop();
    printf("%d ", target);
    for(int j : outdegree[target]) {
      indegree[j]-=1;
      if(indegree[j] == 0)  que.push(j);
    }
  }
  return 0;
}
