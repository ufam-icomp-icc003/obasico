/**
Definição do tipo FP
*/
typedef int (*TCompararFP)(void* carga1, void *carga2 );

typedef struct filaPrioridade{
  void *dados;
}TFilaPrioridade;

TFilaPrioridade *criarFP(int tamanho);
int inserirFP(TFilaPrioridade *fp, void *carga);
void *removerMenorFP(TFilaPrioridade *fp, TCompararFP comparar);
void *encontrarMenorFP(TFilaPrioridade *fp, TCompararFP comparar);
