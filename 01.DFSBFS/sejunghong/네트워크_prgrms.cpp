#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visited[201] = { 0, };

void DFS(int n, vector<vector<int>>& computers) {
    visited[n] = 1; //방문

    for (int i = 0; i < computers[n].size(); i++) {
        if (visited[i] == 0 && computers[n][i] == 1) { //이전에 방문되지 않았고 연결되어있는 노드
            DFS(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            DFS(i, computers); //연결된 네트워크 찾기
            answer++; //연결된 네트워크 증가
        }
    }

    return answer;
}