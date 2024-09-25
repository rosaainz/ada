#include<stdio.h>
#include<stdlib.h>

void leer_archivo(const char *entrada){
  FILE *archivo = fopen(entrada, "r");
  if( archivo == NULL ){
    printf("archivo null");
    return;
  }

  char linea[256];
  while( fgets(linea, sizeof(linea), archivo) ){
    printf("%s", linea);
  }
  fclose(archivo);
}


int main(int argc, char *argv[]){

  if( argc < 2 ){
    printf("Sin archivo");
    return 1;
  }

  const char *entrada = argv[1];
  leer_archivo(entrada);

  return 0;
}
