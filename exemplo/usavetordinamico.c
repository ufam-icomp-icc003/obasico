#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "tad/vetordinamico.h"
#include "inteiro.h"

int main(int argc, char const *argv[]) {
  TVDinamico *vd = criarVD();


  inserirVD(vd, criarInstanciaInt(10), 1);
  inserirVD(vd, criarInstanciaInt(100), 2);
  inserirVD(vd, criarInstanciaInt(1), 3);
  inserirVD(vd, criarInstanciaInt(20), 4);
  inserirVD(vd, criarInstanciaInt(24), 5);

  int* valor = acessarVD(vd, 1);

  printf("%d\n", *valor );

  valor = acessarVD(vd, 5);

  printf("%d\n", *valor );

  ordenarVD(vd, compararInstanciasInt);

  valor = acessarVD(vd, 1);

  printf("%d\n", *valor );

  valor = acessarVD(vd, 5);

  printf("%d\n", *valor );

  // valor = removerVD(vd, 10);
  // if (valor !=NULL){
  //   printf("Removido: %d\n", *valor );
  // }else{
  //   printf("Posição Vazia!\n");
  // }
  //
  // valor = removerVD(vd, 10);
  // if (valor !=NULL){
  //   printf("Removido: %d\n", *valor );
  // }else{
  //   printf("Posição Vazia!\n");
  // }

  return 0;
}
