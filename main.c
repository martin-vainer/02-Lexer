#include <stdio.h>
#include "reconocedor.h"

int main() {
    FILE* archivo_entrada;
    archivo_entrada = fopen("expresiones.txt", "r");

    if (archivo_entrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    analizarExpresion(archivo_entrada);

    fclose(archivo_entrada);
    return 0;
}

