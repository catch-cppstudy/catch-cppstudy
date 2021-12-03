//백준 2583 영역 구하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int board[101][101] = { 0, };
bool visited[101][101] = { false, };
int nexti[4] = { 1,-1,0,0 }, nextj[4] = { 0,0,1,-1 };
int answer = 0;
int area = 0;

void DFS(int i, int j) {
	visited[i][j] = true;
	answer++;

	for (int k = 0; k < 4; k++) {
		int ni = nexti[k] + i;
		int nj = nextj[k] + j;
		if (ni < 0 || nj < 0 || ni >= M || nj >= N)
			continue;
		if (visited[ni][nj] == false && board[ni][nj] == 0) {
			DFS(ni, nj);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//사각형 역역 1
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				board[y][x] = 1;
			}
		}
	}

	vector <int> v;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			answer = 0;
			if (visited[i][j] == 0 && board[i][j] == 0) {
				DFS(i, j);
				v.push_back(answer);
				area++; //지역 수 
			}
		}
	}
	
	sort(v.begin(), v.end()); //오름차순 정렬

	cout << area << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0;
}
