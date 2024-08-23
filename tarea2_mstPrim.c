#include<stdio.h>
#include<limits.h>

void prim(int m, int matrizAdy[m][m]){
  int mst[m]; //arbol generador de costo minimo
  int pesoMinimo[m];
  int vertices[m];

  for(int i=0; i<m; i++){
    pesoMinimo[i] = INT_MAX;
    vertices[i] = 0;
  }

  pesoMinimo[0] = 0; //inciar desde el vertice 0
  mst[0] = -1; //primer nodo es la raiz del mst

}

int main(){
  int m;
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
    u--;
    v--;
    matrizAdy[u][v] = peso; //peso de u -> v
    matrizAdy[v][u] = peso; //peso de v -> u
  }

  prim(m, matrizAdy);
  //imprimir matriz
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      printf("%d ", matrizAdy[i][j]);
    }
    printf("\n");
  }

  return 0;
}
