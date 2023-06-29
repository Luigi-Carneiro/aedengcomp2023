#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){
    DEQUE turma;
    inicializar(&turma);
    DADOS nomes1[3] = {{"Sirius"}, {"Canopus"}, {"Tarantula"}};
    DADOS nomes2[3] = {{"Tardigrado"}, {"Astra"}, {"Exeggutor"}};
    for(int i = 0; i < 3; i++)
        inserirInicio(&turma, nomes1[i]);
    

    for(int i = 0; i < 3; i++)
        inserirFim(&turma, nomes2[i]);
    
    exibe(turma, 'd', 0);
    exibe(turma, 'i', 3);
    exibe(turma, 'd', 1);
}
