#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;

int m, n, h;
int tomato[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX] = { false, };
int dx[] = { 0,0,1,-1,0,0 }; 
int dy[] = { 1,-1,0,0,0,0 }; 
int dz[] = { 0,0,0,0,1,-1 };

queue<pair<pair<int, int>, int>> q;
int day = -1; 
int tomatos = 0; //모두 익거나 익지 못하는 경우를 위해

/*
	1 : 익은 토마토, 0 : 익지 않은 토마토, -1 : 토마토 없음
*/

void bfs() {
	while (!q.empty()) {
		day++;

		int qSize = q.size(); //q 크기가 변하니까
		for (int i = 0; i < qSize; i++) {
			int nowX = q.front().first.first;
			int nowY = q.front().first.second;
			int nowZ = q.front().second;
			q.pop();

			//위, 아래, 상하좌우 탐색
			for (int i = 0; i < 6; i++) {
				int nextX = nowX + dx[i];
				int nextY = nowY + dy[i];
				int nextZ = nowZ + dz[i];

				if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || nextZ < 0 || nextZ >= h)
					continue;

				if (!visit[nextX][nextY][nextZ] && tomato[nextX][nextY][nextZ] == 0) {
					visit[nextX][nextY][nextZ] = true;
					q.push({ {nextX, nextY}, nextZ });
					tomatos--;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) { //익은 토마토
					visit[i][j][k] = true;
					q.push({ {i, j}, k });
				}
				if (tomato[i][j][k] == 0) //익지않은 토마토
					tomatos++;
			}
		}
	}

	if (tomatos == 0) { //모두 익은 상태
		cout << tomatos;
		return 0;
	}

	bfs();

	if (tomatos > 0) //돌 수 있는 곳은 다 돌았지만, 아직 토마토를 다 익히지 못함
		cout << -1;
	else
		cout << day;

	return 0;
}
