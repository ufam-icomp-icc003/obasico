#include "stdio.h"
#include "stdlib.h"
#include "listasc.h"

typedef struct elem {
  void *carga;
  struct elem *prox;
} TElemLSC;

typedef struct dados {
  TElemLSC *prim;
  TElemLSC *ult;
  int tam;
  int tamMax;
} TDadosLSC;

TListaSC *criarLSC_base(TPars_LSC pars){

  TDadosLSC *dados = malloc(sizeof(TDadosLSC));
  dados->tamMax = pars.tamMax;
  dados->prim=NULL;
  dados->ult=NULL;
  dados->tam=0;

  TListaSC *lsc = malloc(sizeof(TListaSC));
  lsc->dados = dados;

  return lsc;
}

//inserir no final
int inserirLSC(TListaSC *lsc, void *carga){
  TDadosLSC *d = lsc->dados;


  if (d->tam == d->tamMax)
    // lista atingiu o seu limite
    return 0;

  TElemLSC *e = malloc(sizeof(TElemLSC));
  e->prox = NULL;
  e->carga = carga;

  if (d->prim == NULL){
    d->prim = e;
    d->ult = e;
  }else{
    d->ult->prox = e;
    d->ult = e;
  }
  d->tam++;
  // inserior elemento
  return 1;
}

// remover do inicio
void *removerLSC(TListaSC *lsc){
  TDadosLSC *d = lsc->dados;

  void *carga = NULL;

  if (d->prim !=NULL){
    TElemLSC *e = d->prim;
    carga = e->carga;
    d->prim = e->prox;
    free(e);
    if (d->prim == NULL){ // removeu ultimo
      d->ult = NULL;
    }
    d->tam--;
  }

  return carga;
}

int mensurarLSC(TListaSC *lsc){
  TDadosLSC *d = lsc->dados;
  return d->tam;
}

//inserir inicio
void inserirInicioLSC(TListaSC *lsc, void *carga){
  TDadosLSC *d = lsc->dados;

  TElemLSC *e = malloc(sizeof(TElemLSC));
  e->prox = NULL;
  e->carga = carga;

  if (d->prim == NULL){
    d->prim = e;
    d->ult = e;
  }else{
    e->prox = d->prim;
    d->prim = e;
  }

  d->tam++;
}

void *removerFinalLSC(TListaSC *lsc){
  TDadosLSC *d = lsc->dados;

  void *carga = NULL;
  if (d->prim==NULL){
    return carga;
  }else if(d->prim == d->ult){
    carga = d->prim->carga;
    free(d->prim);
    d->prim=NULL;
    d->ult=NULL;
    d->tam--;
  }else{
    TElemLSC *cam = d->prim;
    while (cam->prox != d->ult){
        cam = cam->prox;
    }
    cam->prox = NULL;
    carga = d->ult->carga;
    free(d->ult);
    d->ult=cam;
    d->tam--;
  }
  return carga;
}

// acessar um elemento da lista
void *acessarLSC(TListaSC *lsc, int pos){
  TDadosLSC *d = lsc->dados;

  void *carga = NULL;
  if ( (pos<1) && (pos > d->tam) ){
    return carga;
  }else{
    TElemLSC *cam = d->prim;
    for (int i=1;i<pos;i++,cam=cam->prox){
      //cam=cam->prox;
      //printf("%d %d\n", i, pos);
    }
    carga = cam->carga;
  }
  return carga;
}
