#include "stdio.h"
#include "vetordinamico.h"

int main(int argc, char const *argv[]) {

  TVDinamico *meuVD = criarVD();

  void *carga = NULL;

  inserir(meuVD, carga, 1);

  


  return 0;
}
