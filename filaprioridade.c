/**
Implementa as operações de uma fila
considerando a prioridadeque existe
associada a cada elemento

Requisitos: Tamanho fixo
Respeitar: Ordem
Estrutura base: Vetor Não Ordenado
*/
#include "stdio.h"
#include "stdlib.h"
#include "filaprioridade.h"
#include "vetordinamico.h"

typedef struct dadosFP{
  int tamanho;
  TVDinamico *vd;
}TDadosFP;

TFilaPrioridade *criarFP(int tam){

  TDadosFP *d = malloc(sizeof(TDadosFP));

  d->tamanho = tam;
  d->vd = criarVD();

  TFilaPrioridade *fp = malloc(sizeof(TFilaPrioridade));

  fp->dados = d;

  return fp;
}

int inserirFP(TFilaPrioridade *fp, void *carga){
  TDadosFP *d = fp->dados;
  int status = 0; /* fila cheia Não vai inserir*/
  int ocupacao = ocuparVD(d->vd);
  if(ocupacao < d->tamanho){
    status = 1; // inseriu na fila
    inserirVD(d->vd,carga,ocupacao+1);
  }
  return status;
};

static int encontrarPosicaoMenorFP(TFilaPrioridade *fp, TCompararFP comparar){
  TDadosFP *d = fp->dados;

  int pmenor = 1;
  void *cmenor = acessarVD(d->vd,1);
  if (cmenor == NULL)
    return -1;

  int ocupacao = ocuparVD(d->vd);
  for (int i=2;i<=ocupacao;i++){
    void *carga = acessarVD(d->vd,i);
    if ( comparar(cmenor, carga) > 0 ){
      cmenor = carga;
      pmenor = i;
    }
  }

  // printf("Posicao Menor:%d\n", pmenor);
  return pmenor;
}

void *encontrarMenorFP(TFilaPrioridade *fp, TCompararFP comparar){
  TDadosFP *d = fp->dados;

  int pmenor = encontrarPosicaoMenorFP(fp,comparar);
  if (pmenor <= 0)
    return NULL;
  else
    return acessarVD(d->vd, pmenor);
}


void *removerMenorFP(TFilaPrioridade *fp, TCompararFP comparar){
  TDadosFP *d = fp->dados;

  int pmenor = encontrarPosicaoMenorFP(fp, comparar);
  if (pmenor <=0){
    return NULL;
  }
  int ocupacao = ocuparVD(d->vd);

  trocarVD(d->vd, ocupacao, pmenor);
  void *mcarga = removerVD(d->vd,ocupacao);

  return mcarga;
}
