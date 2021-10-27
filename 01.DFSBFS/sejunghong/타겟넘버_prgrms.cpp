#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<int> numbers, int target) {
    queue<int> q;
    q.push(0);

    for (int i = 0; i < numbers.size(); i++) {
        int s = q.size();
        for (int j = 0; j < s; j++) {
            int num = q.front();
            q.pop();
            q.push(num - numbers[i]); //빼기
            q.push(num + numbers[i]); //더하기
        }
    }

    int count = 0;
    while (!q.empty()) {
        if (q.front() == target) //타겟 넘버와 수가 같을 때
            count++;
        q.pop();
    }

    return count;

}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = BFS(numbers, target);

    return answer;
}