#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int board[101][101];
int check[101][101];
int way[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
int n;
int bfs(int rain) {
  int safe = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if((check[i][j] == false) && (board[i][j] > rain)) {
        queue<pair<int, int> > que;
        que.push({i, j});
        check[i][j] = true;
        while(!que.empty()) {
          pair<int, int> here = que.front();
          que.pop();
          for(int k = 0; k < 4; k++) {
            int cx = here.first + way[k][0];
            int cy = here.second + way[k][1];
            if(cx >= 0 && cx < n && cy >= 0 && cy < n) {
              if(check[cx][cy] == false && board[cx][cy] > rain) {
                que.push({cx, cy});
                check[cx][cy] = true;
              }
            }
          }
        }
        safe+=1;
      }
    }
  }
  if(!safe) return 0;
  return safe;
}
int main() {

  int _max = 0, _min = 101; 
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
     for(int j = 0; j < n; j++) {
        scanf("%d", &board[i][j]);
        _max = max(_max, board[i][j]);
        _min = min(_min, board[i][j]);
     }
  }
  if(_min == _max) {
    if(_min == 1 || _min == 100) printf("1\n");
    return 0;
  }

  int safety, answer = 0;
  for(int i = 1; i <= _max; i++) {
    memset(check, false, sizeof(check));
    safety = bfs(i);  // 강수량 마다 확보할 수 있는 안전영역의 갯수를 리턴할 것임.
    if(answer < safety) answer = safety;
  }
  printf("%d\n", answer);
  
	return 0;
}
