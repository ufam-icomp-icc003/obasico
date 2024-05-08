#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "tad/fila.h"
#include "inteiro.h"

int main(int argc, char const *argv[]) {
    TFila *fila = criarFila();

    enfileirar(fila, criarInstanciaInt(10));
    enfileirar(fila, criarInstanciaInt(100));
    enfileirar(fila, criarInstanciaInt(1));
    enfileirar(fila, criarInstanciaInt(20));
    enfileirar(fila, criarInstanciaInt(24));

    int *p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);
    p = desenfileirar(fila);

    enfileirar(fila, criarInstanciaInt(200));
    enfileirar(fila, criarInstanciaInt(240));
    p = desenfileirar(fila);
    printf("%d\n", *p);
    p = desenfileirar(fila);
    printf("%d\n", *p);


  return 0;
}
