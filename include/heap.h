/* Interface do TAD. Declara o tipo da estrutura de dados e
 * os protótipo das funções públicas.
 */

typedef int(*TCompararHeap)(void *e1, void *e2);

/* Declaração opaca de heap. Só permite que o usuário declare ponteiros
 * para a estrutura, sem ter conhecimento do seu conteúdo.
 */
typedef struct{
  void *dados;
  TCompararHeap comparar;
} THeap;

/* Funções públcas para criar e destruir a heap.
 */
typedef struct{int capacidade; TCompararHeap comparar;}TPars_Heap;
#define criarHeap(...) criarHeap_base((TPars_Heap){.capacidade=1,.comparar=NULL,__VA_ARGS__});

THeap *criarHeap_base(TPars_Heap pars);
void destruirHeap(THeap *heap);

/* Funções para obter informações sobre a heap.
 */
int tamanhoHeap(THeap *heap);
int measurarHeap(THeap *heap);
int vaziaHeap(THeap *heap);
int cheiaHeap(THeap *heap);

/* Funções para acessar e manipular o conteúdo da heap.
 */
void *acessarHeap(THeap *heap);
void inserirHeap(THeap *heap, void *elem);
void *removerHeap(THeap *heap);
