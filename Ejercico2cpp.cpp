
#include <stdio.h>
#include <stdlib.h>

#define FILAS  4
#define COLS 4

// Llenar la matriz con números del usuario
void pedirDatos(int tabla[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            int ok = 0;
            while (!ok) {
                printf("Escribe el número para [%d][%d]: ", i, j);
                if (scanf("%d", &tabla[i][j]) == 1) {
                    ok = 1;
                } else {
                    printf("❌ Eso no es un número entero. Intenta otra vez.\n");
                    scanf("%*s"); // descarta entrada inválida
                }
            }
        }
    }
}

// Imprime la matriz
void mostrarTabla(int tabla[FILAS][COLS]) {
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", tabla[i][j]);
        printf("\n");
    }
}

int main(void) {
    int tabla[FILAS][COLS];
    pedirDatos(tabla);
    mostrarTabla(tabla);
    return 0;
}
