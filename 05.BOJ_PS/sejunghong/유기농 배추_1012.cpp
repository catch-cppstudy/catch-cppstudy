//백준 1012 유기농 배추
#include <iostream>
#include <cstring>

using namespace std;

int M, N, K;
int board[51][51];
int visited[51][51];
int ni[4] = { 0,0,1,-1 }, nj[4] = { 1,-1,0,0 };

void DFS(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int n_i = ni[k] + i;
		int n_j = nj[k] + j;
		if (n_i < 0 || n_j < 0 || n_i >= N || n_j >= M)
			continue;
		if (visited[n_i][n_j] == 0 && board[n_i][n_j] == 1)
			DFS(n_i, n_j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		memset(board, 0, sizeof(board)); //초기화
		memset(visited, 0, sizeof(visited)); //초기화
		int count = 0;
		for (int k = 0; k < K; k++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 0 && board[i][j] == 1) {
					DFS(i, j);
					count++;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}