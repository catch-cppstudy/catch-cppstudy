#include <string>
#include <vector>
#include <queue>
using namespace std;
bool check[201];
void dfs(vector<vector<int>> computers, int x) {
    check[x] = true;
    for (int i = 0; i < computers[x].size(); i++) {
        if(i == x)  continue;
        if(check[i] == false && computers[x][i] == 1)   dfs(computers, i);
    }
    return;
}

void bfs(vector<vector<int>> computers, int x) {
    check[x] = true;
    queue<int> que;
    que.push(x);
    while(!que.empty()) {
        int tmp = que.front();
        que.pop();
        for(int i = 0; i < computers.size(); i++) {
            if (i == tmp)   continue;
            if(check[i] == false && computers[tmp][i] == 1) {
                check[i] = true;
                que.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        // 정점별로 체크
        if (check[i] == false) {
            //dfs(computers, i);
            bfs(computers, i);
            ++answer;
        }
    }
    return answer;
}