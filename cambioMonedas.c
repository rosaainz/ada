#include<stdio.h>

int main(){
  int n, C;

  scanf("%d %d", &n, &C);
  int den[n];

  for(int i=0; i<n; i++){
    scanf("%d", &den[i]);
  }

  for(int i=0; i<n; i++){
    printf("%d\n",den[i]);
  }

}
