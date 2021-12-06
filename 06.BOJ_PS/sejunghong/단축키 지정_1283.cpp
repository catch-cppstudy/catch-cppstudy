//백준 1283 단축키 지정
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int alpha[26] = { 0, }; //A : 0, Z : 25

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	getline(cin, N); //공백 포함 입력받기
	for (int i = 0; i < stoi(N); i++) {
		string s;
		getline(cin, s);

		stringstream stream1(s);
		string temp = "";
		int location = 0;
		int check = 0;
		for (int i = 0; i < 5; i++){
			stream1 >> temp;
			//첫 글자 단축키
			if (alpha[toupper(temp[0]) - 'A'] == 0) {
				alpha[toupper(temp[0]) - 'A'] = 1;
				check = 1;
				break;
			}
			location += temp.size() + 1; //위치
		}

		if (check != 1) {
			for (int j = 0; j < s.size(); j++) { 
				if (s[j] == ' ') //공백이 아닐때

					continue;
				if (alpha[toupper(s[j]) - 'A'] == 0) {
					alpha[toupper(s[j]) - 'A'] = 1;
					location = j;
					break; 
				}
			}
		}

		//출력
		for (int i = 0; i < s.size(); i++) {
			if (i == location) {
				cout << "[" << s[i] << "]";
			}
			else
				cout << s[i];
		}

		cout << "\n";


	}
	return 0;
}