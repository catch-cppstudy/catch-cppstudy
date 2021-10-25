//백준 16234 인구 이동
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, L, R;
vector<vector<int>> board;
int visited[51][51] = { 0, };
int nexti[4] = { 1,0,-1,0 }, nextj[4] = { 0,1,0,-1 };
int area_sum = 0, area_count = 0;
vector<pair<int, int>> together;

void DFS(int c_i, int c_j) {
	visited[c_i][c_j] = 1;
	area_sum += board[c_i][c_j]; //연합의 인구
	area_count++; //연합의 크기
	together.push_back({c_i, c_j});

	for (int k = 0; k < 4; k++) {
		int n_i = c_i + nexti[k];
		int n_j = c_j + nextj[k];
		if (n_i < 0 || n_j < 0 || n_i >= N || n_j >= N) {
			continue;
		}
		if (visited[n_i][n_j] == 0) {
			int x = max(board[c_i][c_j], board[n_i][n_j]) - min(board[c_i][c_j], board[n_i][n_j]);
			if (L <= x && x <= R) {
				DFS(n_i, n_j);
			}
		}
	}
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
		}
		board.push_back(temp);
	}

	int answer = 0;
	while (1) {
		memset(visited, 0, sizeof(visited)); // 0으로 초기화
		int check = 0;
		vector<vector<pair<int, int>>> vec;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					together.clear(); // 초기화
					area_sum = 0; area_count = 0;
					DFS(i, j);
					//국경선이 열릴 수 있을 때
					if (together.size() != 1) {
						//가장 뒤에 sum, count추가
						together.push_back({ area_sum, area_count });
						vec.push_back(together);
						check = 1;
					}
				}
			}
		}

		//열릴 수 있는 국경선이 없을 때
		if (check == 0)
			break;
		else {
			//국경선을 열어 인구 이동
			for (int i = 0; i < vec.size(); i++) {
				int s_c = vec[i][vec[i].size() - 1].first / vec[i][vec[i].size() - 1].second;
				for (int j = 0; j < vec[i].size() - 1; j++) {
					board[vec[i][j].first][vec[i][j].second] = s_c;
				}
			}
		}
		answer++; //하루
	}
	
	cout << answer << "\n";


	return 0;
}