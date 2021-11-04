#include <stdio.h>
using namespace std;

int n, m;
int board[2001];
bool palindrome[2001][2001];  //palindrome[s][e] 가 팰린드롬인지 판단

void inputStream() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &board[i]);
  }
  scanf("%d", &m);
}

void Initialize() {
  for(int i = 1; i <= n; i++) {
    palindrome[i][i] = true;
    if(board[i] == board[i+1])
      palindrome[i][i+1] = true;
  }
}
/*
bool isPalindrom(int a, int b) {
  int target = b;
  for(int start = a; start < b; start++) {
    palindrome[start][target] = (board[start] == board[target]) ? true : false;
    if(!palindrome[start][target]) return false; 
    //printf("start : %d, target:%d = %d\n", start, target, palindrome[start][target]);
    target-=1;
  }
  return true;
}
*/
void isPalindrome() {
  for(int i = n-1; i >= 1; i--) { //Top-down : 사이에 있는 값을 알기 위해
    for(int j = i+2; j <= n; j++) { // 차이가 3인 아이 부터 검사
      palindrome[i][j] = ((board[i] == board[j]) && (palindrome[i+1][j-1])) ? true : false;
    }
  }

}

int main(){
  inputStream();
  Initialize();
  isPalindrome();
  
  for(int i = 0; i < m; i++) {
    int s, e, ret;
    scanf("%d %d", &s, &e);
    printf("%d\n", palindrome[s][e]);
  }

/* DEBUG
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
      printf("%d ", palindrome[i][j]);
    printf("\n");
  }
*/
  return 0;
}
