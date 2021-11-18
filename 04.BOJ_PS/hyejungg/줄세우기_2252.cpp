#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//위상정렬 : 일으 ㅣ순서를 정하는 정렬

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> inNodes(n + 1, 0);       //해당 노드에 몇개 진입 가능한지
    vector<vector<int>> outNodes(n + 1); //해당 노드에서 진출 가능한 노드들
    for (int i = 0; i < m; i++)
    {
        int front, back;
        cin >> front >> back;
        inNodes[back]++;
        outNodes[front].push_back(back);
    }

    queue<int> q; //위상정렬을 위해 q선언
    for (int i = 1; i <= n; i++)
        if (inNodes[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front(); // 0인 노드를 탐색
        q.pop();

        cout << cur << " ";
        for (int i = 0; i < outNodes[cur].size(); i++)
        {
            int next = outNodes[cur][i];
            inNodes[next]--;

            if (inNodes[next] == 0)
                q.push(next);
        }
    }

    return 0;
}