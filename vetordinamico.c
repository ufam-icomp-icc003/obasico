/**
Implementacao do conceito de vetor dinâmico.
*/
#include "stdlib.h"
#include "vetordinamico.h"

struct dados{
  int tam;
  int ocupacao;
  void* *vetor;
};

TVDinamico* criarVD(){

  struct dados *d = malloc(sizeof(struct dados));
  d->tam = 1;
  d->ocupacao = 0;
  d->vetor = malloc(sizeof(void*)*d->tam);

  TVDinamico *vd = malloc(sizeof(TVDinamico));
  vd->dados = d;

  return vd;
};

void inserir(TVDinamico *vd, void *dado, int pos){

  struct dados *d = vd->dados;

  d->ocupacao++;
  if (pos > d->tam){
    d->vetor = realloc(d->vetor, sizeof(void*)*(pos) );
  }

  d->vetor[pos-1] = dado;


};






void remover(){};

void ordenar(){};
