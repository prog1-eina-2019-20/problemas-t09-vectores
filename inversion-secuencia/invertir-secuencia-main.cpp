/********************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 30 de octubre de 2019
 * Resumen: Solución al problema 2.º planteado en la clase de problemas
 *          del tema 9 (vectores).
\********************************************************************************/
#include <iostream>
#include "../superiores-media/leer-vector-reales.h"
using namespace std;


/*
 * Pre:  El vector «datos» tiene al menos «n» componentes y n > 0.
 * Post: Ha escrito los valores de las «n» primeras componentes del vector
 *       «datos» desde la de mayor índice a la de menor.
 */
void escribirDatosAlReves(const double datos[], const int n) {
    cout << "La secuencia en orden inverso es" << endl;
    for (int i = n - 1; i > 0; i--) {
        cout << datos[i] << ", ";
    }
    cout << datos[0];
}


/*
 * Programa que solicita al usuario, en primer lugar, un número positivo «n»,
 * luego solicita «n» datos de tipo real y por último los escribe en la pantalla
 * en orden inverso al introducido.
 */
int main() {
    cout << "Introduzca un número positivo: " << flush;
    int n;
    cin >> n;

    double datos[n];
    /* Advertencia: el dimensionamiento de un vector a partir de
     * un dato no constante no forma parte del estándar de C++, pero está
     * implementado por los compiladores LLVM Clang y GNU GCC. */

    leerDatos(datos, n);
    escribirDatosAlReves(datos, n);
}
