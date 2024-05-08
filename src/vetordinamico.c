/**
Implementação do vetor dinamico com crescimento
exponencial.
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"
#include "vetordinamico.h"

typedef struct dadosVD{
  int tam;
  int ocupacao;
  void* *vetor;
} TDadosVD;

TVDinamico *criarVD_base(TPars_VD pars){
  TVDinamico *vd = malloc(sizeof(TVDinamico));

  TDadosVD *d = malloc(sizeof(TDadosVD));

  d->tam = pars.tamanho;
  d->ocupacao = 0;
  d->vetor = malloc(sizeof(void*)*d->tam);

  vd->dados = d;

  return vd;
}

void* acessarVD(TVDinamico *vd, int pos){

  TDadosVD *d = vd->dados;

  void* carga = NULL;

  if ((abs(pos) <= d->tam) && (abs(pos)>0)){ //[-tam,tam]
        pos = (pos<0?d->tam+(pos+1):pos);
        carga = d->vetor[pos-1];
  }else{
    printf("acesso fora do limite\n");
  }
  return carga;
}

void inserirVD(TVDinamico *vd, void* carga, int pos){
  TDadosVD *d = vd->dados;
  if (pos > d->tam){
      d->tam = pow(2,ceil(log2(pos)));
      d->vetor = realloc(d->vetor,sizeof(void*)*(d->tam));
  }
  d->vetor[pos-1] = carga;
  d->ocupacao++;
}

/** atualiza uma posição do vetor dinâmico
sobre escrevendo o conteúdo
0 - não efetiva a operação | fora do escopo do vetor
1 - operação efetivada
*/
int atualizarVD(TVDinamico *vd, void* carga, int pos){
  TDadosVD *d = vd->dados;
  if (pos > d->tam){
    return 0; // fora do escopo do vetor
  }
  // potencial para memory-leaky (perde endereço do
  // conteúdo anterior)
  d->vetor[pos-1] = carga;
  return 1; // feito
}


void *removerVD(TVDinamico *vd, int pos){
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

static void trocar(void* vetor[], int i, int j){
    void *temp = NULL;
    temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

void trocarVD(TVDinamico *vd, int posA, int posB){

  TDadosVD *d = vd->dados;

  posA = (posA<0?d->tam+(posA+1):posA);
  posB = (posB<0?d->tam+(posB+1):posB);

  trocar(d->vetor, posA-1, posB-1);
}

void ordenarVD(TVDinamico *vd, TCompararVD comparar){
  TDadosVD *d = vd->dados;
  for (int i = 0; i < d->ocupacao-1; i++) {
    int imaior = 0;
    for(int j=1;j<d->ocupacao-i;j++){
      if(comparar(d->vetor[imaior],d->vetor[j]) < 0){
        imaior = j;
      }
    }
    trocar(d->vetor, imaior,d->ocupacao-i-1);
  }
}

int mensurarVD(TVDinamico *vd){
  TDadosVD *dv = vd->dados;
  return dv->tam;
}

int ocuparVD(TVDinamico *vd){
  TDadosVD *dv = vd->dados;
  return dv->ocupacao;
}
