#include<stdio.h>
#include<stdlib.h>

void wis(int n, int v[]){
  int *W = (int *)malloc((n-1) * sizeof(int));
  int *solucion = (int *)malloc(n *  sizeof(int));

  W[0] = 0;
  W[1] = v[0];

  for(int i=0; i<=n; i++){
    W[i] = (v[i-1] + W[i-2] > W[i-1]) ? v[i-1] + W[i-2] : W[i-1];
  }

  int index = 0;
  for(int i=n; i >= 1; i--){
    if(i == 1 || W[i-1] < (v[i-1] + W[i-2])){
      solucion[index++] = i;
      i--;
    }
  }
  printf("%d ", W[n]);
  for(int i = index-1; i>=0; i--){
    printf("%d ", solucion[i]);
  }

}


int main(){
  int n;
  scanf("%d", &n);

  int *pesos_vertices = (int *)malloc(n * sizeof(int));
  for(int i=0; i<n; i++){
    scanf("%d", &pesos_vertices[i]);
  }

  wis(n, pesos_vertices);
  free(pesos_vertices);

  return 0;
}
