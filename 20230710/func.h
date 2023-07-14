#ifndef ex1_h
#define ex1_h
#define M 11

typedef struct{
    int valor;
} CODIGO;

typedef CODIGO *TABELA[M];

int chavelinear(int valor, int i);
int chavequadratica1(int valor, int i);
int chavequadratica2(int valor, int i);
int chavedupla(int valor, int i);
void inicializar(TABELA tabela);
int inserirlinear(TABELA tabela, int valor, int *cont);
int inserirquadratica1(TABELA tabela, int valor, int *cont);
int inserirquadratica2(TABELA tabela, int valor, int *cont);
int inserirdupla(TABELA tabela, int valor, int *cont);
void printHash(TABELA tabela);


#endif