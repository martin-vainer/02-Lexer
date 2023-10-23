//---------------------------DECLARACION DE FUNCIONES (declaracion de la firma(prototipo))---------------------------//

#ifndef RECONOCEDOR_H
#define RECONOCEDOR_H

#include <stdbool.h>
#include <stdio.h>

bool esOperador(char caracter);
int Tabla(int caracter);
bool esExpresionValida(char expresion[], int linea);
void analizarExpresion(FILE* archivo);

#endif
