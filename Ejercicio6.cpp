
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

// Imprimir matriz con suma por filas
void mostrarConSumaFilas(int tabla[FILAS][COLS], int sumaFilas[FILAS]) {
    printf("\nMatriz y suma por filas:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", tabla[i][j]);
        printf(" | Suma fila %d: %d\n", i, sumaFilas[i]);
    }
}

// Calcular suma por filas
void sumarFilas(int tabla[FILAS][COLS], int sumaFilas[FILAS]) {
    for (int i = 0; i < FILAS; i++) {
        sumaFilas[i] = 0;
        for (int j = 0; j < COLS; j++)
            sumaFilas[i] += tabla[i][j];
    }
}

//  Calcular suma por columnas
void sumarColumnas(int tabla[FILAS][COLS], int sumaCols[COLS]) {
    for (int j = 0; j < COLS; j++) {
        sumaCols[j] = 0;
        for (int i = 0; i < FILAS; i++)
            sumaCols[j] += tabla[i][j];
    }
}

//   Imprimir suma de columnas
void mostrarSumaColumnas(int sumaCols[COLS]) {
    printf("\nSuma columnas: ");
    for (int j = 0; j < COLS; j++)
        printf("%3d", sumaCols[j]);
    printf("\n");
}

int main(void) {
    int tabla[FILAS][COLS];
    int sumaFilas[FILAS], sumaCols[COLS];

    //   Inicializar semilla aleatoria
    srand(time(NULL));

    // Llenar matriz con números aleatorios
    llenarAleatorio(tabla);

    //  Calcular sumas
    sumarFilas(tabla, sumaFilas);
    sumarColumnas(tabla, sumaCols);

    // Mostrar resultados
    mostrarConSumaFilas(tabla, sumaFilas);
    mostrarSumaColumnas(sumaCols);

    return 0;
}