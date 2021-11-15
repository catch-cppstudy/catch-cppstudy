#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<bool> nums(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        nums[i] = 1;
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            if (nums[i * j] == 1)
            {
                nums[i * j] = 0;
                cnt++;
            }
            if (cnt == k)
            {
                cout << i * j << " ";
                return 0;
            }
        }
    }
    return 0;
}