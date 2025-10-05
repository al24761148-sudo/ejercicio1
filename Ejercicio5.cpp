
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Llenar matriz aleatoria 0-99
void llenarAleatorio(int tabla[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            tabla[i][j] = rand() % 100;
}

// Imprimir matriz
void mostrarTabla(int tabla[FILAS][COLS]) {
    printf("\nMatriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d ", tabla[i][j]);
        printf("\n");
    }
}

// Encontrar máximo y mínimo
void maxMin(int tabla[FILAS][COLS], int *max, int *maxFila, int *maxCol,
            int *min, int *minFila, int *minCol) {
    *max = *min = tabla[0][0];
    *maxFila = *maxCol = *minFila = *minCol = 0;

    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++) {
            if (tabla[i][j] > *max) { *max = tabla[i][j]; *maxFila = i; *maxCol = j; }
            if (tabla[i][j] < *min) { *min = tabla[i][j]; *minFila = i; *minCol = j; }
        }
}

int main(void) {
    int tabla[FILAS][COLS];
    int max, maxFila, maxCol, min, minFila, minCol;

    srand(time(NULL));
    llenarAleatorio(tabla);
    mostrarTabla(tabla);
    maxMin(tabla, &max, &maxFila, &maxCol, &min, &minFila, &minCol);

    printf("\nMáximo: %d en [%d][%d]\n", max, maxFila, maxCol);
    printf("Mínimo: %d en [%d][%d]\n", min, minFila, minCol);

    return 0;
}