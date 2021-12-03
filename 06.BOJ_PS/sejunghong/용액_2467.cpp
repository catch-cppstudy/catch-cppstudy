//백준 2467 용액
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<long long> liquid;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		liquid.push_back(num);
	}

	//이분 탐색
	int left = 0; 
	int right = N - 1;
	long long min_mix = 2000000001;
	int l1 = liquid[left];
	int l2 = liquid[right];
	while (left < right){
		int mid = liquid[left] + liquid[right];

		int mid_abs = abs(liquid[left] + liquid[right]); // 절댓값

		if (min_mix > mid_abs) {
			min_mix = mid_abs;
			l1 = liquid[left];
			l2 = liquid[right];
		}
		if (mid > 0) {
			right--;
		}else {
			left++;
		}
	}

	cout << l1 << " " << l2 << "\n";
	return 0;
}