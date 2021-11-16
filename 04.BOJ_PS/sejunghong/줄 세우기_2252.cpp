//백준 2252 줄세우기
#include <iostream>
#include <vector>

using namespace std;

vector<int> front[32002]; //앞에 있는 노드
int visited[32002] = { false, }; //방문 여부

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < front[node].size(); i++) {
		if(visited[front[node][i]] == false) // 앞에 있는 노드 중 방문되지 않은 노드
			DFS(front[node][i]);
	}
	cout << node << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		front[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		if(visited[i] == false)
			DFS(i);
	}

	cout << "\n";

	return 0;
}