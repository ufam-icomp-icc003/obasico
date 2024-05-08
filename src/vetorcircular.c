/**
implementa um vetor circular tendo o vetor
dinâmico como base.
Suposição: Vetor tem tamanho fixo.
*/
#include "stdio.h"
#include "stdlib.h"
#include "vetordinamico.h"
#include "vetorcircular.h"

typedef struct dados_VC{
    TVDinamico *vd;
}TDadosVC;

TVCircular *criarVC_base(TPars_VC pars){
  TVCircular *vc = malloc(sizeof(TVCircular));
  TDadosVC *dados = malloc(sizeof(TDadosVC));

  dados->vd = criarVD(.tamanho=pars.tamanho);

  vc->dados = dados;

  return vc;

}

int inserirVC(TVCircular *vc, void *carga, int pos){
    TDadosVC *d = vc->dados;

    if (pos<=0)
      return 0;

    int tam = mensurarVD(d->vd);
    pos = pos % tam;
    inserirVD(d->vd,carga,pos);

    return 1;
}

void* removerVC(TVCircular *vc, int pos){

  TDadosVC *d = vc->dados;
  if (pos<=0)
    return NULL;

  int tam = mensurarVD(d->vd);
  pos = pos % tam;


  return removerVD(d->vd,pos);
}

int atualizarVC(TVCircular *vc, void *carga, int pos){

    TDadosVC *d = vc->dados;
    if (pos<=0)
      return 0;

    int tam = mensurarVD(d->vd);
    pos = pos % tam;

    return atualizarVD(d->vd,carga,pos);

}
