
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILAS 4
#define MAX_COLS 4

//  Llenar matriz con números aleatorios 
void llenarAleatorio(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS]) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            matriz[i][j] = rand() % 10;
}

//   Imprimir matriz
void mostrarMatriz(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS], char nombre) {
    printf("\nMatriz %c:\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            printf("%3d", matriz[i][j]);
        printf("\n");
    }
}

// Multiplicar matrices: C = A * B
int multiplicarMatrices(int m, int n, int p,
                        int A[MAX_FILAS][MAX_COLS],
                        int B[MAX_FILAS][MAX_COLS],
                        int C[MAX_FILAS][MAX_COLS]) {
    // Validar dimensiones
    if (n <= 0) return 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    return 1; // Éxito
}

int main(void) {
    int A[MAX_FILAS][MAX_COLS], B[MAX_FILAS][MAX_COLS], C[MAX_FILAS][MAX_COLS];
    int m = 2, n = 3, p = 2; // dimensiones de ejemplo: A(2x3), B(3x2), C(2x2)

    srand(time(NULL));

    // Llenar matrices A y B con números aleatorios
    llenarAleatorio(m, n, A);
    llenarAleatorio(n, p, B);

    // Verificar multiplicación
    if (n != 3) { // esta verificación es extra, en general n debe ser cols de A = filas de B
        printf("❌ Error: dimensiones incompatibles para multiplicar.\n");
        return 1;
    }

    // Multiplicar
    if (!multiplicarMatrices(m, n, p, A, B, C)) {
        printf("❌ No se pudo multiplicar las matrices.\n");
        return 1;
    }

    // Mostrar matrices
    mostrarMatriz(m, n, A, 'A');
    mostrarMatriz(n, p, B, 'B');
    mostrarMatriz(m, p, C, 'C');

    return 0;
}