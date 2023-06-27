typedef struct {
    int identificador;
    char nome[10];
}DADOS;

typedef struct avioes{
    DADOS aviao;
    struct avioes *proximo;
}ELEMENTO;

typedef struct {
    ELEMENTO *topo;
    int tamanho;
}PILHA;

void printPilha(PILHA *pilha);
int inserirElemento(PILHA *pilha, DADOS novo);
void inicializar(PILHA *fila);
void tamanhoPilha(PILHA pilha);
void liberaAviao(PILHA *pilha, int pos);
void pop(PILHA *pilha);