
#include <stdio.h>
#include <string.h>

struct Materia {
    char nombre[30];
    float calificaciones;
};

struct Estudiante {
    int matricula;
    char nombre[50];
    int edad;
    float promedio;
    struct Materia materia[3];
};

int main() {
    struct Estudiante alumnos[24];
    int total = 0;
    int opcion;

    //Cargar datos desde el archivo
    FILE *archivo_lectura = fopen("Estudiantes.txt", "r");

    if (archivo_lectura != NULL) {

        while (fscanf(archivo_lectura, "%d,%49[^,],%d,%f\n",
            &alumnos[total].matricula,
            alumnos[total].nombre,
            &alumnos[total].edad,
            &alumnos[total].promedio) == 4) {

            for (int j = 0; j < 3; j++) {
                fscanf(archivo_lectura, "%29[^,],%f\n",
                    alumnos[total].materia[j].nombre,
                    &alumnos[total].materia[j].calificaciones);
            }

            total++;
        }

        fclose(archivo_lectura);
        printf("\nDatos cargados desde archivo,\n");

    }

    do {
        printf("\n Menu \n");
        printf("1. Capturar estudiantes\n");
        printf("2. Mostrar todos\n");
        printf("3. Buscar por matricula\n");
        printf("4. Mostrar mejor promedio\n");
        printf("5. Guardar en archivo\n");
        printf("6. Salir\n");
        printf("Elige una opcion : ");
        scanf("%d", &opcion);

        //Capturar
        if (opcion == 1) {

            int n;
            printf("¿cuantos estudiantes quieres capturar?: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {

                printf("\nEstudiante %d:\n", total + 1);

                printf("Matricula: ");
                scanf("%d", &alumnos[total].matricula);

                printf("Nombre: ");
                scanf(" %49[^\n]", alumnos[total].nombre);

                printf("Edad: ");
                scanf("%d", &alumnos[total].edad);

                float suma = 0;
                for (int j = 0; j < 3; j++) {

                    printf("Materia %d nombre: ", j + 1);
                    scanf(" %29[^\n]", alumnos[total].materia[j].nombre);

                    printf("Calificacion: ");
                    scanf("%f", &alumnos[total].materia[j].calificaciones);

                    suma += alumnos[total].materia[j].calificaciones;

                }

                alumnos[total].promedio = suma / 3.0;
                total++;
            }

        } else if (opcion == 2) {

            for (int i = 0; i < total; i++) {

                //Mostrar todos los datos del alumno		
                printf("\nMatricula: %d\n", alumnos[i].matricula);
                printf("Nombre: %s\n", alumnos[i].nombre);
                printf("Edad: %d\n", alumnos[i].edad);
                printf("Promedio: %.2f\n", alumnos[i].promedio);

                for (int j = 0; j < 3; j++) {
                    printf("Materia: %s  Calificacion: %.2f\n",
                        alumnos[i].materia[j].nombre,
                        alumnos[i].materia[j].calificaciones);
                }
            }

        }

        //Buscar alumno por matrícula
        else if (opcion == 3) {

            int buscada;
            printf("Matricula a buscar:");
            scanf("%d", &buscada);

            int encontrado = 0;
            for (int i = 0; i < total; i++) {
                if (alumnos[i].matricula == buscada) {

                    printf("\nmatricula: %d\n", alumnos[i].matricula);
                    printf("Nombre: %s\n", alumnos[i].nombre);
                    printf("Edad: %d\n", alumnos[i].edad);
                    printf("Promedio: %.2f\n", alumnos[i].promedio);

                    for (int j = 0; j < 3; j++) {
                        printf("Materia: %s  calificacion: %.2f\n",
                            alumnos[i].materia[j].nombre,
                            alumnos[i].materia[j].calificaciones);
                    }

                    encontrado = 1;
                }
            }

            if (!encontrado) {
                printf("No se encontró esa matrícula.\n");
            }

        }

        //Quien tiene el mejor promedio
        else if (opcion == 4) {

            if (total == 0) {
                printf("No hay estudiantes.\n");
            } else {
                int mejor = 0;

                for (int i = 1; i < total; i++) {
                    if (alumnos[i].promedio > alumnos[mejor].promedio) {
                        mejor = i;
                    }
                }

                printf("\nEl estudiante con mejor promedio es:\n");
                printf("%s (%.2f)\n",
                    alumnos[mejor].nombre,
                    alumnos[mejor].promedio);
            }

        }

        //Guardar datos del alumno
        else if (opcion == 5) {

            FILE *archivo = fopen("Estudiantes.txt", "w");

            for (int i = 0; i < total; i++) {

                fprintf(archivo, "%d,%s,%d,%.2f\n",
                    alumnos[i].matricula,
                    alumnos[i].nombre,
                    alumnos[i].edad,
                    alumnos[i].promedio);

                for (int j = 0; j < 3; j++) {
                    fprintf(archivo, "%s,%.2f\n",
                        alumnos[i].materia[j].nombre,
                        alumnos[i].materia[j].calificaciones);
                }
            }

            fclose(archivo);
            printf("Datos guardados,\n");

        }

    } while (opcion != 6);

    return 0;
}
				
				
					 
					
					
				
			
					
					
					
					
					
					
					
				
				
				
				
				
				
				
				
				
				
				
				
				
			
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
