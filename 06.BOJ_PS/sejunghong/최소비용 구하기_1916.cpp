//���� 1916 �ּҺ�� ���ϱ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321
//ó�� min_cost = 100001�� ���� ����
//�� ������ ���̰� 100000 �ִ� ����� ���̴� �� ����� �� ����
int graph[1001][1001];
bool visited[1001] = { false, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		graph[s][e] = min(graph[s][e], cost);
	}

	int S, E;
	cin >> S >> E;

	visited[S] = true;
	while (!visited[E]) {
		int min_cost = 987654321;
		int min_city = 0;
		//���� �Ÿ��� ª�� ���� ã��
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false && graph[S][i] != INF) {
				if (min_cost > graph[S][i]) {
					min_cost = graph[S][i];
					min_city = i;
				}
			}
		}
		visited[min_city] = true;

		for (int i = 1; i <= N; i++) {
			if (visited[i] == false && graph[min_city][i] != INF) {
				graph[S][i] = min(graph[S][i], graph[S][min_city] + graph[min_city][i]);
			}
		}

	}
	
	cout << graph[S][E] << "\n"; //���
	
	return 0;
}