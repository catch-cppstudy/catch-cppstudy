//���� 1, 2, 3 ���ϱ� 2_12101
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, K;
int arr[3] = { 1,2,3 };
map<string, int> m; //���������� ���ĵ�

//DFS�� N�� ���� ��Ÿ��
void DFS(string s, int sum) {
	for (int i = 0; i < 3; i++) {
		sum += arr[i];
		if (sum > N)
			continue;
		else if (sum == N)
			m[s + to_string(arr[i])]++; //n�� ���� �ʿ� ����
		else
			DFS(s + to_string(arr[i]) + "+", sum); // "+"�� �Բ� ����
		sum -= arr[i];
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	DFS("", 0);

	//k��°�� ���� ���� ���� ��
	if (K > m.size()) {
		cout << "-1" << "\n";
		return 0;
	}

	int i = 0;
	for (auto it : m) {
		i++;
		if (i == K) {
			cout << it.first << "\n"; //K��°�� ���� �� ã��
		}
	}

	return 0;
}
//�ɸ� �ð� 40��
//DP�� ���� ���Ҷ� ���. K��° ���� ���� ���ϱ⿡�� �������� ����?