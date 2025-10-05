
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Llenar matriz aleatoria 0-9
void llenarAleatorio(int tabla[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            tabla[i][j] = rand() % 10;
}

// Imprimir matriz
void mostrarTabla(int tabla[FILAS][COLS]) {
    printf("\nMatriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", tabla[i][j]);
        printf("\n");
    }
}

// Calcular suma total
int sumarElementos(int tabla[FILAS][COLS]) {
    int suma = 0;
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            suma += tabla[i][j];
    return suma;
}

int main(void) {
    int tabla[FILAS][COLS];
    int suma;
    float promedio;

    srand(time(NULL));
    llenarAleatorio(tabla);
    mostrarTabla(tabla);

    suma = sumarElementos(tabla);
    promedio = (float)suma / (FILAS * COLS);

    printf("\nSuma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);

    return 0;
}