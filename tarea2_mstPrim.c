#include<stdio.h>

int main(){
  int m, costo_total;
  scanf("%d",&m);

  int matrizAdy[m][m];
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      matrizAdy[i][j] = 0;
    }
  }

  //llenar matriz
  for(int i = 0; i<m; i++ ){
    int u,v,peso;
    scanf("%d %d %d", &u, &v, &peso);
    matrizAdy[u][v] = peso; //peso de u -> v
    matrizAdy[v][u] = peso; //peso de v -> u
  }

  //imprimir matriz
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      printf("%d ", matrizAdy[i][j]);
    }
    printf("\n");
  }

  return 0;
}
