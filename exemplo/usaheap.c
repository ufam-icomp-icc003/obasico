#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "tad/heap.h"
#include "aviao.h"


int main(int argc, char const *argv[]) {

  THeap *heap = criarHeap(.comparar=compararInstanciasAviao);

  inserirHeap(heap, criarInstanciaAviao(4,0.5,5));
  inserirHeap(heap, criarInstanciaAviao(4,0.3,2));
  inserirHeap(heap, criarInstanciaAviao(8,0.1,3));
  inserirHeap(heap, criarInstanciaAviao(6,0.9,1));
  inserirHeap(heap, criarInstanciaAviao(10,0.1,7));


  TAviao *a = removerHeap(heap);
  imprimirTipoAviao(a);

  // a = acessarHeap(heap);
  // imprimirTipoAviao(a);

  a = removerHeap(heap);
  imprimirTipoAviao(a);

  a = removerHeap(heap);
  imprimirTipoAviao(a);

  a = removerHeap(heap);
  imprimirTipoAviao(a);

  a = removerHeap(heap);
  imprimirTipoAviao(a);

  return 0;
}
