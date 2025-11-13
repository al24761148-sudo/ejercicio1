
#include <stdio.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante alumnos[3];
    int i;

//Ciclo para pedir los 3 datos de los estudiantes.
    for(i = 0; i < 3; i++) {
        printf("Datos del estudiante %d\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", alumnos[i].nombre);   // puedes escribir el nombre con espacio para el apellido

        printf("Edad: ");
        scanf("%d", &alumnos[i].edad);

        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);

        printf("\n");
    }
    
//Aquí imprimes los datos guardados
    printf("---- Datos de los estudiantes ----\n");
    for(i = 0; i < 3; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Promedio: %.2f\n\n", alumnos[i].promedio);
    }

    return 0;
}

