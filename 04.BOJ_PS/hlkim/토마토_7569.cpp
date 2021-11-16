#include <stdio.h>
#include <queue>
using namespace std;

bool check[101][101][101];  // 방문 여부
int tomato[101][101][101];  // 토마토 좌표
int day[101][101][101];     // 숙성일
int pos[6][3] = {{-1, 0, 0}, {0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {0, 0, 1}}; // 상우하좌위아래
int N, M, H;
int zerocnt;  // 토마토 총 개수

int bfs()
{
  int cnt = 0;
  for (int k = 1; k <= H; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
      {
        if (tomato[i][j][k] == 1 && check[i][j][k] == false)
        {
          queue<pair<pair<int, int>, int> > que;
          que.push({{i, j}, k});
          check[i][j][k] = true;
          day[i][j][k] = 1;
          while (!que.empty())
          {
            int x = que.front().first.first;
            int y = que.front().first.second;
            int hg = que.front().second;
            que.pop();
            
            for (int p = 0; p < 6; p++)
            {
              int cx = x + pos[p][0];
              int cy = y + pos[p][1];
              int ch = hg + pos[p][2];
              if (cx <= 0 || cx > N || cy <= 0 || cy > M || ch <= 0 || ch > H)
                continue;
              if (tomato[cx][cy][ch] == 0)
              {
                if(check[cx][cy][ch] == false) {
                  check[cx][cy][ch] = true;
                  day[cx][cy][ch] = day[x][y][hg] + 1;
                  que.push({{cx, cy}, ch});
                  cnt += 1;
                }
                else {
                  // 만약 숙성일이 더 짧은 경우가 있는지 판단
                  if(day[cx][cy][ch] > day[x][y][hg] + 1)
                  {
                    day[cx][cy][ch] = day[x][y][hg] + 1;
                    que.push({{cx, cy}, ch});
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  int mx = 0;
  for (int k = 1; k <= H; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        if(mx < day[i][j][k]) mx = day[i][j][k];

  if (cnt == zerocnt) //모든 0을 다 봤을 때
  {
    if(mx == 1) return 0;
    return mx-1;
  }
  else return -1;
}

int main()
{
  scanf("%d%d%d", &M, &N, &H);
  for (int k = 1; k <= H; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
      {
        scanf("%d", &tomato[i][j][k]);
        if (tomato[i][j][k] == 0)
          zerocnt += 1;
      }
    }
  }

  printf("%d\n", bfs());
  return 0;
}