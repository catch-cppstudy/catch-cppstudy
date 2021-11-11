#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 1000000;

    if (s.size() == 1)
        return 1;

    for (int i = 1; i < s.size(); i++)
    {
        int cnt = 1, result = 0;
        string before = "", current = "";

        for (int j = 0; j < s.size(); j += i)
        {
            current = s.substr(j, i);

            if (before == current)
                cnt++;
            else
            {
                if (cnt == 1)
                    result += current.size();
                else
                    result += (to_string(cnt).size() + current.size()); // to_string(cnt)는 안돼
                cnt = 1;
            }
            before = current;
        }
        if (cnt != 1)
            result += to_string(cnt).size();

        answer = min(answer, result);
    }
    return answer;
}