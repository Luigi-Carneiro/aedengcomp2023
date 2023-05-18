struct cubo{
    float lado1;
};
typedef struct cubo Cubo;

Cubo * criar(float lado);
float Area(float lado);
float Volume(float lado);
void Liberar(Cubo *cubo);