//백준 9935 문자열 폭발
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	string bam;
	cin >> bam;
	
	string answer = "";
	for (int i = 0; i < s.size(); i++) {
		answer += s[i];
		if (answer.size() >= bam.size()) {
			if (bam == answer.substr(answer.size() - bam.size(), bam.size())) {
				for (int k = 0; k < bam.size(); k++)
					answer.pop_back();
			}
		}
	}

	if (answer == "")
		cout << "FRULA" << "\n";
	else
		cout << answer << "\n";

	return 0;
}