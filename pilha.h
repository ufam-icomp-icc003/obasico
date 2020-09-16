/**
definição da estrutura pilha
*/
struct pilha{
  void* dados;
};

typedef struct pilha TPilha;

TPilha *criarPilha();
void empilhar(TPilha *pilha, void* carga);
void *desempilhar(TPilha *pilha);
int mensurarPilha(TPilha *pilha);
