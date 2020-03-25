typedef struct pilha{
  void *dados;
}TPilha;
TPilha *criar_pilha();
void empilhar(TPilha *p, void *elem);
void *desempilhar(TPilha *p);
short vazia_pilha(TPilha *p);
void *topo_pilha(TPilha *p);
