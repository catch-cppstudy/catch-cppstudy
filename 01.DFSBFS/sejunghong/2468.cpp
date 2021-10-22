//c++스터디 1주차(BFS/DFS) 2468 안전 영역
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int N = 0;
int board[101][101] = { 0, };
int visited[101][101] = { 0, };
int next_i[4] = { 1,0,-1,0 }, next_j[4] = { 0,1,0,-1 };
int depth = 0;

void DFS(int c_i, int c_j) {
	visited[c_i][c_j] = 1;
	
	for (int k = 0; k < 4; k++) {
		int n_i = next_i[k] + c_i;
		int n_j = next_j[k] + c_j;

		//지역 벗어남
		if (n_i < 0 || n_j < 0 || n_i >= N || n_j >= N)
			continue; 
		if (visited[n_i][n_j] == 0 && board[n_i][n_j] > depth)
			DFS(n_i, n_j);

	}
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	map<int, int> m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			m[board[i][j]] = 1;
		}
	}

	int answer = 1; //아무 지역도 물에 잠기지 않을수 있으므로 1로 초기화
	for (auto dep : m) {
		memset(visited, 0, sizeof(visited)); //0으로 초기화, 헤더 cstring 선언
		int area = 0;
		depth = dep.first; //잠기는 높이
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0 && board[i][j] > depth) {
					DFS(i, j);
					area++; //지역 + 
				}
			}
		}
		//모두 물에 잠겼을 때
		if (area == 0)
			break;
		answer = max(answer, area); // 최대 안전 영역
	}

	cout << answer << "\n";

	return 0;
} // 걸린 시간 : 40분