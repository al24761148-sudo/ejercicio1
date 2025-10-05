
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Llenar la matriz con números aleatorios 0-9
void llenarAleatorio(int tabla[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            tabla[i][j] = rand() % 10;
}

// Imprime la matriz
void mostrarTabla(int tabla[FILAS][COLS]) {
    printf("\nMatriz generada:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", tabla[i][j]);
        printf("\n");
    }
}

// Cuenta pares e impares
void contarParesImpares(int tabla[FILAS][COLS], int *pares, int *impares) {
    *pares = *impares = 0;
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            if (tabla[i][j] % 2 == 0)
                (*pares)++;
            else
                (*impares)++;
}

int main(void) {
    int tabla[FILAS][COLS];
    int pares, impares;

    srand(time(NULL));
    llenarAleatorio(tabla);
    mostrarTabla(tabla);
    contarParesImpares(tabla, &pares, &impares);

    printf("\nNúmeros pares: %d\n", pares);
    printf("Números impares: %d\n", impares);

    return 0;
}