struct aluno{
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
};
typedef struct aluno ALUNO;

struct turma{
    ALUNO *alunos;
    int quantidade;
};
typedef struct turma TURMA;

TURMA *alocarTurma(int n);
TURMA *inserirTurma(TURMA *turma);
void printAluno(TURMA *turma, int);
void printTurma(TURMA *turma);
int buscaseq(TURMA *turma, int cod);
int buscabinrec(TURMA *turma, int cod, int primeiro, int ultimo);
int liberarTurma(TURMA *turma);