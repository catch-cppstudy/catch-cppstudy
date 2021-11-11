//백준 2064 IP 주소
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

void PrintIP(unsigned int ip) {
	unsigned int bit_mask = (unsigned int)((1 << 8) - 1) << 24;
	unsigned int temp;
	int order = 3;
	string result = "";
	for (int i = 0; i < 4; ++i) {
		temp = ip & bit_mask;
		for (int j = order; j > 0; --j) {
			temp = temp >> 8;
		}
		result += to_string(temp);
		if (i != 3)
			result += ".";

		bit_mask = bit_mask >> 8;
		order--;
	}
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int computer_ips[1000];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s += ".";
		string temp;
		int ip_num = 0;
		int idx = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				temp = s.substr(idx, j - idx + 1);
				ip_num = (ip_num << 8);
				ip_num += stoi(temp);
				idx = j + 1;
			}
		}
		computer_ips[i] = ip_num;
	}

	int network_mask = 0;
	int bit;
	bool check;
	for (int bit_order = 31; bit_order >= 0; --bit_order) {
		bit = 1 << bit_order;
		check = false;

		for (int idx = 1; idx < n; ++idx) {
			if ((computer_ips[0] & bit) != (computer_ips[idx] & bit)) {
				check = true;
				break;
			}
		}

		if (check)
			break;
		else
			network_mask |= bit;
	}

	PrintIP(computer_ips[0] & network_mask);
	PrintIP(network_mask);

	return 0;
}

/* 구글링 : https://everenew.tistory.com/74 */
