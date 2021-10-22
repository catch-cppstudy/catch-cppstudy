#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool check[10001];
vector<int> vec[10001];

void dfs(int start) {
	cout << start << ' ';
	check[start] = true;
	for(int i : vec[start]) {
		if(check[i] == false)
			dfs(i);
	}
}

void bfs(int start) {
	check[start] = true;
	queue<int> que;
	que.push(start);
	while(!que.empty()) {
		int idx = que.front();
		cout << idx << ' ';
		que.pop();
		for(int i : vec[idx]) {
			if (check[i] == false) {
				check[i] = true;
				que.push(i);
			}
		}
	}
	return;
}
int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)	// 범위 조심
		sort(vec[i].begin(), vec[i].end());

	dfs(v);
	cout << '\n';
	memset(check, 0, sizeof(check));
	bfs(v);

	return 0;
}
