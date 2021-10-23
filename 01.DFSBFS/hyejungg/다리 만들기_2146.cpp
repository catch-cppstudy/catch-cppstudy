#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;

int N;
int arr[MAX][MAX] = {
    0,
};

bool visit[MAX][MAX] = {
    false,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isRange(int nextX, int nextY)
{
    return (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N);
}

void mapGroupping(int x, int y, int cnt)
{
    //섬을 1, 2, 3 ... 이런 식으로 그룹핑
    arr[x][y] = cnt;
    visit[x][y] = true;

    //상하좌우로 탐색하며 1인 곳이 있다면 해당 섬
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isRange(nextX, nextY))
        {
            if (arr[nextX][nextY] != 0 && !visit[nextX][nextY])
            {
                mapGroupping(nextX, nextY, cnt);
            }
        }
    }
}

int getBridgeSize(int cnt)
{
    // 1. 해당 섬의 좌표를 큐에 넣음
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == cnt)
            {
                visit[i][j] = true;
                q.push({i, j});
            }
        }
    }
    // 2. 섬과 다음 섬 간의 거리를 구함
    int dist = 0;
    while (!q.empty())
    {
        int qSize = q.size(); //오답원인 warning: comparison of integer expressions of different signedness
        for (int i = 0; i < qSize; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nextX = x + dx[j];
                int nextY = y + dy[j];

                if (isRange(nextX, nextY))
                {
                    //다음 땅이 0이 아니고, 남의 땅을 밟았다면 다리 완성
                    if (arr[nextX][nextY] && arr[nextX][nextY] != cnt)
                    {
                        return dist;
                    }
                    //바다인 경우
                    else if (!arr[nextX][nextY] && !visit[nextX][nextY])
                    {
                        visit[nextX][nextY] = true;
                        q.push({nextX, nextY});
                    }
                }
            }
        }
        dist++;
    }
    return 0;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int count = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && !visit[i][j])
            {
                mapGroupping(i, j, count++);
            }
        }
    }

    int ans = 987654321; //큰 값으로 초기화
    for (int i = 1; i < count; i++)
    {
        memset(visit, false, sizeof(visit));
        ans = min(ans, getBridgeSize(i));
    }
    cout << ans;
    return 0;
}
