#include<stdio.h>
#include<stdlib.h>

int mochila(int n, int W, int v[], int w[], int *total_objetos, int *total_peso){
  if(W==0 || n==0){
    return 0;
  }

  if(w[n-1] > W){
    return mochila(n-1, W, v, w, total_objetos, total_peso);
  }else{
    int excluir_objetos = *total_objetos;
    int excluir_peso = *total_peso;
    int excluir = mochila(n-1, W, v, w, &excluir_objetos, &excluir_peso);

    int incluir_objetos = *total_objetos;
    int incluir_peso = *total_peso;
    int incluir = v[n-1] + mochila(n-1, W - w[n-1], v, w, &incluir_objetos, &incluir_peso);

    if(incluir > excluir){
      *total_objetos = incluir_objetos + 1;
      *total_peso = incluir_peso + w[n-1];
      return incluir;
    }else{
      *total_objetos = excluir_objetos;
      *total_peso = excluir_peso;
      return excluir;
    }
  }
}


int main(){
  int n; //numero de objetos
  int W; //tamaño de la mochila

  scanf("%d %d", &n, &W);

  int *v = (int *)malloc(n * sizeof(int));
  int *w = (int *)malloc(n * sizeof(int));


  for(int i=0; i<n; i++){
    scanf("%d %d", &v[i], &w[i]);
  }


  int total_objetos = 0;
  int total_peso = 0;
  int total_beneficio = mochila(n, W, v, w, &total_objetos, &total_peso);

  printf("\n%d %d %d", total_beneficio, total_objetos, total_peso);

  free(v);
  free(w);
  return 0;
}
