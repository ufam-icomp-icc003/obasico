#include "stdlib.h"
#include "vetordinamico.h"
#include "pilha.h"

typedef struct dadosPilha{
    int altura;
    TVDinamico *vd;
}TDadosPilha;

TPilha *criar_pilha(){
    TDadosPilha *d = malloc(sizeof(TDadosPilha));
    d->altura = 0;
    d->vd = criarVD();

    TPilha *p = malloc(sizeof(TPilha));
    p->dados = d;

    return p;
}

void empilhar(TPilha *pilha, void *elem){
  TDadosPilha *d = pilha->dados;
  d->altura++;
  inserir(d->vd, elem, d->altura);
}

void *desempilhar(TPilha *pilha){

  void *elem = NULL;
  TDadosPilha *d = pilha->dados;
  if(d->altura>0){
    elem = remover(d->vd, d->altura);
    d->altura--;
  }
  return elem;
}

//*acessar elemento do topo da pilha sem removê-lo
void *topo_pilha(TPilha *pilha){
  void *elem = NULL;
  // falta completar o código

  return elem;
}

//* verifica se a pilha é vazia ou não
short vazia_pilha(TPilha *pilha){
  TDadosPilha *d = pilha->dados;

  return (d->altura==0);
}
