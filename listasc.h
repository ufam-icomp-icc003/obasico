/*
definições do tipo lista simplesmente encadeada
*/
typedef struct {int tamMax;} TPars_LSC;
#define criarLSC(...) criarLSC_base((TPars_LSC){.tamMax=-1,__VA_ARGS__})

typedef struct lsc {
  void *dados;
} TListaSC;

TListaSC *criarLSC_base(TPars_LSC pars);
int inserirLSC(TListaSC *lsc, void *carga);
void *removerLSC(TListaSC *lsc);

int mensurarLSC(TListaSC *lsc);
void inserirInicioLSC(TListaSC *lsc, void *carga);
void *removerFinalLSC(TListaSC *lsc);
void *acessarLSC(TListaSC *lsc, int pos);
