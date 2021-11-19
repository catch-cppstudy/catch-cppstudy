#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

// vector의 reverse, erase 사용하면 시간초과
//이유 ... : https://www.acmicpc.net/board/view/25456
// R이 나왔다고 무작정 뒤집으면 안돼
// D가 나왔다고 무작정 지우면 안돼

void getCal(string cmd, deque<int> dq)
{
    bool isReverse = false, isError = false;

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i] == 'R')
        {
            isReverse = !isReverse;
        }
        else if (cmd[i] == 'D')
        {
            if (dq.empty())
            {
                isError = true;
                break;
            }
            if (isReverse) //숫자가 뒤집힌거니까 뒤를 삭제
                dq.pop_back();
            else
                dq.pop_front();
        }
    }

    if (isError)
    {
        cout << "error\n";
    }
    else if (dq.empty())
    {
        cout << "[]\n";
    }
    else if (isReverse)
    {
        cout << "[";
        while (dq.size() > 1)
        { // empty()로 하면 출력 이상함...
            cout << dq.back() << ",";
            dq.pop_back();
        }
        cout << dq.back() << "]\n";
    }
    else if (!isReverse)
    {
        cout << "[";
        while (dq.size() > 1)
        {
            cout << dq.front() << ",";
            dq.pop_front();
        }
        cout << dq.front() << "]\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string cmd;
        cin >> cmd;

        int size;
        cin >> size;
        deque<int> dq;

        string nums;
        cin >> nums;
        string temp;
        for (int j = 0; j < nums.size(); j++)
        {
            if (isdigit(nums[j]))
                temp += nums[j];
            else
            {
                if (temp != "")
                {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        getCal(cmd, dq);
    }

    return 0;
}
