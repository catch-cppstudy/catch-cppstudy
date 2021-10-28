#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;

int N, M, V; //정점 수, 간선 수, 시작노드
int arr[MAX][MAX] = {
    0,
};

bool visit[MAX];

void DFS(int start)
{
    visit[start] = true;
    cout << start << " ";

    for (int next = 1; next <= N; next++)
    {
        if (!visit[next] && arr[start][next] == 1)
        {
            DFS(next);
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;
    cout << start << " ";

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next = 1; next <= N; next++)
        {
            if (!visit[next] && arr[now][next] == 1)
            {
                visit[next] = true;
                q.push(next);
                cout << next << " ";
            }
        }
    }
}

void resetVisit()
{
    for (int i = 1; i <= N; i++)
    {
        visit[i] = false;
    }
}

int main()
{
    // input
    cin >> N >> M >> V;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    // output
    resetVisit();
    DFS(V);

    cout << "\n";

    resetVisit();
    BFS(V);
}