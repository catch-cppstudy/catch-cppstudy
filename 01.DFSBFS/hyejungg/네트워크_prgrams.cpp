#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 201;
int visit[MAX] = {
    false,
};

void DFS(vector<vector<int>> computers, int start)
{
    visit[start] = true;

    // start와 연결된 노드 탐색
    for (int i = 0; i < computers[start].size(); i++)
    {
        //방문하지 않았으면서, 1이고, 대각선이 같지 않은
        if (!visit[i] && computers[start][i] && i != start)
        {
            DFS(computers, i);
        }
    }
}

void BFS(vector<vector<int>> computers, int start)
{
    visit[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int nowStart = q.front();
        q.pop();

        for (int i = 0; i < computers[start].size(); i++)
        {
            //방문하지 않았으면서, 1이고, 대각선이 같지 않은
            if (!visit[i] && computers[nowStart][i] && i != start)
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    //(0,0)부터 탐색
    for (int i = 0; i < computers.size(); i++)
    {
        if (!visit[i])
        {
            // BFS(computers, i);
            DFS(computers, i);
            answer++;
        }
    }
    return answer;
}