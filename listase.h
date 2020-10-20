/*
definições do tipo lista simplesmente encadeada
*/
typedef struct {int tamMax;} TPars_LSE;
#define criarLSE(...) criarLSE_base((TPars_LSE){.tamMax=-1,__VA_ARGS__})

typedef struct{
  void *dados;
} TListaSE;

typedef int(*TCompararLSE)(void *e1, void *e2);

TListaSE *criarLSE_base(TPars_LSE pars);
void destruirLSE(TListaSE *lse);
int inserirFinalLSE(TListaSE *lsc, void *carga);
void *removerInicioLSE(TListaSE *lsc);


int mensurarLSE(TListaSE *lsc);
int inserirInicioLSE(TListaSE *lsc, void *carga);
int inserirOrdenadoLSE(TListaSE *lsc, void *carga, TCompararLSE comparar);
void *removerFinalLSE(TListaSE *lsc);
void *acessarLSE(TListaSE *lse, int pos);
int vaziaLSE(TListaSE *lse);
