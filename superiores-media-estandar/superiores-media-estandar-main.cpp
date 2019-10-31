/********************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 30 de octubre de 2019
 * Resumen: Solución al problema 1.º planteado en la clase de problemas
 *          del tema 9 (vectores).
 *          Versión que sigue el estándar de C++.
\********************************************************************************/
#include <iostream>
#include "../superiores-media/leer-vector-reales.h"
using namespace std;

/*
 * Número máximo de enteros con los que trabajaremos
 */
const int DIMENSION_MAXIMA = 40;


/*
 * Pre:  «datos» tiene «n» componentes.
 * Post: Ha devuelto el valor medio de los valores almacenados en las
 *       componentes de «datos».
 */
double calcularMedia(const double datos[], const int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += datos[i];
    }
    return suma / n;
}


/*
 * Pre:  El vector «datos» tiene al menos «n» componentes y n > 0.
 * Post: Ha devuelto cuántos de los datos almacenados en el vector «datos» son
 *       iguales o superiores al valor de «umbral».
 */
int contarSuperiores(const double datos[], const int n, const double umbral) {
    int cuenta = 0;
    for (int i = 0; i < n; i++) {
        if (datos[i] >= umbral) {
            cuenta++;
        }
    }
    return cuenta;
}


/*
 * Programa que solicita al usuario, en primer lugar, un número positivo «n»,
 * luego solicita «n» datos de tipo real y por último, escribe en la pantalla el
 * valor medio de los datos introducidos y cuántos de ellos son superiores a la
 * media.
 */
int main() {
    cout << "Introduzca un número positivo: ";
    int n;
    cin >> n;

    if (n > DIMENSION_MAXIMA) {
        n = DIMENSION_MAXIMA;
    }

    double datos[DIMENSION_MAXIMA];
    /* En esta versión, el dimensionamiento del vector se hace a partir de un dato
     * constante conocido en tiempo de compilación, de acuerdo con el estándar de
     * C++. Se va a trabajar con un vector «sobredimensionado»: de las
     * «DIMENSION_MAXIMA» que tiene el vector «datos», se va a trabajar solo con
     * las «n» primeras. */

    leerDatos(datos, n);
    double media = calcularMedia(datos, n);
    int superiores = contarSuperiores(datos, n, media);
    cout << "La media de los datos introducidos es " << media << " y " 
         << superiores
         << " de ellos son superiores o iguales a la media." << endl;
         
    return 0;
}
