#include<stdio.h>
#include<limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

void imprimirMatrizAd(int grafo[MAX_VERTICES][MAX_VERTICES], int m){
  for(int i=0; i < m; i++){
    for(int j=0; j < m; j++){
      if(grafo[i][j] == INF){
        printf("INF ");
      }else{
        printf("%d ", grafo[i][j]);
      }
    }
    printf("\n");
  }
}

int main(){
  int n; // número de vertices de la grafica
  int m; // número tuplas
  int k; // consultas (origen, destino)

  scanf("%d %d %d", &n, &m, &k);

  int grafo[MAX_VERTICES][MAX_VERTICES];
  int D[MAX_VERTICES][MAX_VERTICES];
  int C[MAX_VERTICES][MAX_VERTICES];

  for(int i=0; i < MAX_VERTICES; i++){
    for(int j=0; j < MAX_VERTICES; j++){
      grafo[i][j] = (i == j) ? 0 : INF;
    }
  }

  //llenar matriz de adyacencia
  for(int i=0; i < m; i++){
    int u, v, peso;
    scanf("%d %d %d", &u, &v, &peso);
    grafo[u][v] = peso;
    grafo[v][u] = peso;
  }

  //k consultas
  for(int i=0; i < k; i++){
    int o, d; //origen y destino
    scanf("%d %d", &o, &d);
  }



  imprimirMatrizAd(grafo, m);






}
