#include "stdio.h"
#include "stdlib.h"
#include "listase.h"

typedef struct elem {
  void *carga;
  struct elem *prox;
} TElemLSE;

typedef struct dados {
  TElemLSE *prim;
  TElemLSE *ult;
  int tam;
  int tamMax;
} TDadosLSE;

TListaSE *criarLSE_base(TPars_LSE pars){

  TDadosLSE *dados = malloc(sizeof(TDadosLSE));
  dados->tamMax = pars.tamMax;
  dados->prim=NULL;
  dados->ult=NULL;
  dados->tam=0;

  TListaSE *lse = malloc(sizeof(TListaSE));
  lse->dados = dados;

  return lse;
}

//inserir no final
int inserirFinalLSE(TListaSE *lse, void *carga){
  TDadosLSE *d = lse->dados;


  if (d->tam == d->tamMax)
    // lista atingiu o seu limite
    return 0;

  TElemLSE *e = malloc(sizeof(TElemLSE));
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
void *removerInicioLSE(TListaSE *lse){
  TDadosLSE *d = lse->dados;

  void *carga = NULL;

  if (d->prim !=NULL){
    TElemLSE *e = d->prim;
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

int mensurarLSE(TListaSE *lse){
  TDadosLSE *d = lse->dados;
  return d->tam;
}

//inserir inicio
int inserirInicioLSE(TListaSE *lse, void *carga){
  TDadosLSE *d = lse->dados;

  if (d->tam == d->tamMax)
    return 0;

  TElemLSE *e = malloc(sizeof(TElemLSE));
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

  return 1;
}

void *removerFinalLSE(TListaSE *lse){
  TDadosLSE *d = lse->dados;

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
    TElemLSE *cam = d->prim;
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
void *acessarLSE(TListaSE *lse, int pos){
  TDadosLSE *d = lse->dados;

  void *carga = NULL;
  if ( (pos<1) && (pos > d->tam) ){
    return carga;
  }else{
    TElemLSE *cam = d->prim;
    for (int i=1;i<pos;i++,cam=cam->prox){
      //cam=cam->prox;
      //printf("%d %d\n", i, pos);
    }
    carga = cam->carga;
  }
  return carga;
}
