#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int busMax = 0;
    for (int i = 0; i < 10; i++)
    {
        int down, up;
        cin >> down >> up;
        busMax -= down;
        busMax += up;
        answer = max(answer, busMax);
    }

    cout << answer;

    return 0;
}
