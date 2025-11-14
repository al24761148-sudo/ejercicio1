
#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {

    struct Estudiante alumnos[3];
    int i;
    int datos_cargados = 0; 
    int count = 0;

    FILE *archivo_lectura = fopen("datos_estudiantes.txt", "r");

    if (archivo_lectura != NULL) {

        //Aquí se lee la cabecera 
        fscanf(archivo_lectura, "%*[^,],%*[^,],%*[^\n]\n");

        //Leer los 3 estudiantes
        while (count < 3 &&
               fscanf(archivo_lectura, "%49[^,],%d,%f\n",
                      alumnos[count].nombre,
                      &alumnos[count].edad,
                      &alumnos[count].promedio) == 3) 
        {
            count++;
        }

        fclose(archivo_lectura);

        if (count == 3) {
            printf("Datos cargados desde archivo correctamente \n\n");
            datos_cargados = 1;
        }
    }

    if (!datos_cargados) {
        for (i = 0; i < 3; i++) {

            printf("Datos del estudiante %d\n", i + 1);

            printf("Nombre: ");
            scanf(" %[^\n]", alumnos[i].nombre);

            printf("Edad: ");
            scanf("%d", &alumnos[i].edad);

            printf("Promedio: ");
            scanf("%f", &alumnos[i].promedio);

            printf("\n");
        }
    }

    //Aquí imprimimos los datos
    float suma_promedios = 0.0;
    int mejor_estudiante_index = 0; 

    printf("\n Datos de los Estudiantes \n");
    for (i = 0; i < 3; i++) {

        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Promedio: %.2f\n\n", alumnos[i].promedio);

        suma_promedios += alumnos[i].promedio;

        if (alumnos[i].promedio > alumnos[mejor_estudiante_index].promedio) {
            mejor_estudiante_index = i;
        }
    }

    //Calculamos el promedio general del grupo
    float promedio_general = suma_promedios / 3;
    printf("PROMEDIO GENERAL DEL GRUPO: %.2f \n", promedio_general);

    
    //Determinamos quién es el mejor estudiante
    printf("MEJOR ESTUDIANTE: %s (%.2f) \n\n",
           alumnos[mejor_estudiante_index].nombre,
           alumnos[mejor_estudiante_index].promedio);


    //Guardamos los datos en un archivo
    FILE *archivo_escritura = fopen("datos_estudiantes.txt", "w");

    if (archivo_escritura == NULL) {
        printf("Error al guardar archivo.\n");
        return 1;
    }

    // Cabecera
    fprintf(archivo_escritura, "Nombre,Edad,Promedio\n");

    // Escribir los datos de cada estudiante separados por comas
    for (i = 0; i < 3; i++) {
        fprintf(archivo_escritura, "%s,%d,%.2f\n",
                alumnos[i].nombre,
                alumnos[i].edad,
                alumnos[i].promedio);
    }

    printf("Datos guardados exitosamente en 'datos_estudiantes.txt' \n");

return 0; 
}