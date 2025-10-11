 
#include <stdio.h>
#include <string.h>

// convierte un número romano a su equivalente en número arábigo
int roman_to_int(char r) {
    if (r == 'I') return 1;
    if (r == 'V') return 5;
    if (r == 'X') return 10;
    if (r == 'L') return 50;
    if (r == 'C') return 100;
    if (r == 'D') return 500;
    if (r == 'M') return 1000;
    return 0; // por si cometen un error al escribir
}

 //  Convierte un número romano a arábigo
int roman_to_arabic(const char *roman_str) {
    int total = 0;
    int actual, siguiente;

    for (int i = 0; i < strlen(roman_str); i++) {
        actual = roman_to_int(roman_str[i]);
        siguiente = roman_to_int(roman_str[i + 1]);

        if (actual < siguiente) {
            total -= actual;
        } else {
            total += actual;
        }
    }

    return total;
}

int main() {
    char romano[20];
    
// muestra el rsultado final
    printf("Ingresa un número romano con mayúsculas: ");
    scanf("%s", romano);

    int resultado = roman_to_arabic(romano);
    printf("El numero arabigo equivalente es: %d\n", resultado);

    return 0;
}