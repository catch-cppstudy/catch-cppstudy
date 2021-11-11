//백준 20210 파일 탐색기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(vector<string>& a, vector<string>& b) {
	int min_size = min(a.size(), b.size());

	for (int i = 0; i < min_size; i++) {
		//두 문자가 같지 않을 때
		if (a[i] != b[i]) {
			//둘 다 숫자일 때
			if (a[i][0] >= '0' && a[i][0] <= '9' && b[i][0] >= '0' && b[i][0] <= '9') {
				//앞 0없앤 진짜 수
				string a_num = "";
				string b_num = "";
				for (int j = 0; j < a[i].size(); j++) {
					if (a[i][j] != '0') {
						a_num = a[i].substr(j);
						break;
					}
				}
				for (int j = 0; j < b[i].size(); j++) {
					if (b[i][j] != '0') {
						b_num = b[i].substr(j);
						break;
					}
				}
				//수가 같을 때
				if (a_num == b_num) {
					//0이 더 많은 수 뒤로
					return a[i].size() < b[i].size();
				}
				//수가 다를 때
				else {
					// 3 , 12 비교 12 < 3이 큼
					if (a_num.size() < b_num.size())
						return true;
					else if (a_num.size() > b_num.size())
						return false;
					else {
						if (a_num < b_num)
							return true;
						return false;
					}
				}
			}

			//둘 중 하나가 숫자일 때
			if ((a[i][0] >= '0' && a[i][0] <= '9') || (b[i][0] >= '0' && b[i][0] <= '9')) {
				return a[i] < b[i];
			}

			//둘다 영어일 때
			if (toupper(a[i][0]) == toupper(b[i][0])) {
				return a[i] < b[i];
			}
			return toupper(a[i][0]) < toupper(b[i][0]); //대문자 변환 더 큰 값
		}
	}

	//비교할 수 있는 사이즈까지 똑같을 때 사이즈 작은 순으로 정렬
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<string>> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vector<string> temp;
		string s_temp;
		for (int j = 0; j < s.size(); j++) {
			//숫자
			if (s[j] >= '0' && s[j] <= '9')
				s_temp += s[j];
			//숫자 이 외
			else {
				//숫자가 이미 저장되어 있을 때
				if (s_temp != "")
					temp.push_back(s_temp);
				s_temp = s[j];
				temp.push_back(s_temp);
				s_temp = "";//수 초기화
			}
		}
		if (s_temp != "")
			temp.push_back(s_temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);
	
	//출력
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}


	return 0;
}
//걸린 시간 : 3시간