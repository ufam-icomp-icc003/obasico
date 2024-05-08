typedef struct aviao TAviao;
void *criarInstanciaAviao(int nroTurbina, double nivelCombustivel, int prioridade);
int compararInstanciasAviao(void *elemA, void *elemB);
void imprimirTipoAviao(TAviao *a);
