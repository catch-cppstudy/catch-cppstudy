//백준 20154 이 구역의 승자는 누구야?!
#include <iostream>
#include <string>

int alpha_num[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += alpha_num[s[i] - 'A'];
		if (sum > 9)
			sum %= 10;
	}
	
	//홀수
	if (sum % 2 == 1)
		cout << "I'm a winner!\n";
	//짝수
	else
		cout << "You're the winner?\n";

	return 0;
}
//걸린시간 10분
