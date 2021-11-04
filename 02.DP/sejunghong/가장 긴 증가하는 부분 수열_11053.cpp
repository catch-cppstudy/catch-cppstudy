//백준 가장 긴 증가하는 부분 수열 11053
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int max_num = 0; 
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) // 작은 수 
				max_num = max(max_num, dp[j]); // 작은 수 중 길이가 가장 긴 것
		}
		dp[i] = max_num + 1; //가장 긴 것을 골라 +1(자기 자신 추가)
		answer = max(answer, dp[i]); //가장 긴 길이
	}

	cout << answer << "\n";

	return 0;
}