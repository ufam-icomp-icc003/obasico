/**
Implementacao do conceito de vetor dinâmico.
*/
#include "stdlib.h"
#include "math.h"
#include "vetordinamico.h"

typedef struct dados{
  int tam;
  int ocupacao;
  void* *vetor;
} TDadosVD;

TVDinamico* criarVD(){

  TDadosVD *d = malloc(sizeof(TDadosVD));
  d->tam = 1;
  d->ocupacao = 0;
  d->vetor = malloc(sizeof(void*)*d->tam);
  //memset()

  TVDinamico *vd = malloc(sizeof(TVDinamico));
  vd->dados = d;

  return vd;
};

void inserir(TVDinamico *vd, void *dado, int pos){

  TDadosVD *d = vd->dados;

  if (pos > d->tam){
    d->tam = pow(2,ceil(log2(pos)));
    d->vetor = realloc(d->vetor, sizeof(void*)*(d->tam) );
    //memset()
  }
  if (d->vetor[pos-1]==NULL)
    d->ocupacao++;

  d->vetor[pos-1] = dado;

};

void *remover(TVDinamico *vd, int pos){
  TDadosVD *d = vd->dados;

  void *carga = NULL;
  // verifica validade da posição
  if (abs(pos) <= d->tam){ //[-tam,tam]
   //  1, 2, 3, 4, 5 <== acesso pos
   // [0, 1, 2, 3, 4]
   // -5,-4,-3,-2,-1 <== acesso -pos
      pos = (pos<0?d->tam+(pos+1):pos);
      carga = d->vetor[pos-1];

      if (carga != NULL){
        d->vetor[pos-1] = NULL;
        d->ocupacao--;
      }
  }
  return carga;
};

void *acessar(TVDinamico *vd, int pos){
  TDadosVD *d = vd->dados;

  void *carga = NULL;
  // verifica validade da posição
  if (abs(pos) <= d->tam) && (abs(pos)>0){ //[-tam,tam]
      pos = (pos<0?d->tam+(pos+1):pos);
      carga = d->vetor[pos-1];
  }
  return carga;
};

void *deslocar(TVDinamico *vd, int passo){ //shift
  // deslocar fisico

  // [x3,x2,x1,NULL,NULL] n*k, k>>n: letreiro

  // [x4,x3,x2,x1,NULL]

}

static void trocar(void* vetor[], int i, int j){
    void *temp = NULL;
    temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

void ordenar(TVDinamico *vd, TCompararVDinamico comparar){
  TDadosVD *d = vd->dados;
  for (int i = 0; i < d->tam-1; i++) {
    int imaior = 0;
    for(int j=1;j<d->tam-i;j++){
      if(comparar(d->vetor[imaior],d->vetor[j]) < 0){
        imaior = j;
      }
    }
    trocar(d->vetor, imaior,d->tam-i-1);
  }

};
