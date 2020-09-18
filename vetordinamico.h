/** definição da estrutura de dados
*/
struct vdinamico{
  void *dados;
};
typedef struct vdinamico TVDinamico;

typedef int (*TCompararVD)(void* elemA, void* elemB);

TVDinamico *criarVD();
void inserirVD(TVDinamico *vd, void* carga, int pos);
void* removerVD(TVDinamico *vd, int pos);
void* acessarVD(TVDinamico *vd, int pos);
void ordenarVD(TVDinamico *vd, TCompararVD comparar);
int mensurarVD(TVDinamico *vd);
int ocuparVD(TVDinamico *vd);
void trocarVD(TVDinamico *vd, int posA, int posB);
