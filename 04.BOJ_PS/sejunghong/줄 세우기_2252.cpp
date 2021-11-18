//���� 2252 �ټ����
#include <iostream>
#include <vector>

using namespace std;

vector<int> front[32002]; //�տ� �ִ� ���
int visited[32002] = { false, }; //�湮 ����

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < front[node].size(); i++) {
		if(visited[front[node][i]] == false) // �տ� �ִ� ��� �� �湮���� ���� ���
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