//백준 2146 다리 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> board;
int nexti[4] = { 1,0,-1,0 }, nextj[4] = { 0,1,0,-1 };
int visited[101][101] = { 0, };
vector<pair<int, int>> island; //하나의 섬

void DFS(int c_i, int c_j) {
	visited[c_i][c_j] = 1; //방문
	island.push_back({ c_i, c_j }); //한 지역 push

	for (int k = 0; k < 4; k++) {
		//다음 위치 = 현재위치 + next
		int n_i = c_i + nexti[k];
		int n_j = c_j + nextj[k];
		if (n_i < 0 || n_j < 0 || n_i >= N || n_j >= N)
			continue;

		if (visited[n_i][n_j] == 0 && board[n_i][n_j] == 1)
			DFS(n_i, n_j);
	}

}

int min_bridge(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {

	int min_length = 100000; 
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			//이을 수 있는 다리 길이
			int length = max(a[i].first, b[j].first) - min(a[i].first, b[j].first) 
						+ max(a[i].second, b[j].second) - min(a[i].second, b[j].second) - 1;
			min_length = min(min_length, length); //가장 짧은 다리
		}
	}
	return min_length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
		}
		board.push_back(temp);
	}

	vector<vector<pair<int, int>>> islands;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			island.clear(); //초기화
			if (visited[i][j] == 0 && board[i][j] == 1) {
				DFS(i, j);
				islands.push_back(island);
			}
		}
	}

	int answer = 1000000;
	for (int i = 0; i < islands.size() - 1; i++) {
		for (int j = i + 1; j < islands.size(); j++) {
			answer = min(answer, min_bridge(islands[i], islands[j])); //가장 짧은 거리
		}
	}

	cout << answer << "\n";


	return 0;
}
//걸린 시간 : 40분