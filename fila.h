//FIFO Primeiro que Chega é atendido
//Prioridade --> Heap

typedef struct fila{
  void *dados;
}TFila;

TFila *criar_fila();
void enfileirar(TFila *f, void *elem);
void *desenfileirar(TFila *f);
short vazia(TFila *f);
void *cabeca(TFila *f);
