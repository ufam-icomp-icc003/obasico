#include "stdlib.h"
#include "inteiro.h"

void *criarInstanciaInt(int valor){

  int *carga = malloc(sizeof(int));
  *carga = valor;

  return carga;
}

int compararInstanciasInt(void *elemA, void *elemB){
    int *pelemA = elemA;
    int *pelemB = elemB;
    return (*pelemA - *pelemB);
}
