#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Cubo.h"

Cubo * criar(float lado){
    Cubo *cubo;
    cubo = malloc(sizeof(Cubo));
    cubo->lado1 = lado;
    return cubo;
}

float Area(float lado){
    float area;
    area = pow(lado, 2);
    return area;
}

float Volume(float lado){
    float volume;
    volume = pow(lado, 3);
    return volume;
}

void Liberar(Cubo *cubo){
    free(cubo);
}
