#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 101;
const int MIN = 0;

int N;
int arr[MAX][MAX] = {
    0,
};
int maxValue = MIN, minValue = MAX;

bool visit[MAX][MAX] = {
    false,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int height)
{
    //위치를 기준으로 상하좌우 탐색하며 안전 구역 탐색
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
        {
            continue;
        }
        if (arr[nextX][nextY] > height && !visit[nextX][nextY])
        {
            visit[nextX][nextY] = true;
            DFS(nextX, nextY, height);
        }
    }
}

void resetVisit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visit[i][j] = false;
        }
    }
}

int main()
{
    int ans = 1;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            //입력 중 큰 값과 작은 값을 구함
            maxValue = max(maxValue, arr[i][j]);
            minValue = min(minValue, arr[i][j]);
        }
    }

    for (int i = minValue; i < maxValue; i++)
    {
        int cnt = 0;
        resetVisit();

        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                if (arr[row][col] > i && !visit[row][col])
                {
                    visit[row][col] = true;
                    cnt++;
                    DFS(row, col, i);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}