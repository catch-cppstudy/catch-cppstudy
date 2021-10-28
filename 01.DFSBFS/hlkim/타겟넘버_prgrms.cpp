#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer, sum, idx;
void dfs(vector<int> num, int tar, int sum, int idx) {
    if(idx == num.size()) {
        //cout << "sum is " << sum << '\n';
        if(sum == tar)  answer += 1;
        return;
    }
    dfs(num, tar, sum + num[idx], idx+1);
    dfs(num, tar, sum - num[idx], idx+1);   
}

void bfs(vector<int> num, int tar) {
    queue<int> que;
    que.push(0);
    for(int i = 0; i < num.size(); i++) {
        int len = que.size();
        for(int j = 0; j < len; j++) {
            int tmp = que.front();
            que.push(tmp + num[i]);
            que.push(tmp - num[i]);
            que.pop();
        }
    }
    while(!que.empty()) {
        if(que.front() == tar)	answer += 1;
        que.pop();
    }
}
int solution(vector<int> numbers, int target) {
    //dfs(numbers, target, 0, 0);
    bfs(numbers, target);
    return answer;
}