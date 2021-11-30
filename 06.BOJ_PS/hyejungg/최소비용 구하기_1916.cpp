#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 123456789

vector<pair<int, int>> w[1001]; //정점별 도착지(first), 가중치(second) 저장
vector<int> dist(1001, INF);    //최소비용 저장

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (cost > dist[curNode]) // *** 없으면 시간초과
            continue;

        for (int i = 0; i < w[curNode].size(); i++)
        {
            int nextCost = dist[curNode] + w[curNode][i].second;
            int nextNode = w[curNode][i].first;

            if (nextCost < dist[nextNode])
            {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        w[start].push_back({end, cost});
    }
    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << dist[end];

    return 0;
}
