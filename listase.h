/*
definições do tipo lista simplesmente encadeada
*/
typedef struct {int tamMax;} TPars_LSE;
#define criarLSE(...) criarLSE_base((TPars_LSE){.tamMax=-1,__VA_ARGS__})

typedef struct{
  void *dados;
} TListaSE;

TListaSE *criarLSE_base(TPars_LSE pars);
int inserirFinalLSE(TListaSE *lsc, void *carga);
void *removerInicioLSE(TListaSE *lsc);

int mensurarLSE(TListaSE *lsc);
int inserirInicioLSE(TListaSE *lsc, void *carga);
void *removerFinalLSE(TListaSE *lsc);
void *acessarLSE(TListaSE *lsc, int pos);
