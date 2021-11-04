//���� ���� �� �����ϴ� �κ� ���� 11053
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
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
			if (v[i] > v[j]) // ���� �� 
				max_num = max(max_num, dp[j]); // ���� �� �� ���̰� ���� �� ��
		}
		dp[i] = max_num + 1; //���� �� ���� ��� +1(�ڱ� �ڽ� �߰�)
		answer = max(answer, dp[i]); //���� �� ����
	}

	cout << answer << "\n";

	return 0;
}