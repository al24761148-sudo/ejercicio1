
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define MAX 10  // tamaño máximo para la matriz

// Llenar matriz con números aleatorios 
void llenarAleatorio(int matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = rand() % 10;
}

//   Imprimir matriz
void mostrarMatriz(int matriz[MAX][MAX], int n, char nombre) {
    printf("\nMatriz %c:\n", nombre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d", matriz[i][j]);
        printf("\n");
    }
}

// Buscar un elemento en la matriz
void buscarElemento(int matriz[MAX][MAX], int n, int valor) {
    int encontrado = 0;

    printf("\nBuscando el valor %d en la matriz...\n", valor);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == valor) {
                printf("✔ Encontrado en posición [%d][%d]\n", i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("❌ El valor %d no se encuentra en la matriz.\n", valor);
    }
}

int main(void) {
    int matriz[MAX][MAX];
    int numero;

    srand(time(NULL));

    // Llenar matriz aleatoria
    llenarAleatorio(matriz, N);

    // Mostrar matriz
    mostrarMatriz(matriz, N, 'M');

    // Pedir número a buscar
    printf("\nIngrese un número a buscar (0-9): ");
    if (scanf("%d", &numero) != 1) {
        printf("❌ Error: debe ingresar un número entero.\n");
        return 1;
    }

    // Buscar elemento
    buscarElemento(matriz, N, numero);

    return 0;
}