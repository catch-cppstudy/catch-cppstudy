//���� 7569 �丶��
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int M, N, H; //M:���� N:���� H:����
int box[102][102][102];
int ni[6] = { 1,0,-1,0,0,0 }, nj[6] = { 0,1,0,-1,0,0 }, nk[6] = { 0,0,0,0,1,-1 };
int visited[102][102][102] = { 0, };
int cnt_day = 0;

//��ġ
struct point {
	int k;
	int i;
	int j;
};

queue<point> q; // queue

void BFS() {

	while (!q.empty()) {
		int c_k = q.front().k;
		int c_i = q.front().i;
		int c_j = q.front().j;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int n_k = c_k + nk[i];
			int n_i = c_i + ni[i];
			int n_j = c_j + nj[i];
			if (n_k < 0 || n_i < 0 || n_j < 0 || n_k >= H || n_i >= N || n_j >= M)
				continue;
			//�湮���� �ʰ� ���� ���� �丶���� ��
			if (box[n_k][n_i][n_j] == 0 && visited[n_k][n_i][n_j] == 0) {
				point p = { n_k, n_i, n_j};
				visited[n_k][n_i][n_j] = visited[c_k][c_i][c_j] + 1;
				q.push(p);
				cnt_day = max(cnt_day, visited[n_k][n_i][n_j]); //���� ū ��
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int num;
				cin >> num;
				box[k][i][j] = num;
				//���� �丶�� queue�� push
				if (num == 1) {
					point p = { k,i,j };
					q.push(p);
					visited[k][i][j] = 0;
				}
			}
		}
	}

	BFS();

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//��� ���� ���ϴ� ��Ȳ
				if (box[k][i][j] == 0 && visited[k][i][j] == 0) {
					cout << "-1" << "\n";
					return 0;
				}
			}
		}
	}

	cout << cnt_day << "\n";

	return 0;
}