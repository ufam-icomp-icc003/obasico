#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "tad/filaprioridade.h"
#include "aviao.h"

int main(int argc, char const *argv[]) {

  TFilaPrioridade *fp = criarFP(4);

  inserirFP(fp, criarInstanciaAviao(4,0.5,5));
  inserirFP(fp, criarInstanciaAviao(4,0.3,2));
  inserirFP(fp, criarInstanciaAviao(8,0.1,3));
  inserirFP(fp, criarInstanciaAviao(6,0.9,1));

  TAviao *pmenor = encontrarMenorFP(fp, compararInstanciasAviao);
  imprimirTipoAviao(pmenor);

  pmenor = removerMenorFP(fp, compararInstanciasAviao);
  imprimirTipoAviao(pmenor);

  pmenor = encontrarMenorFP(fp, compararInstanciasAviao);
  imprimirTipoAviao(pmenor);

  return 0;
}
