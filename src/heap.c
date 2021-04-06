#include <stdlib.h>
#include "heap.h"
#include "vetordinamico.h"

/* Definição da estrutura de heap. Neste exemplo, usaremos um vetor fixo, que
 * uma vez criado não pode ser redimensionado. Para utilizar outro tipo de estrutura,
 * basta trocar o campo "dados"
 */
typedef struct {
	TVDinamico *vd;
} TDadosHeap;


/* Protótipos para as funções internas.
 */
static void heapify(TVDinamico *vd, int pos, int tam, TCompararHeap comparar);
static void aumentar_chave(TVDinamico *vd, int pos, TCompararHeap comparar);


static int compararInt(void *e1, void *e2){
	return *((int*)e1) - *((int*)e2);
}

/* Função heapify. Corrige uma "quase-heap" fazendo um elemento incorretamente
 * posicionado "descer" até seu lugar correto na heap.
 */
static void heapify(TVDinamico *vd, int pos, int tam, TCompararHeap comparar)
{
	int maior = pos;
	int esq = 2 * pos;
	int dir = esq + 1;

	if (esq <= tam && comparar(acessarVD(vd,esq), acessarVD(vd,maior))>0) maior = esq;
	if (dir <= tam && comparar(acessarVD(vd,dir), acessarVD(vd,maior))>0) maior = dir;

	if (maior != pos) {
		trocarVD(vd, pos, maior);
		heapify(vd, maior, tam, comparar);
	}
}


/* Corrige a posição de um elemento que teve sua chave trocada por uma chave de
 * valor maior ou igual.
 */
static void aumentar_chave(TVDinamico *vd, int pos, TCompararHeap comparar)
{
	if (pos == 1)
			return;

	int pai = (pos / 2);
	if (comparar(acessarVD(vd,pos), acessarVD(vd, pai))>0) {
//		printf("posicao: %d %d\n", pai, pos);
		trocarVD(vd, pos, pai);
		aumentar_chave(vd, pai, comparar);
	}

}


/* Aqui começam as funções públicas do TAD.
 */

/* Cria uma heap vazia com um vetor cuja capacidade máxima é especificada
 * pelo usuário.
 */

THeap *criarHeap_base(TPars_Heap pars)
{
	THeap *nova;

	nova = malloc(sizeof(THeap));
	TDadosHeap *dh = malloc(sizeof(TDadosHeap));

	if (pars.comparar == NULL) pars.comparar=compararInt;

	dh->vd = criarVD(.tamanho=pars.capacidade);
	nova->dados = dh;
	nova->comparar = pars.comparar;

	return nova;
}


/* Libera toda a memória alocada para a heap.
 */
void destruirHeap(THeap *heap)
{
	// free(heap->dados);
	// free(heap);
}


int ocuparHeap(THeap *heap)
{
	TDadosHeap *dh = heap->dados;
	return ocuparVD(dh->vd);
}


int mensurarHeap(THeap *heap){
	TDadosHeap *dh = heap->dados;

	return mensurarVD(dh->vd);
}


int vaziaHeap(THeap *heap)
{
	TDadosHeap *dh = heap->dados;
	return (ocuparVD(dh->vd)==0);
}


int cheiaHeap(THeap *heap)
{
		TDadosHeap *dh = heap->dados;
		return (ocuparVD(dh->vd)==mensurarVD(dh->vd));
}


/* Acessa um elemento da heap. A heap só permite acessar o primeiro
 * elemento e ele só pode ser lido.
 * Pré-condições: a heap não pode estar vazia
 */
void *acessarHeap(THeap *heap)
{
	TDadosHeap *dh = heap->dados;

	return acessarVD(dh->vd,1);
}


/* Insere um elemento em uma posição válida da heap. Não há garantia de
 * qual será a posição resultante do elemento, apenas que ela irá
 * respeitar a propriedade de heap.
 * Pré-condições: a heap não pode estar cheia
 */
void inserirHeap(THeap *heap, void *elem)
{
	TDadosHeap *dh = heap->dados;

	int pos = ocuparVD(dh->vd)+1;
	inserirVD(dh->vd, elem, pos);

	aumentar_chave(dh->vd, pos, heap->comparar);

}


/* Remove um elemento do início da heap, garantindo que a estrutura irá
 * respeitar a propriedade de heap máxima.
 * Pré-condições: a heap não pode estar vazia
 */
void* removerHeap(THeap *heap)
{
	TDadosHeap *dh = heap->dados;

	int ocupa = ocuparVD(dh->vd);
	trocarVD(dh->vd,1,ocupa);
	void* carga = removerVD(dh->vd,ocupa);

	heapify(dh->vd, 1, ocupa-1, heap->comparar);

	return carga;
}
