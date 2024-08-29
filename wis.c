#include<stdio.h>
#include<stdlib.h>


int main(){
  int n;
  scanf("%d", &n);

  int *pesos_vertices = (int *)malloc(n * sizeof(int));
  for(int i=0; i<n; i++){
    scanf("%d", &pesos_vertices[i]);
  }

  for(int i=0; i<n; i++){
    printf("%d", pesos_vertices[i]);
  }

  free(pesos_vertices);

  return 0;
}
