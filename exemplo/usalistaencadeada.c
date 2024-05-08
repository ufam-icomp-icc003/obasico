#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "tad/listase.h"
#include "aviao.h"

int main(int argc, char const *argv[]) {

  TListaSE *lse = criarLSE(.tamMax=6);

  inserirInicioLSE(lse, criarInstanciaAviao(4,0.5,5));
  inserirInicioLSE(lse, criarInstanciaAviao(4,0.3,2));
  inserirInicioLSE(lse, criarInstanciaAviao(8,0.1,3));
  inserirInicioLSE(lse, criarInstanciaAviao(6,0.9,1));

  TAviao *a = acessarLSE(lse,1);
  imprimirTipoAviao(a);
  a = acessarLSE(lse,mensurarLSE(lse));
  imprimirTipoAviao(a);
  a = removerFinalLSE(lse);
  imprimirTipoAviao(a);
  a = removerInicioLSE(lse);
  imprimirTipoAviao(a);

  inserirInicioLSE(lse, criarInstanciaAviao(4,0.5,5));
  inserirInicioLSE(lse, criarInstanciaAviao(4,0.3,2));
  inserirInicioLSE(lse, criarInstanciaAviao(8,0.1,3));
  inserirInicioLSE(lse, criarInstanciaAviao(6,0.9,1));
  a = acessarLSE(lse,mensurarLSE(lse));
  imprimirTipoAviao(a);
  inserirInicioLSE(lse, criarInstanciaAviao(8,0.1,3));
  a = acessarLSE(lse,mensurarLSE(lse));
  imprimirTipoAviao(a);


  return 0;
}
