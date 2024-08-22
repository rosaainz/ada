#include <stdio.h>
#include <limits.h>

#define V 100  // Número máximo de vértices

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int primMST(int graph[V][V], int n) {
    int parent[V]; // Array para almacenar el MST construido
    int key[V];    // Valores usados para elegir el peso mínimo
    int mstSet[V]; // Para representar el conjunto de vértices incluidos en el MST

    // Inicializar todos los valores como INFINITO
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // Empezar desde el primer vértice
    key[0] = 0;
    parent[0] = -1; // El primer nodo es siempre la raíz del MST

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);

        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    int totalCost = 0;
    for (int i = 1; i < n; i++)
        totalCost += graph[i][parent[i]];

    return totalCost;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[V][V] = {0};  // Inicializar la matriz de adyacencia

    for (int i = 0; i < n; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        u--; v--;  // Ajustar para índices de 0 a n-1
        graph[u][v] = peso;
        graph[v][u] = peso;
    }

    int totalCost = primMST(graph, n);
    printf("%s",graph);
    printf("%d\n", totalCost);

    return 0;
}

