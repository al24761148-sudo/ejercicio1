
#include <stdio.h>

#define FILAS 4
#define COLS 4

// Inicializa la matriz en ceros
void ponerCeros(int tabla[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            tabla[i][j] = 0;
}

// Imprime la matriz
void mostrarTabla(int tabla[FILAS][COLS]) {
    printf("\nMatriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", tabla[i][j]);
        printf("\n");
    }
}

int main(void) {
    int tabla[FILAS][COLS];
    ponerCeros(tabla);
    mostrarTabla(tabla);
    return 0;
}
