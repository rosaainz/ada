#include<stdio.h>
#include<limits.h>

int monedas(int C, int n, int denMonedas[]){
  if(C == 0){
    return 0;
  }
  if(n <= 0){
    return INT_MAX;
  }
  if(denMonedas[n-1] > C){
    return monedas(C, n-1, denMonedas);
  }else{
    int tomarMoneda = monedas(C - denMonedas[n-1], n, denMonedas);
    int noTomarMoneda = monedas(C, n-1, denMonedas);

    if(tomarMoneda != INT_MAX){
      tomarMoneda += 1;
    }
    return (tomarMoneda < noTomarMoneda) ? tomarMoneda : noTomarMoneda;
  }
}

int main(){
  int n, C;

  scanf("%d %d", &n, &C);
  int denMonedas[n];

  for(int i=0; i<n; i++){
    scanf("%d", &denMonedas[i]);
  }

  int res = monedas(C, n, denMonedas);
  printf("%d", res);

}
