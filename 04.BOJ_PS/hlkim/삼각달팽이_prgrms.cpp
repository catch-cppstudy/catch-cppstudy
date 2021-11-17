#include <string>
#include <vector>

using namespace std;
int board[1001][1001];
int way[3][2] = {{1, 0}, {0, 1}, {-1, 0}};

vector<int> solution(int n) {
    vector<int> answer;
    int num = 2, cur = 0;
    int end = n, idx = num;
    int x = 1, y = 1;
    int cx, cy;
    int target = (n * (n+1)) / 2;
    board[1][1] = 1;
    while(num <= target) {
        cx = x + way[cur%3][0];
        cy = y + way[cur%3][1];
        if(cx > 0 && cx <= n && cy > 0 && cy <= n) {
            if(board[cx][cy] == 0)
                board[cx][cy] = num;
            else {
                cy = cur/3 + 1;
                board[cx][cy] = num;
            }
        }
        
        // 방향 전환: 끝에 다달을 때
        if(end == idx) {
            end-=1;
            cur+=1;
            idx = 1;
        }
        else idx += 1;
        
        num += 1;
        x = cx; y = cy;
    }
    
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            if(board[i][j] != 0)
                answer.push_back(board[i][j]);
    return answer;
}