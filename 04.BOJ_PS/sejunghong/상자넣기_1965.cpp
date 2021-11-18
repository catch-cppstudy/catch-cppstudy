//백준 1965 상자넣기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> box;
	int dp[1001];
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num; 
		box.push_back(num);
		int pre_max = 0;
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i])
				pre_max = max(pre_max, dp[j]);
		}
		dp[i] = pre_max + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	return 0;
}