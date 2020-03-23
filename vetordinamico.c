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

  TVDinamico *vd = malloc(sizeof(TVDinamico));
  vd->dados = d;

  return vd;
};

void inserir(TVDinamico *vd, void *dado, int pos){

  TDadosVD *d = vd->dados;

  d->ocupacao++;
  if (pos > d->tam){
    d->tam = pow(2,ceil(log(pos)));
    d->vetor = realloc(d->vetor, sizeof(void*)*(d->tam) );
  }
  d->vetor[pos-1] = dado;

};

void *remover(TVDinamico *vd, int pos){
  TDadosVD *d = vd->dados;

  void *carga = NULL;
  // verifica validade da posição
  if (abs(pos) <= d->tam){

   //  1, 2, 3, 4, 5 <== acesso pos
   // [0, 1, 2, 3, 4]
   // -5,-4,-3,-2,-1 <== acesso -pos
      pos = (pos<0?d->tam+(pos+1):pos);

      carga = d->vetor[pos-1];
      d->vetor[pos-1] = NULL;
  }
  return carga;
};

// static void trocar(void* vetor[], int i, int j){
//     void *temp = NULL;
//     temp = vetor[i];
//     vetor[i] = vetor[j];
//     vetor[j] = temp;
// }
//
// typedef  int (* TCompararVDinamico)(void*,void*);
// void ordenar(TVDinamico *vd, TCompararVDinamico comparar){
//   TDadosVD *d = vd->dados;
//   for (int i = 0; i < d->tam-1; i++) {
//     int imaior = 0;
//     for(int j=1;j<d->tam-i;j++){
//       if(comparar(d->vetor[imaior],d->vetor[j]) < 0){
//         imaior = j;
//       }
//     }
//     trocar(d->vetor, imaior,d->tam-i-1);
//   }
//
// };
