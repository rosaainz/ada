#include<stdio.h>
#include<limits.h>

void prim(int m, int matrizAdy[m][m]){
  if(m <= 1){
    printf("0\n");
    return;
  }

  int mst[m]; //arbol generador de costo minimo
  int pesoMinimo[m]; //peso minimo para cada vertice
  int vertices[m]; //conjunto de vertices incluidos en el mst

  // inicializar arrays
  for(int i=0; i<m; i++){
    pesoMinimo[i] = INT_MAX;
    vertices[i] = 0;
  }

  pesoMinimo[0] = 0; //iniciar desde el vertice 0
  mst[0] = -1; //primer nodo es la raiz del mst

  for(int cuenta=0; cuenta < m; cuenta++){
    int min= INT_MAX, indice_min;

    // encontrar el vertice con el menor peso que no esta en el mst
    for(int v = 0; v < m; v++){
      if(vertices[v] == 0 && pesoMinimo[v] < min){
        min = pesoMinimo[v];
        indice_min = v;
      }
    }

    // verificar si se encontro un vertice valido
    int u = indice_min;
    vertices[u] = 1; // incluir el vertice en el mst

    // actualizar el peso y el padre de los vertices adyacentes
    for(int v = 0; v < m; v++){
      if(matrizAdy[u][v] && vertices[v] == 0 && matrizAdy[u][v] < pesoMinimo[v]){
        mst[v] = u;
        pesoMinimo[v] = matrizAdy[u][v];
      }
    }
  }

  // calcular el costo total del mst
  int pesoMinimoTotal=0;
  for(int i=1; i < m; i++){
    pesoMinimoTotal += matrizAdy[i][mst[i]];
  }
  printf("%d\n", pesoMinimoTotal);
}

int main(){
  int m;
  scanf("%d",&m);

  if(m==1){
    int u, v, peso;
    scanf("%d %d %d", &u, &v, &peso);
    printf("%d\n", peso);
    return 0;
  }

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
  // for(int i=0; i<m; i++){
  //  for(int j=0; j<m; j++){
  //    printf("%d ", matrizAdy[i][j]);
  //  }
  //  printf("\n");
  // }

  return 0;
}
