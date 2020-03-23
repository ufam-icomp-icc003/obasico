/**
Cabecalho do Vetor dinâmico.
*/

typedef struct VDinamico{
  void *dados;
} TVDinamico;



TVDinamico* criarVD();
void inserir(TVDinamico *vd, void *carga_util, int pos);
void remover();
void ordenar();
