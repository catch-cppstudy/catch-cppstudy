//���� Pen Pineapple Apple Pen_15881
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string s;
	cin >> s;

	int count = 0;
	for (int i = 0; i < s.size() - 3; i++) {
		//���ڿ� �ڸ���
		if (s.substr(i, 4) == "pPAp") {
			count++;
			i += 3;
		}
	}
	cout << count << "\n";

	return 0;
}
//DP ���?