#include<stdio.h>
#include<limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX //infinito para los que sean cero

void imprimirMatrizAdy(int grafo[MAX_VERTICES][MAX_VERTICES], int m){
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
  int m;
  int s; //vertice original
  int d; //vertice destino
  int n = 0; //contador de vertices
  scanf("%d %d %d", &m, &s, &d);


  int grafo[MAX_VERTICES][MAX_VERTICES];
  for(int i=0; i < MAX_VERTICES; i++){
    for(int j=0; j < MAX_VERTICES; j++){
      grafo[i][j] = INF;
    }
  }

  for(int i=0; i < m; i++){
    int u,v,peso;
    scanf("%d %d %d", &u, &v, &peso);
    grafo[u][v] = peso;
    grafo[v][u] = peso;
    if(u > v) n = u;
    if(v > n) n = v;
  }

  int D[MAX_VERTICES]; //distancias
  int Z[MAX_VERTICES]; //predecesores

  imprimirMatrizAdy(grafo, m);

  return 0;
}
