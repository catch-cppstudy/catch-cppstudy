//슈퍼 마리오 2851
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> mushroom;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		mushroom.push_back(num);
	}

	int close100 = 0;
	int sum = 0;
	int pre_sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += mushroom[i];
		if (abs(sum-100) > abs(pre_sum-100)) {
			close100 = pre_sum;
			break;
		}
		else if (abs(sum - 100) == abs(pre_sum - 100)) {
			close100 = sum;
			break;
		}
		pre_sum = sum;
	}

	if (close100 == 0)
		close100 = sum;

	cout << close100 << "\n";


	return 0;
}
