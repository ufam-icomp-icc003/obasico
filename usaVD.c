#include "stdio.h"
#include "vetordinamico.h"

int main(int argc, char const *argv[]) {

  TVDinamico *meuVD = criarVD();

  void *dado = NULL;

  inserir(meuVD, dado, 1);

  /** aqui o encapsulamento dos dados
  impede o acesso direto aos atributos
  do TAD.
  */
  int tam = meuVD->dados->tam;
  int ocupacao = meuVD->dados->ocupacao;


  return 0;
}
