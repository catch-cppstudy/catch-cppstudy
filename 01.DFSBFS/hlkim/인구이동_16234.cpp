#include <stdio.h>
#include <queue>
#include <cstdlib>
using namespace std;
int N, L, R;
int check[51][51];
int board[51][51];
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int total; // moving day

void Initialize()
{
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      check[i][j] = 0;
}

void bfs()
{
  bool failFlag = true;
  while (failFlag)
  {
    failFlag = false;
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (check[i][j] == 0)
        {                        
          int cnt = board[i][j]; 
          check[i][j] = 1;
          queue<pair<int, int>> que;
          queue<pair<int, int>> mem;
          que.push({i, j});
          mem.push({i, j});
          while (!que.empty())
          {
            pair<int, int> p = que.front();
            que.pop();
            for (int k = 0; k < 4; k++)
            {
              int cx = p.first + way[k][0];
              int cy = p.second + way[k][1];
              int _abs = abs(board[cx][cy] - board[p.first][p.second]);
              if (cx <= 0 || cx > N || cy <= 0 || cy > N)
                continue;
              if ((check[cx][cy] == 0) && (_abs <= R && _abs >= L))
              {
                check[cx][cy] = 1;
                cnt += board[cx][cy];
                que.push({cx, cy});
                mem.push({cx, cy});
              }
            }
          }
          if (mem.size() > 1) failFlag = true;
          
          /* Integrate the number of Allied countries */
          int len = cnt / mem.size();
          while (!mem.empty())
          { 
            int a = mem.front().first;
            int b = mem.front().second;
            mem.pop();
            board[a][b] = len;
          }
        }
      }
    }
    /* Initialize check[][] for next simulation */
    Initialize();
    if (failFlag) total += 1;
  }
}

int main()
{
  scanf("%d%d%d", &N, &L, &R);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      scanf("%d", &board[i][j]);

  bfs();
  printf("%d\n", total);
  return 0;
}
