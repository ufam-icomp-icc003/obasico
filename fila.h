/**
Definição da fila com politica FIFO
*/

typedef struct fila TFila;
struct fila{
  void *dados;
};


TFila *criarFila();
void enfileirar(TFila *fila, void *carga);
void *desenfileirar(TFila *fila);
int mensurarFila(TFila *fila);
