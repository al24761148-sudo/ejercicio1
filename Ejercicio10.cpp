
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 3
#define COLS 4
#define MAX 10  // tamaño máximo para todas las matrices

// Llenar matriz con números aleatorios 0-9
void llenarAleatorio(int filas, int cols, int matriz[MAX][MAX]) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            matriz[i][j] = rand() % 10;
}

// Imprimir matriz
void mostrarMatriz(int filas, int cols, int matriz[MAX][MAX], char nombre) {
    printf("\nMatriz %c:\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            printf("%3d", matriz[i][j]);
        printf("\n");
    }
}

// Calcular la transpuesta
void transponer(int filas, int cols, int A[MAX][MAX], int AT[MAX][MAX]) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            AT[j][i] = A[i][j];
}

int main(void) {
    int A[MAX][MAX], AT[MAX][MAX];

    srand(time(NULL));

    // Llenar matriz A
    llenarAleatorio(FILAS, COLS, A);

    // Calcular transpuesta
    transponer(FILAS, COLS, A, AT);

    // Mostrar matrices
    mostrarMatriz(FILAS, COLS, A, 'A');
    mostrarMatriz(COLS, FILAS, AT, 'T');  // ahora filas y cols correctas

    return 0;
}