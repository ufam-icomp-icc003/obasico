/**
implementação do tipo Pilha usando VDinamico
A pilha é neutra, portanto pode receber qualquer
tipo de dado
*/
#include "stdio.h"
#include "stdlib.h"
#include "vdinamico.h"
#include "pilha.h"

typedef struct dadosPilha{

  TVDinamico *vd;

} TDadosPilha;

TPilha *criarPilha(){

  TVDinamico *vd = criarVD();

  TDadosPilha *dp = malloc(sizeof(TDadosPilha));
  dp->vd = vd;

  TPilha *pilha = malloc(sizeof(TPilha));

  pilha->dados = dp;

  return pilha;
}

void empilhar(TPilha *pilha, void *carga){
  TDadosPilha *dp = pilha->dados;
  int ocupacao = ocuparVD(dp->vd);
  inserirVD(dp->vd, carga, ocupacao+1);
}

void* desempilhar(TPilha *pilha){
  TDadosPilha *dp = pilha->dados;
  int ocupacao = ocuparVD(dp->vd);
  void *carga = NULL;
  if (ocupacao > 0){
    carga = removerVD(dp->vd, ocupacao);
  }

  return carga;
}

int mensurarPilha(TPilha *pilha){
    TDadosPilha *dp = pilha->dados;

    return ocuparVD(dp->vd);
}
