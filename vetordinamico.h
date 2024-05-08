/**
Cabecalho do Vetor dinâmico.
*/
typedef int (* TCompararVDinamico)(void*,void*);

typedef struct VDinamico{
  void *dados;
} TVDinamico;



TVDinamico* criarVD();
void inserir(TVDinamico *vd, void *carga_util, int pos);
void *remover(TVDinamico *vd, int pos);
void *acessar(TVDinamico *vd, int pos);
void ordenar();
