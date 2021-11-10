//백준 1194 달이 차오른다, 가자. 
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int ni[4] = { 1,0,-1,0 }, nj[4] = { 0,1,0,-1 };

int n, m;

//d[][][0] 은 아무 열쇠도 안가진 상태
int  d[51][51][1 << 7];
char board[51][51];

int key[27];
struct node {
	int i, j;
	int key;
};

int BFS(int i, int j){
	queue<node> q;
	memset(d, -1, sizeof(d)); //초기화

	for (int k = 0; k < 4; ++k) {
		q.push({ i,j,0 });
		d[i][j][0] = 0;
	}

	int check = false;

	int ret = -1;
	while (!q.empty()) {
		int c_i = q.front().i;
		int c_j = q.front().j;
		int key = q.front().key;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int n_i = c_i + ni[k];
			int n_j = c_j + nj[k];
			int n_key = key;

			if (board[n_i][n_j] == '1') {
				return d[c_i][c_j][key] + 1;
			}

			if (!(0 <= n_i && n_i < n && 0 <= n_j && n_j < m)) continue;
			if (d[n_i][n_j][n_key] != -1) continue;
			if (board[n_i][n_j] == '#') continue;

			if ('A' <= board[n_i][n_j] && board[n_i][n_j] <= 'F') {
				int cnt = board[n_i][n_j] - 'A';
				int cand = n_key;
				if ((cand &= (1 << cnt)) == 0) continue;

			}

			if ('a' <= board[n_i][n_j] && board[n_i][n_j] <= 'f') {
				int cnt = board[n_i][n_j] - 'a';
				n_key |= (1 << cnt);
			}
			q.push({ n_i,n_j,n_key });
			d[n_i][n_j][n_key] = d[c_i][c_j][key] + 1;
		}
		if (check) break;
	}

	return ret;
}
int main() {

	cin >> n >> m;

	int temp_i, temp_j;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				temp_i = i;
				temp_j = j;
			}
		}

	cout << BFS(temp_i, temp_j) << "\n";

	return 0;
}