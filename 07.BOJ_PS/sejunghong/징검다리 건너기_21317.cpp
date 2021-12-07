//백준 21317 징검다리 건너기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> stone(N);
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		stone[i].push_back(a);
		stone[i].push_back(b);
	}
	int k;
	cin >> k;

	int dp1[24] = { 100000, };
	int dp2[24] = { 100000, };

	//초기화
	for (int i = 0; i < 24; i++) {
		dp1[i] = 100000;
		dp2[i] = 100000;
	}
	dp1[1] = 0; dp2[1] = 0;

	for (int i = 1; i < N; i++) {
		dp1[i + 1] = min(dp1[i + 1], dp1[i] + stone[i][0]);
		dp2[i + 1] = min(dp2[i + 1], dp2[i] + stone[i][0]);
		dp1[i + 2] = min(dp1[i + 2], dp1[i] + stone[i][1]);
		dp2[i + 2] = min(dp2[i + 2], dp2[i] + stone[i][1]);

		dp2[i + 3] = min(dp2[i + 3], dp1[i] + k);
	}

	cout << min(dp1[N], dp2[N]) << "\n";

	return 0;
}