#ifndef prova_h
#define prova_h

typedef struct no{
    int numeros;
    struct no *proximo;
    struct no *anterior;
}ELEMENTO;

typedef struct{
    int tamanho;
    ELEMENTO *cabeca;
}DEQUE;

void inicializar(DEQUE *turma);
void inserir(DEQUE *turma, int novo);
void exibe(DEQUE turma);
void intercalar(DEQUE *pilha1, DEQUE *pilha2, DEQUE *resultante);
#endif