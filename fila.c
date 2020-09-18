/**
implementa uma fila usando VDinamico
*/
#include "stdio.h"
#include "stdlib.h"
#include "vetordinamico.h"
#include "fila.h"

typedef struct dadosFila{
  TVDinamico *vd; //
  int cabeca;
  int final;
}TDadosFila;

void enfileirar(TFila *fila, void *carga){
    TDadosFila *df = fila->dados;
    df->final++;
    inserirVD(df->vd, carga, df->final);
}

void *desenfileirar(TFila *fila){
  TDadosFila *df = fila->dados;
  int ocupacao = ocuparVD(df->vd);
  void *carga = NULL;

  if (ocupacao > 0){
    carga = removerVD(df->vd,df->cabeca);
    df->cabeca++;
    if (df->cabeca > df->final){
      df->cabeca=1;
      df->final=0;
    }
  }

  return carga;
}

int mensurarFila(TFila *fila){
  TDadosFila *df = fila->dados;
  int ocupacao = ocuparVD(df->vd);

  return ocupacao;
}

TFila *criarFila(){
    TDadosFila *df = malloc(sizeof(TDadosFila));

    df->vd = criarVD();
    df->cabeca = 1;
    df->final = 0;

    TFila *fila = malloc(sizeof(TFila));

    fila->dados = df;

    return fila;
}
