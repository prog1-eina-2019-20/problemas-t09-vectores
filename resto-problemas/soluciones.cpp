/********************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 30 de octubre de 2019
 * Resumen: Soluciones a los problemas 3.º a 10.º de Programación 1 planteados en
 *          la clase de problemas del tema 9 (vectores).
\********************************************************************************/
#include <iostream>
using namespace std;


/********************************** Problema 3 **********************************/
/*
 * Pre:  El vector «v» tiene al menos «n» componentes y n ≥ 0.
 * Post: Ha devuelto el número de datos positivos almacenados en las
 *       primeras «n» componentes del vector «v».
 */
int numPositivos(const int v[], const int n) {
    int cuenta = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            cuenta++;
        }
    }
    return cuenta;
}


/********************************** Problema 4 **********************************/
/*
 * Pre:  Los vectores «original» y «copia» tienen al menos «n» componentes cada
 *       uno y n ≥ 0.
 * Post: Ha copiado las primeras «n» componentes del vector «original» en las
 *       primeras «n» componentes del vector «copia».
 */
void copiar(const int original[], const int n, int copia[]) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}


/********************************** Problema 5 **********************************/
/*
 * Pre:  Los vectores «v» y «w» tienen al menos «n» componentes cada uno y n ≥ 0.
 * Post: Ha devuelto ture si y solo si los datos de las primeras «n» componentes 
 *       de los vectores «v» y «w» son iguales.
 */
bool sonIguales(const int v[], const int w[], const int n) {
    bool deMomentoSonIguales = true;
    int i = 0;
    while (deMomentoSonIguales && i < n) {
        deMomentoSonIguales = v[i] == w[i];
        i++;
    }
    // !deMomentoSonIguales || i >= n
    return deMomentoSonIguales;
}


/********************************** Problema 6 **********************************/
/*
 * Pre:  El vector «v» tiene «n» componentes y se cumple que 0 ≤ i < n.
 * Post: Ha devuelto el número de veces que está repetido el dato
 *       «i»-ésimo del vector «v».
 */
int numeroRepeticiones(const int v[], const int i, const int n) {
    int repeticiones = 0;
    for (int j = 0; j < n; j++) {
        if (v[i] == v[j]) {
            repeticiones++;
        }
    }
    return repeticiones;
}


/*
 * Pre:  El vector «v» tiene «n» componentes.
 * Post: Ha devuelto la moda de los datos almacenados en el vector «v».
 */
int moda(const int v[], const int n) {
    int moda = v[0];
    int repeticionesDeLaModa = numeroRepeticiones(v, 0, n);

    for (int i = 1; i < n; i++) {
        int reptecionesDelDatoIesimo = numeroRepeticiones(v, i, n);
        if (reptecionesDelDatoIesimo > repeticionesDeLaModa) {
            moda = v[i];
            repeticionesDeLaModa = reptecionesDelDatoIesimo;
        }
    }
    return moda;
}

/********************************** Problema 7 **********************************/
/*
 * Pre:  El vector «datos» tiene «n» componentes.
 * Post: Ha devuelto el valor true si y solo si un dato igual al valor del
 *       parámetro «buscado» está almacenado en el vector «datos».
 */
bool esta(const int datos[], const int n, const int buscado) {
    bool encontrado = false;
    int i = 0;
    while (!encontrado && i < n) {
        encontrado = (datos[i] == buscado);
        i++;
    }
    return encontrado;
}

/********************************** Problema 8 **********************************/
/*
 * Pre:  El vector «v» tiene «n» componentes.
 * Post: Ha devuelto true si y solo si los datos del vector «v» están ordenados
 *       de forma no decreciente.
 */
bool estaOrdenada(const int v[], const int n) {
    // ordenada==false cuando se tiene la CERTEZA de que no está
    // ordenada de forma no decreciente, es decir, cuando se han
    // encontrado un par de componentes consecutivas en el orden
    // incorrecto.
    bool ordenada = true;
    int i = 0;
    while (ordenada && i < n - 1) {
        ordenada = (v[i] <= v[i + 1]);
        i++;
    }
    return ordenada;
}


/********************************** Problema 9 **********************************/
/*
 * Pre:  El vector «v» tiene al menos «n» componentes, con n ≥ 0; sea Np
 *       el número de datos positivos del vector «v»: el vector «p» tiene
 *       al menos Np componentes. El valor del parámetro «numPositivos» no
 *       está definido.
 * Post: Las primeras Np componentes del vector «p» almacenan los Np
 *       datos positivos de las primeras «n» componentes del vector «T» y
 *       numPositivos = Np.
 */
void copiaPositivos(const int T[], const int n,
                    int P[], int& numPositivos) {
    numPositivos = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] > 0) {
            P[numPositivos] = T[i];
            numPositivos++;
        }
    }
}


/********************************* Problema 10 **********************************/
/*
 * Pre:  El vector «secuencia» tiene «longitud» componentes.
 * Post: Ha escrito en el vector «secuencia» los primeros «longitud»
 *       dígitos de la secuencia de Kolakoski.
 */
void kolakoski(int secuencia[], const int longitud) {
    /* Declaraciones e inicializaciones */
    // valor del dígito o dígitos que hay que añadir a la secuencia
    int siguienteDigito = 1;

    // Por la definición del primer bloque de la secuencia
    secuencia[0] = siguienteDigito;

    // Número de dígitos obtenidos hasta el momento
    int numDigitos = 1;

    // Número de bloques obtenidos hasta el momento
    int numBloques = 1;

    while (numDigitos < longitud) {
        // Cálculo del siguiente dígito o dígitos a añadir:
        // si 1, es 2; si 2, es 1
        siguienteDigito = 3 - siguienteDigito;

        // Se añade un dígito del nuevo bloque
        secuencia[numDigitos] = siguienteDigito;

        // Si la longitud del nuevo bloque es 2 y "cabe" en el vector
        // se añade el segundo dígito del bloque
        if ((secuencia[numBloques - 1] == 2)
                && (numDigitos + 1 < longitud)) {
            secuencia[numDigitos + 1] = siguienteDigito;
        }

        // Se actualiza el número de bloques y dígitos de la secuencia
        // obtenidos
        numDigitos += secuencia[numBloques-1];
        numBloques++;
    }
}
