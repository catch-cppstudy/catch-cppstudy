#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int m, n, k;
int visit[51][51] = {
    false,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(vector<vector<int>> map, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;

            if (!visit[nextX][nextY] && map[nextX][nextY] == 1)
            {
                visit[nextX][nextY] = true;
                q.push({nextX, nextY});
            }
        }
    }
    return 1; //주변 근처를 다 돌면 1
}

void visitInit()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> m >> n >> k;
        vector<vector<int>> map(m, vector<int>(n, 0));
        visitInit();
        // vector<vector<bool>> visit(m, vector<int>(n, false));

        //배추의 위치 input
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        int worm = 0;
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (map[x][y] == 1 && !visit[x][y])
                {
                    worm += BFS(map, x, y);
                }
            }
        }
        cout << worm << "\n";
    }

    return 0;
}
