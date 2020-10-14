typedef struct {int tamanho;} TPars_VC;
#define criarVC(...) criarVC_base((TPars_VC){.tamanho=1,__VA_ARGS__})

typedef struct vetor_circular{
  void *dados;   
}TVCircular;

TVCircular *criarVC_base(TPars_VC pars);
int inserirVC(TVCircular *vc, void *carga, int pos);
void* removerVC(TVCircular *vc, int pos);
int atualizarVC(TVCircular *vc, void *carga, int pos);
