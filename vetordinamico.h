/** definição de macros para construir
funções com argmentos opcional
*/
typedef struct {int tamanho; bool fixa;} TPars_VD;
#define criarVD(...) criarVD_base((TPars_VD){.tamanho=1,.fixa=false,__VA_ARGS__})

/**
Tipo Ponteiros para funções: callback
*/
typedef int (*TCompararVD)(void* elemA, void* elemB);


/** definição da estrutura de dados
*/
typedef struct vdinamico{
  void *dados;
} TVDinamico;

TVDinamico* criarVD_base(TPars_VD pars);
int inserirVD(TVDinamico *vd, void* carga, int pos);
void* removerVD(TVDinamico *vd, int pos);
void* acessarVD(TVDinamico *vd, int pos);
void ordenarVD(TVDinamico *vd, TCompararVD comparar);
int mensurarVD(TVDinamico *vd);
int ocuparVD(TVDinamico *vd);
void trocarVD(TVDinamico *vd, int posA, int posB);
int atualizarVD(TVDinamico *vd, void* carga, int pos);
