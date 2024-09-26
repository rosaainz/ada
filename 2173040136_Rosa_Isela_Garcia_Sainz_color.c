#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

//lista de adyacencia
typedef struct Nodo{
  int vertice;
  struct Nodo* siguiente;
} Nodo;

//grafo
typedef struct Grafo{
  Nodo* listas[MAX_VERTICES];
  int numVertices;
} Grafo;

void addArista( Grafo* grafo, int o, int dest ){
  Nodo* nuevoNodo = malloc(sizeof(Nodo));
  nuevoNodo->vertice = dest;
  nuevoNodo->siguiente = grafo->listas[o];
  grafo->listas[o] = nuevoNodo;

  nuevoNodo = malloc(sizeof(Nodo));
  nuevoNodo->vertice = o;
  nuevoNodo->siguiente = grafo->listas[dest];
  grafo->listas[dest] = nuevoNodo;
}

Grafo* crearGrafo( int vertices ){
  Grafo* grafo = malloc(sizeof(Grafo));
  grafo->numVertices = vertices;
 for( int i=0; i < vertices; i++ ){
   grafo->listas[i] = NULL;
 }
 return grafo;
}

void leer_archivo( const char *entrada, Grafo *grafo ){
  FILE *archivo = fopen(entrada, "r");
  if( archivo == NULL ){
    printf("archivo null");
    return;
  }

  int o, dest;
  while( fscanf(archivo, "%d %d", &o, &dest) == 2 ){
    addArista(grafo, o, dest);
  }
  fclose(archivo);
}


void imprimirGrafo( Grafo* grafo ){
  for( int i=0; i<grafo->numVertices; i++ ){
    Nodo* temp = grafo->listas[i];
    printf("Vertice: %d", i);
    while( temp != NULL ){
      printf(" -> %d", temp->vertice);
      temp = temp->siguiente;
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]){

  if( argc < 2 ){
    printf("Sin archivo");
    return 1;
  }

  Grafo* grafo = crearGrafo(MAX_VERTICES);

  const char *entrada = argv[1];
  leer_archivo(entrada, grafo);

  imprimirGrafo(grafo);

  //liberar memoria
  for( int i=0; i<grafo->numVertices; i++ ){
    Nodo* temp;
    while( grafo->listas[i] != NULL ){
      temp = grafo->listas[i];
      grafo->listas[i] = grafo->listas[i]->siguiente;
      free(temp);
    }
  }

  free(grafo);
  return 0;
}
