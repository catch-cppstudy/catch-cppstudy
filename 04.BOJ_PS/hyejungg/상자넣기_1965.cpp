#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int ans = 0;
    int n;
    cin >> n;

    vector<int> boxs;
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        boxs.push_back(num);

        int dpMax = 0;
        for (int j = 0; j < boxs.size(); j++)
        {
            if (boxs[i] > boxs[j])
                if (dpMax < dp[j])
                    dpMax = dp[j];
        }
        dp[i] = dpMax + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}