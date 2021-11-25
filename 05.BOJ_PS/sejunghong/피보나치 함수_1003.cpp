//���� 1003 �Ǻ���ġ �Լ�
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int dp_zero[41] = { 0, };
	int dp_one[41] = { 0, };
	//�ʱ� ����
	dp_zero[0] = 1; dp_one[0] = 0;
	dp_zero[1] = 0; dp_one[1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2]; // 0 ����
		dp_one[i] = dp_one[i - 1] + dp_one[i - 2]; // 1 ����
	}

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		cout << dp_zero[num] << " " << dp_one[num] << "\n";
	}

	return 0;
}