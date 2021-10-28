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
            q.push(num - numbers[i]); //����
            q.push(num + numbers[i]); //���ϱ�
        }
    }

    int count = 0;
    while (!q.empty()) {
        if (q.front() == target) //Ÿ�� �ѹ��� ���� ���� ��
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