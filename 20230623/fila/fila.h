typedef struct {
    int identificador;
    char nome[10];
}DADOS;

typedef struct avioes{
    DADOS aviao;
    struct avioes *proximo;
}ELEMENTO;

typedef struct {
    ELEMENTO *primeiro;
    ELEMENTO *ultimo;
    int tamanho;
}FILA;

void inicializar(FILA *fila);
int inserirElemento(FILA *fila, DADOS novo);
void tamanhoFila(FILA fila);
int decolagem(FILA *fila);
int printFila(FILA *fila);
int primeiroElemento(FILA *fila);