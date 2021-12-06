//백준 20116 상자의 균형
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int L;
	
	cin >> n >> L;

	double sum = 0;
	vector <double> box;
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		box.push_back(num);
		sum += num;
	}

	for (int i = 0; i < n - 1; i++) {
		sum -= box[i];
		double center = sum / (n - i - 1);
		if (box[i] - L >= center || box[i] + L <= center) {
			cout << "unstable" << "\n";
			return 0;
		}
	}

	cout << "stable" << "\n";

	return 0;
}