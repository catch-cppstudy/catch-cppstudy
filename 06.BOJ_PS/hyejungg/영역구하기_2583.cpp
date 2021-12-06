#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visit[101][101] = {
    false,
};
int cnt, m, n, k;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    visit[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
        {
            if (!visit[nextX][nextY])
                dfs(nextX, nextY);
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visit[x][y] = true;
    q.push({x, y});
    cnt = 1;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
            {
                if (!visit[nextX][nextY])
                {
                    q.push({nextX, nextY});
                    visit[nextX][nextY] = true;
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int r = x1; r < x2; r++)
        {
            for (int c = y1; c < y2; c++)
            {
                visit[r][c] = true;
            }
        }
    }

    multiset<int> answer; //set 쓰면 중복 수를 고려하지 않아서 multiset을 써야 오류 안남!
    //vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                // cnt = 0;
                // dfs(i, j);
                bfs(i, j);
                answer.insert(cnt);
                //answer.push_back(cnt);
            }
        }
    }

    //sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (auto a : answer)
        cout << a << " ";

    return 0;
}