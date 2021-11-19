//백준 5430 AC
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
		//vector<int> v; //vector 삭제 맨 앞 O(n) 맨 뒤 O(1)
		deque<int> dq;  //deque 삭제 맨 앞 O(1) 맨 뒤 O(1)
		string s;
		cin >> s;
		string temp;
		for (int j = 0; j < s.size(); j++) {
			if (isdigit(s[j])) {
				temp += s[j];
			}
			else {
				//수가 존재할 때
				if (temp != "") {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		int error_check = 0;
		
		int r = 0; // r이 홀수면 거꾸로, r이 짝수면 그대로
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
				//짝수 : 가장 앞 버리기
				if (r % 2 == 0) {
					dq.pop_front();
				}
				//홀수 : 가장 뒤 버리기
				else {
					dq.pop_back();
				}
			}
		}

		if (error_check == 0) {
			cout << "[";
			if (r % 2 == 1) {
				//홀수일 때 뒤집어서 출력
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