#define MAX 100

typedef struct No {
    int elemento;
    int proximo;
} No;

typedef struct {
    No lista[MAX];
    int primeiro;
    int quantidade;
    int ultimo;
} Lista;

void inicializar(Lista *lista);
void inserir(Lista *lista, int elemento);
void print(Lista lista);
void copiarLista(Lista *l1, Lista *l2);
Lista organizarA(Lista lista);
Lista organizarB(Lista lista);
