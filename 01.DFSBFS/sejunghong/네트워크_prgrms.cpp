#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visited[201] = { 0, };

void DFS(int n, vector<vector<int>>& computers) {
    visited[n] = 1; //�湮

    for (int i = 0; i < computers[n].size(); i++) {
        if (visited[i] == 0 && computers[n][i] == 1) { //������ �湮���� �ʾҰ� ����Ǿ��ִ� ���
            DFS(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            DFS(i, computers); //����� ��Ʈ��ũ ã��
            answer++; //����� ��Ʈ��ũ ����
        }
    }

    return answer;
}