#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> mushroom;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		mushroom.push_back(num);
	}
	
	int pre = 0, sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += mushroom[i];
		if (sum >= 100) {
			if (abs(sum - 100) <= abs(100 - pre))
				cout << sum << "\n";
			else
				cout << pre << "\n";
			return 0;
		}
		pre = sum;
	}

	cout << pre << "\n";

}
