//백준 1260 DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
int graph[1001][1001] = { 0, };
int visited_DFS[1001] = { 0, };
int visited_BFS[1001] = { 0, };

void DFS(int node) {
	visited_DFS[node] = 1; //방문
	cout << node << " ";
	for (int i = 1; i <= N; i++) {
		//연결되어있고 방문하지 않았을 때
		if (graph[node][i] == 1 && visited_DFS[i] == 0) {
			DFS(i);
		}
	}

}

void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited_BFS[node] = 1; //방문

	while (!q.empty()) {
		int n = q.front(); //가장 앞 노드
		cout << n << " ";
		for (int i = 1; i <= N; i++) {
			//연결되어있고 방문하지 않았을 때
			if (graph[n][i] == 1 && visited_BFS[i] == 0) {
				q.push(i);
				visited_BFS[i] = 1; //방문
			}
		}
		q.pop();
	}
}

int main() {
	//연산속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFS(V); //깊이 우선탐색
	cout << "\n";
	BFS(V); //넓이 우선탐색
	cout << "\n";

	return 0;
}

//걸린 시간 : 30분