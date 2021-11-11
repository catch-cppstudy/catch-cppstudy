//���� 20210 ���� Ž����
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(vector<string>& a, vector<string>& b) {
	int min_size = min(a.size(), b.size());

	for (int i = 0; i < min_size; i++) {
		//�� ���ڰ� ���� ���� ��
		if (a[i] != b[i]) {
			//�� �� ������ ��
			if (a[i][0] >= '0' && a[i][0] <= '9' && b[i][0] >= '0' && b[i][0] <= '9') {
				//�� 0���� ��¥ ��
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
				//���� ���� ��
				if (a_num == b_num) {
					//0�� �� ���� �� �ڷ�
					return a[i].size() < b[i].size();
				}
				//���� �ٸ� ��
				else {
					// 3 , 12 �� 12 < 3�� ŭ
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

			//�� �� �ϳ��� ������ ��
			if ((a[i][0] >= '0' && a[i][0] <= '9') || (b[i][0] >= '0' && b[i][0] <= '9')) {
				return a[i] < b[i];
			}

			//�Ѵ� ������ ��
			if (toupper(a[i][0]) == toupper(b[i][0])) {
				return a[i] < b[i];
			}
			return toupper(a[i][0]) < toupper(b[i][0]); //�빮�� ��ȯ �� ū ��
		}
	}

	//���� �� �ִ� ��������� �Ȱ��� �� ������ ���� ������ ����
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
			//����
			if (s[j] >= '0' && s[j] <= '9')
				s_temp += s[j];
			//���� �� ��
			else {
				//���ڰ� �̹� ����Ǿ� ���� ��
				if (s_temp != "")
					temp.push_back(s_temp);
				s_temp = s[j];
				temp.push_back(s_temp);
				s_temp = "";//�� �ʱ�ȭ
			}
		}
		if (s_temp != "")
			temp.push_back(s_temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);
	
	//���
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}


	return 0;
}
//�ɸ� �ð� : 3�ð�