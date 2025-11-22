#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar_menu(void) {
    printf("==== Mi App en C ====\n");
    printf("1. Saludar\n");
    printf("2. Sumar dos numeros\n");
    printf("3. Contar palabras de una frase\n");
    printf("0. Salir\n");
    printf("Selecciona una opcion: ");
}

int sumar(int a, int b) {
    return a + b;
}

int contar_palabras(const char *s) {
    int count = 0, in_word = 0;
    for (const char *p = s; *p; ++p) {
        if (*p != ' ' && *p != '\t' && *p != '\n') {
            if (!in_word) { in_word = 1; count++; }
        } else {
            in_word = 0;
        }
    }
    return count;
}

int main(void) {
    int opcion = -1;
    char buffer[256];

    while (1) {
        mostrar_menu();
        if (scanf("%d", &opcion) != 1) {
            fprintf(stderr, "Entrada no valida.\n");
            return 1;
        }
        // Limpia salto de linea pendiente
        int c; while ((c = getchar()) != '\n' && c != EOF) {}

        switch (opcion) {
            case 1: {
                printf("Escribe tu nombre: ");
                if (fgets(buffer, sizeof(buffer), stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    printf("Hola, %s!\n\n", buffer);
                }
                break;
            }
            case 2: {
                int a, b;
                printf("Ingresa dos numeros (ej. 3 7): ");
                if (scanf("%d %d", &a, &b) == 2) {
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Resultado: %d\n\n", sumar(a, b));
                } else {
                    fprintf(stderr, "Entrada no valida.\n");
                    return 1;
                }
                break;
            }
            case 3: {
                printf("Escribe una frase: ");
                if (fgets(buffer, sizeof(buffer), stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    printf("Palabras: %d\n\n", contar_palabras(buffer));
                }
                break;
            }
            case 0:
                printf("Saliendo...\n");
                return 0;
            default:
                printf("Opcion no valida.\n\n");
        }
    }
}