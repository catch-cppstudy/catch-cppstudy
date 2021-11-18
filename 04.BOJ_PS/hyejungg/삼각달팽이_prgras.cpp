#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> numbers(n, vector<int>(n, 0));

    int num = 1, x = 0, y = 0, state = 0;

    for (int i = 0; i < n; i++)
    {
        if (state == 0)
        { //좌하향
            for (int j = i; j < n; j++)
                numbers[x++][y] = num++;
            x--;
            y++;
            state = 1;
            continue;
        }
        else if (state == 1)
        { //우측
            for (int j = i; j < n; j++)
                numbers[x][y++] = num++;
            x--;
            y -= 2;
            state = 2;
            continue;
        }
        else if (state == 2)
        { //좌상향
            for (int j = i; j < n; j++)
                numbers[x--][y--] = num++;
            x += 2;
            y++;
            state = 0;
            continue;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (numbers[i][j] != 0)
                answer.push_back(numbers[i][j]);
    }

    return answer;
}