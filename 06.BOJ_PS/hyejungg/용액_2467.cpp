#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num); //오름차순으로 들어감
    }

    int left = 0, right = n - 1;
    int a = v[left];
    int b = v[right];
    int value = abs(a + b); //초기값

    while (left < right)
    {
        int temp = v[left] + v[right];
        if (abs(temp) < value)
        {
            a = v[left];
            b = v[right];
            value = abs(temp); //복사
        }

        temp < 0 ? left++ : right--;
    }

    cout << a << " " << b << " ";

    return 0;
}
