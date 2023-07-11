#ifndef ex1_h
#define ex1_h
#define N 5

typedef struct PACIENTE{
    char *nome;
    char *cpf;
    int idade;
    int codigo;
    int disponivel;
} PACIENTE;

typedef PACIENTE *TABELA[N];

int chave(int codigo);
void inicializar(TABELA tabela);
int inserir(TABELA tabela, PACIENTE paciente);
void printHash(TABELA tabela);
void tiraHash(TABELA tabela, int cod);

#endif