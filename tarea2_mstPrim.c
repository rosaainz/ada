#include <stdio.h>
#include <limits.h>

void prim(int V, int matrizAdy[V][V]) {
    if (V <= 1) {
        printf("0\n");
        return;
    }

    int mst[V]; //arbol generador de costo minimo
    int pesoMinimo[V]; //peso minimo para cada vertice
    int vertices[V]; //conjunto de vertices incluidos en el mst

    // inicializar arrays
    for (int i = 0; i < V; i++) {
        pesoMinimo[i] = INT_MAX;
        vertices[i] = 0;
    }

    pesoMinimo[0] = 0; //iniciar desde el vertice 0
    mst[0] = -1; //primer nodo es la raiz del mst

    for (int cuenta = 0; cuenta < V - 1; cuenta++) {
        int min = INT_MAX, indice_min = -1;

        // encontrar el vertice con el menor peso que no esta en el mst
        for (int v = 0; v < V; v++) {
            if (vertices[v] == 0 && pesoMinimo[v] < min) {
                min = pesoMinimo[v];
                indice_min = v;
            }
        }

        // verificar si se encontro un vertice valido
        if (indice_min == -1) {
            break;
        }

        int u = indice_min;
        vertices[u] = 1;

        // actualizar el peso y el padre de los vertices adyacentes
        for (int v = 0; v < V; v++) {
            if (matrizAdy[u][v] && vertices[v] == 0 && matrizAdy[u][v] < pesoMinimo[v]) {
                mst[v] = u;
                pesoMinimo[v] = matrizAdy[u][v];
            }
        }
    }

     // calcular el costo total del mst
    int pesoMinimoTotal = 0;
    for (int i = 1; i < V; i++) {
        if (mst[i] != -1) {
            pesoMinimoTotal += matrizAdy[i][mst[i]];
        }
    }
    printf("%d\n", pesoMinimoTotal);
}

int main() {
    int m;
    scanf("%d", &m);

    if (m == 1) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        printf("%d\n", peso);
        return 0;
    }

    int u, v, peso;
    int maxV = 0; // numero maximo de vertices

    // encontrar  numero de vértices
    int edges[m][3];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &peso);
        if (u > maxV) maxV = u;
        if (v > maxV) maxV = v;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = peso;
    }

    int V = maxV; // numero de vertices
    int matrizAdy[V][V];

    // inicializar la matriz de adyacencia
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            matrizAdy[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        u = edges[i][0] - 1;
        v = edges[i][1] - 1;
        peso = edges[i][2];
        matrizAdy[u][v] = peso; // Peso de u -> v
        matrizAdy[v][u] = peso; // Peso de v -> u
    }

    prim(V, matrizAdy);

    return 0;
}

