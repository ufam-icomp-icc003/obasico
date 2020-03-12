/**
Cabecalho do Vetor dinâmico.
*/

typedef struct VDinamico{
  void *dados;
} TVDinamico;


TVDinamico* criarVD();
void inserir();
void remover();
void ordenar();
