#include<stdio.h>
#include<stdlib.h>

int main(){
  int n; //numero de objetos
  int W; //tamaño de la mochila

  scanf("%d %d", &n, &W);

  int *v = (int *)malloc(n * sizeof(int));
  int *w = (int *)malloc(n * sizeof(int));


  for(int i=0; i<n; i++){
    int v_; //veneficio del objeto
    int w_; //peso del objeto
    scanf("%d %d", &v_, &w_);
    v[i] = v_;
    w[i] = w_;
  }

  printf("arreglo v:\n");
  for(int i=0; i<n; i++){
    printf("%d ", v[i]);
  }

  printf("\narreglo w:\n");
  for(int i=0; i<n; i++){
    printf("%d ", w[i]);
  }
  return 0;
}
