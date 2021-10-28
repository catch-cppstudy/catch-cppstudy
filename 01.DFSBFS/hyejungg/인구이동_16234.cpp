#include <iostream>
#include <cstring> //memset
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 51;

int N, L, R;
int arr[MAX][MAX] = {
    0,
};

bool visit[MAX][MAX] = {
    false,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> v; //방문 좌표
int cnt, sum, ans = 0;

bool isUnion(int nextX, int nextY, int nowX, int nowY)
{
    return abs(arr[nextX][nextY] - arr[nowX][nowY]) >= L && abs(arr[nextX][nextY] - arr[nowX][nowY]) <= R;
}

void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
        {
            continue;
        }
        //인접한 국가를 방문하지 않았고, 합칠 수 있다면(L명 이상, R명 이하)
        if (!visit[nextX][nextY] && isUnion(nextX, nextY, x, y))
        {
            visit[nextX][nextY] = true;
            cnt++;
            sum += arr[nextX][nextY]; //합칠 수 있는 국가니까 sum+=
            v.push_back({nextX, nextY});
            DFS(nextX, nextY);
        }
    }
}

int main()
{
    int ans = 0;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (1)
    {
        bool move = false; //인구이동 여부
        memset(visit, false, sizeof(visit));

        //각 나라에 대해서 인구 이동이 가능한지 확인
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visit[i][j])
                {
                    v.clear(); //방문 좌표를 초기화
                    cnt = 1;   //인접 여부 카운팅
                    sum = arr[i][j];
                    visit[i][j] = true;
                    v.push_back({i, j});
                    DFS(i, j);

                    //인접 했다면 연합
                    if (cnt >= 2)
                    {
                        move = true;
                        int avg = sum / cnt;
                        //각 칸의 인구수를 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)로 재정의
                        for (int k = 0; k < v.size(); k++)
                        {
                            arr[v[k].first][v[k].second] = avg;
                        }
                    }
                }
            }
        }
        if (!move)
            break;
        else
            ans++;
    }
    cout << ans;
}