//���� 17609 ȸ��
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//check=0 : ȸ�� �Ǵ�, check=1 : ����ȸ�� �Ǵ�
int palindrome(string s, int check) {
	int left, right;
	left = 0; right = s.size() - 1; //���� ��, ������ ��

	while (left < right) {
		if (s[left] != s[right]) {
			if (check == 0) {
				//���� ȸ������ �Ǵ�
				int len = right - left;
				if (palindrome(s.substr(left + 1, len), 1) == 0 || palindrome(s.substr(left, len), 1) == 0)
					return 1; //���� ȸ���� �� ��
				else
					return 2; //���� ȸ���� �ƴ� ��
			}
			else
				return 2;
		}
		left++;
		right--;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		cout << palindrome(s, 0) << "\n";
	}

	return 0;
}