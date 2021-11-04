#include <iostream>
using namespace std;

int N, M;
int arr[2001] = {
    0,
};
bool isPalindrome[2001][2001] = {
    false,
};

void init()
{
    //대각선은 우선 true로 초기화
    for (int i = 1; i <= N; i++)
    {
        isPalindrome[i][i] = true;
    }
    //지금 idx와 다음 idx가 같으면 true로 초기화
    for (int i = 1; i <= N - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            isPalindrome[i][i + 1] = true;
    }
    // isPalindrome[start + 1][end - 1]의 값에 접근
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 2; j <= N; j++)
        {
            // i ~ j가 팰린드롬이려면 i+1 ~ j-1도 팰린드롬
            if (arr[i] == arr[j] && isPalindrome[i + 1][j - 1])
                isPalindrome[i][j] = true;
        }
    }
}

int main(void)
{
    //입출력 향상 (없으면 시간초과 발생)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    init();

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << isPalindrome[s][e] << "\n";
    }
}