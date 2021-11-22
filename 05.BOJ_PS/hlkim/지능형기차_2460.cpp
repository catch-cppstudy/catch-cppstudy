#include <stdio.h>
using namespace std;

int main(){
  int mx = 0;
  int people = 0;
  for(int i = 0; i < 10; i++) {
    int down, up;
    scanf("%d%d", &down, &up);
    people -= down;
    people += up;
    if(people > mx)
      mx = people;
  }

  printf("%d\n", mx);
  return 0;
}
