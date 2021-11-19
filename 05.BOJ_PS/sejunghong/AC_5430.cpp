//���� 5430 AC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string rd;
		cin >> rd;
		int num;
		cin >> num;
		//vector<int> v; //vector ���� �� �� O(n) �� �� O(1)
		deque<int> dq;  //deque ���� �� �� O(1) �� �� O(1)
		string s;
		cin >> s;
		string temp;
		for (int j = 0; j < s.size(); j++) {
			if (isdigit(s[j])) {
				temp += s[j];
			}
			else {
				//���� ������ ��
				if (temp != "") {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		int error_check = 0;
		
		int r = 0; // r�� Ȧ���� �Ųٷ�, r�� ¦���� �״��
		for (int j = 0; j < rd.size(); j++) {
			if (rd[j] == 'R') {
				r++;
			}
			else {
				if (dq.empty()) {
					cout << "error" << "\n";
					error_check = 1;
					break;
				}
				//¦�� : ���� �� ������
				if (r % 2 == 0) {
					dq.pop_front();
				}
				//Ȧ�� : ���� �� ������
				else {
					dq.pop_back();
				}
			}
		}

		if (error_check == 0) {
			cout << "[";
			if (r % 2 == 1) {
				//Ȧ���� �� ����� ���
				for (int j = dq.size()-1; j >= 0; j--) {
					cout << dq[j];
					if (j != 0)
						cout << ",";
				}
			}
			else {
				for (int j = 0; j < dq.size(); j++) {
					cout << dq[j];
					if (j != dq.size() - 1)
						cout << ",";
				}
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}