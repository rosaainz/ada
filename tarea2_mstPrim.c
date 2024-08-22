#include<stdio.h>

int main(){
  int m, costo_total;
  int matriz[m][3];

  scanf("%d",&m);

  for(int i=0; i<m; i++){
    for(int j=0; j<3; j++){
      matriz[i][j] = 0;
    }
  }

  //llenar matriz
  for(int i = 0; i<m; i++ ){
    int u,v,peso;
    scanf("%d %d %d", &u, &v, &peso);
    matriz[i][0] = u;
    matriz[i][1] = v;
    matriz[i][2] = peso;
  }

  //imprimir matriz
  for(int i=0; i<m; i++){
    for(int j=0; j<3; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
