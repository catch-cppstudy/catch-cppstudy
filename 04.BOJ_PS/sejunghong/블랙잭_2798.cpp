//백준 2798 블랙잭 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	vector <int> card;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		card.push_back(n);
	}

	int answer = 0;
	//3중 for문 3개 선택
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k]; //3개 카드 합
				if (sum <= M) {
					answer = max(answer, sum);
				}

			}
		}
	}
	cout << answer << "\n";

	
	return 0;
}
