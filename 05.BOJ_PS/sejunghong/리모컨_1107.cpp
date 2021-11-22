//���� 1107 ������
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int button[10] = { 0, };

//���峭 ��ư�� �������� �Ǵ�
bool button_check(string num) {
	for (int i = 0; i < num.size(); i++) {
		if (button[num[i] - '0'] == 1)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		button[num] = 1;
	}

	if (N == "100") {
		cout << "0" << "\n";
		return 0;
	}

	int count_100 = max(100, stoi(N)) - min(100, stoi(N)); //100������ +, -

	int count = 0;
	string num_up = N;
	string num_down = N;
	while (1) {
		//100������ +-�Ѱͺ��� Ŭ ��
		if (count + num_down.size() > count_100) {
			count = count_100;
			break;
		}
		//
		if (button_check(num_down) == true && stoi(num_down) >= 0) {
			count += num_down.size();
			break;
		}
		else if (button_check(num_up) == true) {
			count += num_up.size();
			break;
		}
		num_up = to_string(stoi(num_up) + 1); // +1
		num_down = to_string(stoi(num_down) - 1); /// -1
		count++;
	}
	cout << count << "\n";



	return 0;
}