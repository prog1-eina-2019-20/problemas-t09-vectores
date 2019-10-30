/********************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 30 de octubre de 2019
 * Resumen: Fichero de implementación de un módulo que incluye una función para  
 *          leer desde el teclado un vector de datos de tipo real. Se utiliza en 
 *          las soluciones a los problemas 1.º y 2.º planteados en la clase de 
 *          problemas del tema 9 (vectores).
\********************************************************************************/
#include <iostream>
using namespace std;

/*
 * Pre:  El vector «datos» tiene al menos «n» componentes.
 * Post: Ha solicitado «n» datos de tipo real al usuario y los ha copiado en
 *       las primeras «n» componentes del vector «datos», de menor a mayor
 *       índice.
 */
void leerDatos(double datos[], const int n) {
    cout << "Introduzca " << n << " enteros: ";
    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }
}
