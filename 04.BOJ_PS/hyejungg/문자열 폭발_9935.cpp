//시간초과....
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, boom;
    cin >> str;
    cin >> boom;

    while (1) {
        if (str.find(boom) != string::npos) {
            int idx = str.find(boom);
            str.erase(idx, boom.size());
        }
        else
            break;
    }

    if (str.empty())
        str = "FRULA";

    cout << str;

    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, boom;
    cin >> str;
    cin >> boom;

    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        ans += str[i]; //한글자씩 넣어

        while (1)
        {
            if (ans.size() < boom.size()) // boom보다 작으면 비교할 것도 x
                break;

            // ans의 뒤에서 폭발문 크기만큼만 substr 한 값이 폭발문이랑 같다면
            if (ans.substr(ans.size() - boom.size(), boom.size()) == boom)
                for (int j = 0; j < boom.size(); j++)
                    ans.pop_back();
            else
                break;
        }
    }

    if (ans.empty())
        ans = "FRULA";

    cout << ans;

    return 0;
}
