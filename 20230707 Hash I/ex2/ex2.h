#ifndef ex1_h
#define ex1_h
#define N 5

typedef struct PACIENTE{
    char *nome;
    char *cpf;
    int idade;
    int codigo;
} PACIENTE;

typedef struct aux{
    PACIENTE paciente;
    struct aux *proximo;
}ELEMENTO;

typedef ELEMENTO *TABELA[N];

int chave(int codigo);
void inicializar(TABELA tabela);
int inserir(TABELA tabela, PACIENTE paciente);
void printHash(TABELA tabela);

#endif