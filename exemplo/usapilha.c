#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "tad/pilha.h"
#include "inteiro.h"


int main(int argc, char const *argv[]) {
    TPilha *pilha = criarPilha();

    empilhar(pilha, criarInstanciaInt(10));
    empilhar(pilha, criarInstanciaInt(100));
    empilhar(pilha, criarInstanciaInt(1));
    empilhar(pilha, criarInstanciaInt(20));
    empilhar(pilha, criarInstanciaInt(24));

    int *p = desempilhar(pilha);
    printf("%d\n", *p);
}



  return 0;
}
