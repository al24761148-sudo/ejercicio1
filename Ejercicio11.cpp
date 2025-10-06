
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define MAX 10  // tamaño máximo para la matriz

// Llenar matriz cuadrada con números aleatorios 
void llenarAleatorio(int matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = rand() % 10;
}

// Imprimir matriz
void mostrarMatriz(int matriz[MAX][MAX], int n, char nombre) {
    printf("\nMatriz %c:\n", nombre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d", matriz[i][j]);
        printf("\n");
    }
}

//   Calcular y mostrar diagonales
void diagonales(int matriz[MAX][MAX], int n) {
    int sumaPrincipal = 0, sumaSecundaria = 0;

    printf("\nDiagonal principal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matriz[i][i]);
        sumaPrincipal += matriz[i][i];
    }
    printf("\nSuma diagonal principal: %d\n", sumaPrincipal);

    printf("\nDiagonal secundaria: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matriz[i][n - 1 - i]);
        sumaSecundaria += matriz[i][n - 1 - i];
    }
    printf("\nSuma diagonal secundaria: %d\n", sumaSecundaria);
}

int main(void) {
    int matriz[MAX][MAX];

    srand(time(NULL));

    // Llenar matriz
    llenarAleatorio(matriz, N);

    // Mostrar matriz
    mostrarMatriz(matriz, N, 'M');

    // Mostrar diagonales y sumas
    diagonales(matriz, N);

    return 0;
}