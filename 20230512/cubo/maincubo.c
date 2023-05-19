#include <stdio.h>
#include <math.h>

#include "Cubo.h"

int main(){
    Cubo *cubo;
    float area, volume, lado;

    printf("indique o tamanho do lado do cubo: ");
    scanf("%f", &lado);
    cubo = criar(lado);
    area = Area(lado);
    volume = Volume(lado);
    printf("a area do lado do cubo eh %.2f e o volume do cubo eh %.2f\n", area, volume);
    Liberar(cubo);

    return 0;
}
