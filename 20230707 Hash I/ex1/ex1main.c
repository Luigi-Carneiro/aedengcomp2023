#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

int main()
{
    TABELA Tabela;
    PACIENTE Pacientes[N] =
        {{"Laura", "238.582.950-93", 36, 23455}, {"Kaua", "382.890.542-58", 28, 54671}, {"Enrico", "184.398.495-32", 13, 45782}, {"Renata", "293.687.019-24", 24, 23463}, {"Eduardo", "301.485.677-02", 25, 17224}};

    inicializar(Tabela);

    for (int i = 0; i < N; i++)
        inserir(Tabela, Pacientes[i]);

    printHash(Tabela);

    return 0;
}