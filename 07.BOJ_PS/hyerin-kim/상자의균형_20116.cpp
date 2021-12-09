#include <stdio.h>

using namespace std;

double box[200002];
int main(){
  int n, L;
  scanf("%d%d", &n, &L);
  for(int i = 0; i < n; i+=1) {
    scanf("%lf", &box[i]);
  }
  
  int cnt = 1;
  double sum = 0;
  for(int i = n-1; i >= 1; i-=1) {
    sum += box[i];
    double centor = sum / (n-i);
    if( (centor > box[i-1]-L) && (centor < box[i-1]+L) )
      cnt+=1;
  }
  if(cnt == n) printf("stable\n");
  else printf("unstable\n");
  return 0;
}