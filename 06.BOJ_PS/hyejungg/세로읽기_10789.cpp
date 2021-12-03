#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<char>> arr(5, vector<char>(15, '.'));

    string str = "";
    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            arr[i][j] = str[j];
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j][i] == '.' || arr[j][i] == ' ')
                continue;
            cout << arr[j][i];
        }
    }

    return 0;
}
