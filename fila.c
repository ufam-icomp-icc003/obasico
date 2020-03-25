#include "stdio.h"
#include "stdlib.h"
#include "vetordinamico.h"
#include "fila.h"

#define VAZIO_FILA 1
#define NAO_VAZIO_FILA 2

typedef struct dadosFila{
  int tamanho; // tamanho == 0 => vazia
  int status; // vazia ou nao?
  int ultima;
  int primeira;
  TVDinamico *vd; // instancia do Vetor dinamico
} TDadosFila;

TFila *criar_fila(){

    TDadosFila *d = malloc(sizeof(TDadosFila));
    d->tamanho = 0;
    d->status = VAZIO_FILA; // vazio

    d->ultima = 0; // ocupada
    d->primeira = 1; //  ocupada

    d->vd = criarVD();

    TFila *f = malloc(sizeof(TFila));
    f->dados = d;

    return f; // retorno da instancia
}

void enfileirar(TFila *f, void *elem){
    TDadosFila *d = f->dados;

    // ultima posicao ocupada
    // primeira posicao ocupada

    d->ultima++;
    d->tamanho++;
    d->status = NAO_VAZIO_FILA;
    inserir(d->vd,elem,d->ultima);
}

void *desenfileirar(TFila *f){
    void *elem = NULL;
    TDadosFila *d = f->dados;

    if (d->status == NAO_VAZIO_FILA){ // nao vazio
      elem = remover(d->vd,d->primeira);
      d->primeira++;
      d->tamanho--;

      if (d->tamanho==0){
        d->primeira=1;
        d->ultima=0;
        d->status = VAZIO_FILA;
      }
    }

    return elem;
}
