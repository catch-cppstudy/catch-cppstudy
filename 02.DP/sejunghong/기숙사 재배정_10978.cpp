//백준 10978 기숙사 재배정
#include <iostream>

using namespace std;

long long dp[21] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	dp[1] = 0; dp[2] = 1;
	for (int i = 3; i <= 20; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1);
	}

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}