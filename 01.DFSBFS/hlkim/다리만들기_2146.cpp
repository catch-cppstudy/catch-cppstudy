#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
using namespace std;
int n; 
int board[101][101];
bool check[101][101];
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
map <int, queue<pair<int, int>>> mp; //나라 별로 저장할 좌표

void dfs(int x, int y, int cnt) {
  check[x][y] = true;
  board[x][y] = cnt;
  mp[cnt].push({x, y});
  for(int i = 0; i < 4; i++) {
    int cx = x + way[i][0];
    int cy = y + way[i][1];
    if (cx <=0 || cx > n || cy <= 0 || cy > n) continue;
    if (check[cx][cy] == false && board[cx][cy] == 1) dfs(cx, cy, cnt);
  }
}

int bfs(int ground) {
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(board[i][j] == ground) check[i][j] = true;

  int area = 0, cnt = 0;
  int start = mp[ground].size();
  while(!mp[ground].empty()) {
    int x = mp[ground].front().first;
    int y = mp[ground].front().second;
    /* Increase area */
    if(++cnt > start) {
      area += 1;
      cnt = 1;
      start = mp[ground].size();
    }
    mp[ground].pop();

    for(int i = 0; i < 4; i++) {
      int cx = x + way[i][0];
      int cy = y + way[i][1];
      if (cx <=0 || cx > n || cy <= 0 || cy > n) continue;
      if (check[cx][cy] == false && board[cx][cy] == 0) {
        mp[ground].push({cx, cy});
        check[cx][cy] = true;
      }
      else if(board[cx][cy] > 0 && board[cx][cy] != ground) return area;  
    }
  }
  return area;
}

int main(){
  int idx=0;
  scanf("%d", &n);
  for(int i = 1; i<= n; i++)
    for(int j = 1; j <= n; j++)
      scanf("%d", &board[i][j]);

  for(int i = 1; i<= n; i++)
    for(int j = 1; j <= n; j++)
      if(board[i][j] == 1 && check[i][j] == false)
        dfs(i, j, ++idx);
  
  int ans = INT_MAX;
  for(int i = 1; i <= idx; i++) {
    memset(check, false, sizeof(check));
    ans = min(bfs(i), ans);
  }
  printf("%d\n", ans);
  return 0;
}
