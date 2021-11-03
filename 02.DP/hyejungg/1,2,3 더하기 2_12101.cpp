#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<string> ans;

void dfs(int idx, int m, int sum, string str) {
	if (idx == m) {
		if (sum == N)
			ans.push_back(str.substr(1, str.size() - 1));
		return;
	}
	dfs(idx + 1, m, sum + 1, str + "+1");
	dfs(idx + 1, m, sum + 2, str + "+2");
	dfs(idx + 1, m, sum + 3, str + "+3");
}

int main(void)
{
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) 
		dfs(0, i, 0, "");
	//사전순으로 정렬
	sort(ans.begin(), ans.end());
	if (ans.size() >= K)
		cout << ans[K - 1];
	else
		cout << "-1";
}