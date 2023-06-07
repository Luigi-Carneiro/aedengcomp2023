typedef struct No {
    int elemento;
    struct No* proximo;

} No;

typedef struct {
    No* inicio;
    int quantidade;

} ListaLigada;

void inicializar(ListaLigada *lista);
void inserirFim(ListaLigada *lista, int elemento);
void print(No *inicio);
void liberar(No *inicio);
ListaLigada *copiarListaLigada(ListaLigada *lista);
No *organizarA(No *inicio);
No *organizarB(No *inicio);
