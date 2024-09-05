#include<stdio.h>
#include<limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX //infinito para los que sean cero


int encontrarVerticeDistanciaMin(int D[], int visitado[], int n){
  int min = INF;
  int minIndex = -1;

  for(int i=0; i < n; i++){
    if(!visitado[i] && D[i] < min){
      min = D[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void dijkstra(int grafo[MAX_VERTICES][MAX_VERTICES], int origen, int n, int D[], int Z[]){
  int visitado[MAX_VERTICES];

  for(int i=0; i < n; i++){
    D[i] = INF;
    Z[i] = -1;
    visitado[i] = 0;
  }

  D[origen] = 0;

  for(int i=0; i < n-1; i++){
    int u = encontrarVerticeDistanciaMin(D, visitado, n);
    if(u == -1) break;
    //printf("%d ", u);

    //marcar el vertice encontrado como visitado
    visitado[u] = 1;

    for(int v=0; v < n; v++){
      if(!visitado[v] && grafo[u][v] != INF && D[u] != INF && D[u] + grafo[u][v] < D[v]){
        D[v] = D[u] + grafo[u][v];
        Z[v] = u;
      }
    }
  }
}

void imprimirRutaCorta(int Z[], int d){
  int ruta[MAX_VERTICES];
  int longitud = 0;

  int actual = d - 1;
  while(actual != -1){
    ruta[longitud++] = actual;
    actual = Z[actual];
  }

  printf("[");
  for(int i=longitud-1; i>=0; i--){
    printf("%d", ruta[i]+1);
    if(i > 0){
      printf(" ");
    }
  }
  printf("]\n");
}

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
    u--;
    v--;
    grafo[u][v] = peso;
    grafo[v][u] = peso;
    if(u >= v) n = u + 1;
    if(v >= n) n = v + 1;
  }
  n++;

  int D[MAX_VERTICES]; //distancias
  int Z[MAX_VERTICES]; //predecesores

  dijkstra(grafo, s-1, n, D, Z);
  //imprimirMatrizAdy(grafo, m);

  //costo total
  if(D[d-1] == INF){
  }else{
    printf("%d ", D[d-1]);
  }

  imprimirRutaCorta(Z, d);

  return 0;
}
