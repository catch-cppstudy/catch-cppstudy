#include <iostream>
using namespace std;

// dp?

const int MAXSIZE = 41;
long long fibDp[MAXSIZE] = {
    0,
    1,
};
void init()
{
    for (int i = 2; i < MAXSIZE; i++)
        fibDp[i] = fibDp[i - 1] + fibDp[i - 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
            cout << "1 0\n";
        else if (num == 1)
            cout << "0 1\n";
        else
        {
            cout << fibDp[num - 1] << " " << fibDp[num] << "\n";
        }
    }

    return 0;
}
