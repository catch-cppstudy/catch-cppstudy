#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 열쇠 소유 여부 -> 비트로 표현
// a를 갖은 경우 : 000001
// a,d,f를 갖은 경우 : 101001
// 열쇠 표시 -> OR(|)연산, 열쇠로 문 열 수 있는지 확인 -> AND(&)연산

int N, M;
char arr[51][51] = {
    '.',
};

bool visit[51][51][1 << 6]; // x, y, key여부
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(int a, int b)
{
    queue<pair<pair<int, int>, pair<int, int>>> q; //{{x, y}, {이동횟수, 현재 갖은 키}}
    q.push({{a, b}, {0, 0}});
    visit[a][b][0] = true; //[0] 아무 key도 갖고 있지 않은 상태에서 시작

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;
        q.pop();

        if (arr[x][y] == '1')
            return cnt; //현재 도착점이라면 return

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                continue;

            if (!visit[nextX][nextY][key])
            {
                if (arr[nextX][nextY] == '.' || arr[nextX][nextY] == '1')
                {
                    visit[nextX][nextY][key] = true;
                    q.push({{nextX, nextY}, {cnt + 1, key}});
                }
                else if (arr[nextX][nextY] >= 'a' && arr[nextX][nextY] <= 'f')
                {                                                             //열쇠라면
                    int tmpKey = key | (1 << (int(arr[nextX][nextY] - 'a'))); //|연산으로 6개 비트 중 해당 인덱스를 열쇠 표시 (ex. a : 000001)
                    visit[nextX][nextY][tmpKey] = true;
                    q.push({{nextX, nextY}, {cnt + 1, tmpKey}});
                }
                else if (arr[nextX][nextY] >= 'A' && arr[nextX][nextY] <= 'F')
                {                                                            //문이라면
                    int value = key & (1 << (int(arr[nextX][nextY]) - 'A')); //갖고 있는 key가 문에 열리는지 &연산으로 확인
                    // cout << "value : " << value << "\n";
                    if (value != 0)
                    { // 0이 아니라면 해당 문의 열쇠를 갖고 있다는 의미
                        visit[nextX][nextY][key] = true;
                        q.push({{nextX, nextY}, {cnt + 1, key}});
                    }
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    pair<int, int> startPos;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            //시작 지점은 빈 곳이기도 하니까 좌표 저장 후 .으로 다시 초기화
            if (arr[i][j] == '0')
            {
                startPos.first = i;
                startPos.second = j;
                arr[i][j] = '.';
            }
        }
    }
    int answer = BFS(startPos.first, startPos.second);
    cout << answer;
}