#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int sum, int depth)
{
    if (depth == numbers.size())
    { //인덱스가 끝까지 다했을 때
        if (sum == target)
        {
            answer++; //가능한 경우를 ++
        }
        return;
    }
    DFS(numbers, target, sum + numbers[depth], depth + 1); //더하는 경우
    DFS(numbers, target, sum - numbers[depth], depth + 1); //빼는 경우
}

void BFS(vector<int> numbers, int target, int start)
{
    queue<int> q; // sum 보관
    q.push(start);

    for (int i = 0; i < numbers.size(); i++)
    {
        int qSize = q.size();
        for (int j = 0; j < qSize; j++)
        {
            int sum = q.front();
            q.pop();

            q.push(sum + numbers[i]); //+인 경우
            q.push(sum - numbers[i]); //-인 경우
        }
    }

    while (!q.empty())
    {
        if (q.front() == target)
        {
            answer++;
        }
        q.pop();
    }
}

int solution(vector<int> numbers, int target)
{
    // 0번째 인덱스부터 시작
    // DFS(numbers, target, 0, 0);
    BFS(numbers, target, 0); //시간 초과

    return answer;
}