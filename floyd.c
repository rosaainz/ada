#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

void floyd(int grafo[MAX_VERTICES][MAX_VERTICES], int n, int D[MAX_VERTICES][MAX_VERTICES], int C[MAX_VERTICES][MAX_VERTICES]) {
    int i, j, k;

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        D[i][j] = grafo[i][j];
        if (D[i][j] == INF) {
          C[i][j] = -1;
        } else if (i != j) {
          C[i][j] = i;
        } else {
          C[i][j] = -1;
        }
      }
    }

    for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] < D[i][j]) {
            D[i][j] = D[i][k] + D[k][j];
            C[i][j] = C[k][j];
          }
        }
      }
    }
}

void getS(int C[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    if (u == v) {
        printf("%d ", u);
    } else if (C[u][v] == -1) {
        printf("e ");
    } else {
        getS(C, u, C[u][v]);
        printf("%d ", v);
    }
}

int main() {
    int n, m, k; //num vertices, m tuplas, k consultas
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int D[MAX_VERTICES][MAX_VERTICES];
    int C[MAX_VERTICES][MAX_VERTICES];

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grafo[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        grafo[u][v] = peso;
        grafo[v][u] = peso;
    }

    floyd(grafo, n, D, C);

    // k consultas
    for (int i = 0; i < k; i++) {
        int o, d;
        scanf("%d %d", &o, &d);

        // Imprimir la distancia más corta
        if (D[o][d] == INF) {
            printf("INF, e\n");
        } else {
            printf("%d, ", D[o][d]);
            // Imprimir el camino más corto
            getS(C, o, d);
            printf("\n");
        }
    }

    return 0;
}
