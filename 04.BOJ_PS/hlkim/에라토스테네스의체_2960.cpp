#include <stdio.h>
using namespace std;

bool check[1001];
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  int cnt = 0;
  for (int i = 2; i <= n; i++)
  {
    if (check[i] == false)
    {
      for (int j = i; j <= n; j += i)
      {
        if (check[j] == false)
        {
          cnt = cnt + 1;
          check[j] = true;
        }
        if (cnt == k)
        {
          printf("%d\n", j);
          return 0;
        }
      }
    }
  }
  return 0;
}