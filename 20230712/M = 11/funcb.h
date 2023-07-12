#ifndef funcb_h
#define funcb_h
#define M 11

typedef struct aux{
    int numero;
    struct aux *proximo;
}ELEMENTO;

typedef ELEMENTO *TABELA[M];

int chave(int codigo);
void inicializar(TABELA tabela);
int inserir(TABELA tabela, int num);
void printHash(TABELA tabela);


#endif