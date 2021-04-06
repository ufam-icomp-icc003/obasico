#include "aviao.h"
struct aviao{
  int nroTurbina;
  double nivelCombustivel;
  int prioridade;
};

void *criarInstanciaAviao(int nroTurbina, double nivelCombustivel, int prioridade){

  TAviao *carga = malloc(sizeof(TAviao));
  carga->nroTurbina = nroTurbina;
  carga->nivelCombustivel = nivelCombustivel;
  carga->prioridade = prioridade;

  return carga;
}

int compararInstanciasAviao(void *elemA, void *elemB){
    TAviao *pelemA = elemA;
    TAviao *pelemB = elemB;

    return (pelemA->prioridade - pelemB->prioridade);
}

void imprimirTipoAviao(TAviao *a){
  if (a!=NULL){
    printf("Prior: %d\n", a->prioridade);
    printf("turbinas: %d\n", a->nroTurbina);
    printf("nivelCombustivel: %lf\n", a->nivelCombustivel);
  }

}
