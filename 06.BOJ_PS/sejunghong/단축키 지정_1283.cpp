//���� 1283 ����Ű ����
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
	getline(cin, N); //���� ���� �Է¹ޱ�
	for (int i = 0; i < stoi(N); i++) {
		string s;
		getline(cin, s);

		stringstream stream1(s);
		string temp = "";
		int location = 0;
		int check = 0;
		for (int i = 0; i < 5; i++){
			stream1 >> temp;
			//ù ���� ����Ű
			if (alpha[toupper(temp[0]) - 'A'] == 0) {
				alpha[toupper(temp[0]) - 'A'] = 1;
				check = 1;
				break;
			}
			location += temp.size() + 1; //��ġ
		}

		if (check != 1) {
			for (int j = 0; j < s.size(); j++) { 
				if (s[j] == ' ') //������ �ƴҶ�

					continue;
				if (alpha[toupper(s[j]) - 'A'] == 0) {
					alpha[toupper(s[j]) - 'A'] = 1;
					location = j;
					break; 
				}
			}
		}

		//���
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