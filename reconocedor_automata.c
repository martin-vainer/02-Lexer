#include "reconocedor.h"
#include <stdio.h>
#include <ctype.h>

bool esOperador(char caracter) {
    if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/' || caracter == '(' || caracter == ')') {
        return true;
    } else {
        return false;
    }
}

int Tabla(int caracter) {
    static int tabla[18] = {0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (isdigit(caracter) || esOperador(caracter)) {
        return tabla[caracter - 40];
    } else {
        return -1;
    }
}

bool esExpresionValida(char expresion[], int linea) {
    int i = 0, estado_actual = 0;
    while (i < 100) {
        if (i != 0) {
            if (expresion[i] == '\0' || expresion[i] == '\n') {
                if (estado_actual == 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        estado_actual = Tabla(expresion[i]);
        if (estado_actual == -1) {
            return false;
        }
        i++;
    }

    return true;
}

void analizarExpresion(FILE* archivo) {
    char expresion[100];
    int linea = 1;

    while (fgets(expresion, sizeof(expresion), archivo)) {
        printf("Expresion regular en la linea %d: %s\n", linea, expresion);

        if (esExpresionValida(expresion, linea)) {
            printf("Analisis de la expresion en la linea %d:\n", linea);
            printf("Caracter  |  Token\n");
            printf("-----------------\n");

            int i = 0;
            while (expresion[i] != '\0' && expresion[i] != '\n') {
                if (isdigit(expresion[i])) {
                    int j = i;
                    while (isdigit(expresion[j])) {
                        j++;
                    }
                    printf("   ");
                    while (i < j) {
                        printf("%c", expresion[i]);
                        i++;
                    }
                    printf("  |  Numero\n");
                } else if (esOperador(expresion[i])) {
                    printf("   %c     |  Operador\n", expresion[i]);
                    i++;
                }
            }
            printf("\n");
        } else {
            for (int i = 0; expresion[i] != '\0'; i++) {
                char c = expresion[i];
                if (!isdigit(c) && !esOperador(c) && c != '\n') {
                    printf("Error en la linea %d, Caracter: %c, Ubicacion: %d\n", linea, c, i + 1);
                }
            }
            printf("\n");
        }

        linea++;
    }
}
