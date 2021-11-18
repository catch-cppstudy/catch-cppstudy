//백준 2460 지능형기차2
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p = 0;
	int max_p = 0;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		p -= a;
		p += b;
		max_p = max(max_p, p);
	}
	cout << max_p << "\n";

	return 0;
}
