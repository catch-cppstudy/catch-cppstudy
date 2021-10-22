//���� 1260 DFS�� BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
int graph[1001][1001] = { 0, };
int visited_DFS[1001] = { 0, };
int visited_BFS[1001] = { 0, };

void DFS(int node) {
	visited_DFS[node] = 1; //�湮
	cout << node << " ";
	for (int i = 1; i <= N; i++) {
		//����Ǿ��ְ� �湮���� �ʾ��� ��
		if (graph[node][i] == 1 && visited_DFS[i] == 0) {
			DFS(i);
		}
	}

}

void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited_BFS[node] = 1; //�湮

	while (!q.empty()) {
		int n = q.front(); //���� �� ���
		cout << n << " ";
		for (int i = 1; i <= N; i++) {
			//����Ǿ��ְ� �湮���� �ʾ��� ��
			if (graph[n][i] == 1 && visited_BFS[i] == 0) {
				q.push(i);
				visited_BFS[i] = 1; //�湮
			}
		}
		q.pop();
	}
}

int main() {
	//����ӵ� ���
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

	DFS(V); //���� �켱Ž��
	cout << "\n";
	BFS(V); //���� �켱Ž��
	cout << "\n";

	return 0;
}

//�ɸ� �ð� : 30��