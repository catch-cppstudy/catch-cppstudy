#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 1000000 //수빈이가 이동 가능한 채널 횟수 (500,000까지 버튼이니까 +, - 포함해서 x2)

vector<bool> brokeChannel(10, false);

bool isPress(int idx)
{
    string str = to_string(idx);
    for (int i = 0; i < str.size(); i++)
    {
        if (brokeChannel[str[i] - '0'])
            return false;
    }
    return true;
}

//이동하려고 하는 채널부터 +/-
int pressChannel(int n)
{
    int result = INF;
    int find = 0;
    for (int i = 0; i <= MAX; i++)
    {
        if (isPress(i))
        {
            int pressCnt = abs(n - i); //+/-
            if (result > pressCnt)
            {
                result = pressCnt;
                find = i;
            }
        }
    }
    return result + to_string(find).size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n; //이동하려고 하는 채널
    cin >> m; //고장난 버튼의 개수
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        brokeChannel[num] = true; // num번째는 고장났다.
    }

    // 100에서 +/- 눌러서 이동한 횟수 vs 직접 채널 눌러서 이동한 횟수
    cout << min(abs(n - 100), pressChannel(n)) << "\n";

    return 0;
}
