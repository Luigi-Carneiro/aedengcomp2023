typedef struct{
    char nome[20];
}DADOS;

typedef struct no{
    DADOS aluno;
    struct no *proximo;
    struct no *anterior;
}ELEMENTO;

typedef struct{
    int tamanho;
    ELEMENTO *cabeca;
}DEQUE;

void inicializar(DEQUE *turma);
void inserirInicio(DEQUE *turma, DADOS novo);
void inserirFim(DEQUE *turma, DADOS novo);
void exibe(DEQUE turma, char ordem, int pos);