#include <iostream>
#include <string>
using namespace std;

int alphaNumbers[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string str;
    cin >> str;

    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += alphaNumbers[str[i] - 'A'];
        if (sum > 9)
            sum %= 10;
    }

    string answer;
    answer = (sum % 2 == 1) ? "I'am a winner!" : "You're the winner?";
    cout << answer;
}