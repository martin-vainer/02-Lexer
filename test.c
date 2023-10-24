#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "reconocedor.h"

// // Función de prueba para verificar si el reconocimiento de operadores funciona correctamente
// void test_esOperador() {
//     printf("Prueba 1: esOperador('+') = %s\n", esOperador('+') ? "Verdadero" : "Falso");
//     printf("Prueba 2: esOperador('A') = %s\n", esOperador('A') ? "Verdadero" : "Falso");
//     // Agrega más pruebas según tus necesidades
// }

// // Función de prueba para verificar si el reconocimiento de expresiones válidas funciona correctamente
// void test_esExpresionValida() {
//     char expresion1[] = "2+3*(4-1)";
//     char expresion2[] = "3/(2-1))";
//     char expresion3[] = "1-7a8*462/())f-4";
//     printf("Prueba 1: esExpresionValida(expresion1) = %s\n", esExpresionValida(expresion1, 1) ? "Verdadero" : "Falso");
//     printf("Prueba 2: esExpresionValida(expresion2) = %s\n", esExpresionValida(expresion2, 2) ? "Verdadero" : "Falso");
//     printf("Prueba 3: esExpresionValida(expresion3) = %s\n", esExpresionValida(expresion1, 3) ? "Verdadero" : "Falso");
//     // Agrega más pruebas según tus necesidades
// }

// int main() {
//     // Ejecuta las funciones de prueba
//     test_esOperador();
//     test_esExpresionValida();
//     return 0;
// }

int main(void){
    assert(esOperador('+') == true);
    assert(esOperador('A') == false);
    assert(esOperador('a') == false);
    assert(esExpresionValida("2+3*(4-1)", 1) == true);
    assert(esExpresionValida("3/(2-1))", 2) == true);
    assert(esExpresionValida("1-7a8*462/())f-4", 3) == false);
    // assert(0);
    return 0;
}