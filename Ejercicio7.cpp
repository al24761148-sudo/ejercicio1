
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Llenar matriz aleatoria 
void llenarAleatorio(int tabla[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            tabla[i][j] = rand() % 10;
}

// Imprimir matriz
void mostrarTabla(int tabla[FILAS][COLS], char nombre) {
    printf("\nMatriz %c:\n", nombre);
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", tabla[i][j]);
        printf("\n");
    }
}

// Sumar dos matrices: C = A + B
void sumarMatrices(int A[FILAS][COLS], int B[FILAS][COLS], int C[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            C[i][j] = A[i][j] + B[i][j];
}

int main(void) {
    int A[FILAS][COLS], B[FILAS][COLS], C[FILAS][COLS];

    srand(time(NULL));

    // Llenar matrices A y B
    llenarAleatorio(A);
    llenarAleatorio(B);

    // Sumar matrices
    sumarMatrices(A, B, C);

    // Mostrar matrices
    mostrarTabla(A, 'A');
    mostrarTabla(B, 'B');
    mostrarTabla(C, 'C');

    return 0;
}