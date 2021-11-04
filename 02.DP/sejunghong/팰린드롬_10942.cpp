//백준 팰린드롬? 10942
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int S, E;
int dp[2001][2001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	//길이 1
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}
	//길이 2
	for (int i = 1; i < N; i++) {
		if(v[i] == v[i+1]) //첫번째 수와 두번째 수가 같을 때
			dp[i][i + 1] = 1;
	}
	//길이 3이상
	for (int i = 2; i < N; i++) { //length
		for (int j = 1; j <= N-i; j++) { //left
			if (v[j] == v[i + j] && dp[j + 1][i + j - 1])
				dp[j][i + j] = 1;
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}

	return 0;
}

//시간 초과
/*
vector<int> v;
int S, E;

bool palindrome(int left, int right) {

	while (S <= left) {
		if (v[left] != v[right])
			return false;
		left--;
		right++;
	}
	return true;
}

int main() {
	//입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		//길이 홀수 
		if ((E - S) % 2 == 0) {
			if (palindrome((E + S) / 2 - 2, (E + S) / 2) == true)
				cout << "1\n";
			else
				cout << "0\n";
		}
		//길이 짝수
		else {
			if(palindrome((E + S) / 2 - 1, (E + S) / 2) == true)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}
*/