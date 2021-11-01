//백준 1, 2, 3 더하기 2_12101
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, K;
int arr[3] = { 1,2,3 };
map<string, int> m; //사전순으로 정렬됨

//DFS로 N의 합을 나타냄
void DFS(string s, int sum) {
	for (int i = 0; i < 3; i++) {
		sum += arr[i];
		if (sum > N)
			continue;
		else if (sum == N)
			m[s + to_string(arr[i])]++; //n의 합을 맵에 저장
		else
			DFS(s + to_string(arr[i]) + "+", sum); // "+"와 함께 저장
		sum -= arr[i];
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	DFS("", 0);

	//k번째에 오는 식이 없을 때
	if (K > m.size()) {
		cout << "-1" << "\n";
		return 0;
	}

	int i = 0;
	for (auto it : m) {
		i++;
		if (i == K) {
			cout << it.first << "\n"; //K번째에 오는 수 찾기
		}
	}

	return 0;
}
//걸린 시간 40분
//DP는 개수 구할때 사용. K번째 오는 값을 구하기에는 적합하지 않음?