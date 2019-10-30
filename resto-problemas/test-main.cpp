/********************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Miguel Ángel Latre
 * Última revisión: 30 de octubre de 2019
 * Resumen: Programa de pruebas de las soluciones a los problemas 3.º a 10.º de
 *          Programación 1 planteados en la clase de problemas del tema 9
 *          (vectores).
\********************************************************************************/
#include <iostream>
using namespace std;

/* Cabeceras de las funciones solicitadas en el enunciado */
int numPositivos(const int v[], const int n);
void copiar(const int original[], const int n, int copia[]);
bool sonIguales(const int v[], const int w[], const int n);
int moda(const int v[], const int n);
bool esta(const int datos[], const int n, const int buscado);
bool estaOrdenada(const int v[], const int n);
void copiaPositivos(const int T[], const int n, int P[], int& numPositivos);
void kolakoski(int secuencia[], const int longitud);


/*
 * Datos para las pruebas de «numPositivos», «copiar», «sonIguales» y
 * «copiaPositivos».
 */
const int VECTOR_0[] = {};
const int VECTOR_1[] = {5};
const int VECTOR_2[] = {-5};
const int VECTOR_3[] = {-1, 1};
const int VECTOR_4[] = {1, -1};
const int VECTOR_5[] = {1, -2, 3, -4, 5, -6};
const int VECTOR_6[] = {-1, 2, -3, 4, -5, 6};


/*
 * Prueba la función «numPositivos» con los datos anteriores. Si el resultado de
 * una prueba es correcto, escribe en la pantalla true; en caso contrario, escribe
 * en la pantalla false.
 */
void pruebaNumPositivos() {
    cout << "Pruebas de la función «numPositivos»: " << endl;
    cout << boolalpha;
    cout << (numPositivos(VECTOR_0, 0) == 0) << endl;
    cout << (numPositivos(VECTOR_1, 1) == 1) << endl;
    cout << (numPositivos(VECTOR_2, 1) == 0) << endl;
    cout << (numPositivos(VECTOR_3, 2) == 1) << endl;
    cout << (numPositivos(VECTOR_4, 2) == 1) << endl;
    cout << (numPositivos(VECTOR_5, 6) == 3) << endl;
    cout << (numPositivos(VECTOR_6, 6) == 3) << endl;
}

/*
 * Prueba la función «copiar».
 * Si el resultado de una prueba es correcto, escribe en la pantalla true;
 * en caso contrario, escribe en la pantalla false.
 * Utiliza la función «sonIguales», que es también objeto de otras pruebas.
 */
void pruebaCopiar() {
    cout << endl;
    cout << "Pruebas de la función «copiar»: " << endl;
    cout << boolalpha;
    int vectorCopiado[6];

    copiar(VECTOR_0, 0, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_0, 0) << endl;

    copiar(VECTOR_1, 1, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_1, 1) << endl;

    copiar(VECTOR_2, 1, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_2, 1) << endl;

    copiar(VECTOR_3, 2, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_3, 2) << endl;

    copiar(VECTOR_4, 2, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_4, 2) << endl;

    copiar(VECTOR_5, 6, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_5, 6) << endl;

    copiar(VECTOR_6, 6, vectorCopiado);
    cout << sonIguales(vectorCopiado, VECTOR_6, 6) << endl;
}


/*
 * Prueba la función «sonIguales».
 * Si el resultado de una prueba es correcto, escribe en la pantalla true;
 * en caso contrario, escribe en la pantalla false.
 */
void pruebaSonIguales() {
    cout << endl;
    cout << "Pruebas de la función «sonIguales»: " << endl;
    cout << boolalpha;

    cout << sonIguales(VECTOR_0, VECTOR_0, 0) << endl;
    cout << sonIguales(VECTOR_1, VECTOR_1, 1) << endl;
    cout << sonIguales(VECTOR_2, VECTOR_2, 1) << endl;
    cout << sonIguales(VECTOR_3, VECTOR_3, 2) << endl;
    cout << sonIguales(VECTOR_4, VECTOR_4, 2) << endl;
    cout << sonIguales(VECTOR_5, VECTOR_5, 6) << endl;
    cout << sonIguales(VECTOR_6, VECTOR_6, 6) << endl;
}


/*
 * Prueba la función «moda».
 * Si el resultado de una prueba es correcto, escribe en la pantalla true;
 * en caso contrario, escribe en la pantalla false.
 * Utiliza los vectores de ejemplo del enunciado.
 */
void pruebaModa() {
    cout << endl;
    cout << "Pruebas de la función «moda»: " << endl;    
    cout << boolalpha;

    const int T1[] = {4, 7, 5, 5, 1, 7, 6, 9, 2, 2, 5, 0, 7, 9, 5, 6, 5, 0, 8, 0, 2};
    cout << (moda(T1, 21) == 5) << endl;

    const int T2[] = {1, 5, 8, 6, 8, 3, 4, 6, 6, 1, 5, 8, 1, 9, 5, 9, 5, 8, 9, 2, 9};
    int m = moda(T2, 21);
    cout << (m == 5 || m == 8 || m == 9) << endl;
}


/*
 * Prueba la función «esta».
 * Si el resultado de una prueba es correcto, escribe en la pantalla true;
 * en caso contrario, escribe en la pantalla false.
 */
void pruebaEsta() {
    cout << endl;
    cout << "Pruebas de la función «esta»: " << endl;    
    cout << boolalpha;

    cout << !esta(VECTOR_0, 0,  0) << endl;
    cout << !esta(VECTOR_1, 1,  0) << endl;
    cout <<  esta(VECTOR_1, 1,  5) << endl;
    cout << !esta(VECTOR_2, 1,  5) << endl;
    cout <<  esta(VECTOR_2, 1, -5) << endl;
    cout << !esta(VECTOR_6, 6,  3) << endl;
    cout <<  esta(VECTOR_6, 6, -3) << endl;
}


/*
 * Prueba la función «estaOrdenada».
 * Si el resultado de una prueba es correcto, escribe en la pantalla true;
 * en caso contrario, escribe en la pantalla false.
 */
void pruebaEstaOrdenada() {
    const int ORDENADA[] = {1, 2, 3, 4, 5, 6};
    cout << endl;
    cout << "Pruebas de la función «estaOrdenada»: " << endl;    
    cout << boolalpha;

    cout <<  estaOrdenada(VECTOR_0, 0) << endl;
    cout <<  estaOrdenada(VECTOR_1, 1) << endl;
    cout <<  estaOrdenada(VECTOR_2, 1) << endl;
    cout <<  estaOrdenada(VECTOR_3, 2) << endl;
    cout << !estaOrdenada(VECTOR_4, 2) << endl;
    cout << !estaOrdenada(VECTOR_5, 6) << endl;
    cout << !estaOrdenada(VECTOR_6, 6) << endl;
    cout <<  estaOrdenada(ORDENADA, 6) << endl;
    
}

/*
 * Prueba la función «copiaPositivos».
 * Si el resultado de una prueba es correcto, escribe en la pantalla true;
 * en caso contrario, escribe en la pantalla false.
 * Utiliza la función «sonIguales», que es también objeto de otras pruebas.
 */
void pruebaCopiaPositivos() {
    const int RESULTADO_3_Y_4[] = {1};
    const int RESULTADO_5[] = {1, 3, 5};
    const int RESULTADO_6[] = {2, 4, 6};
    
    cout << endl;
    cout << "Pruebas de la función «copiaPositivos»: " << endl;
    cout << boolalpha;

    int positivos[6];
    int nPos;

    copiaPositivos(VECTOR_0, 0, positivos, nPos);
    cout << ((nPos == 0) && sonIguales(positivos, VECTOR_0, nPos)) << endl;

    copiaPositivos(VECTOR_1, 1, positivos, nPos);
    cout << ((nPos == 1) && sonIguales(positivos, VECTOR_1, nPos)) << endl;

    copiaPositivos(VECTOR_2, 1, positivos, nPos);
    cout << ((nPos == 0) && sonIguales(positivos, VECTOR_0, nPos)) << endl;

    copiaPositivos(VECTOR_3, 2, positivos, nPos);
    cout << ((nPos == 1) && sonIguales(positivos, RESULTADO_3_Y_4, nPos)) << endl;

    copiaPositivos(VECTOR_4, 2, positivos, nPos);
    cout << ((nPos == 1) && sonIguales(positivos, RESULTADO_3_Y_4, nPos)) << endl;

    copiaPositivos(VECTOR_5, 6, positivos, nPos);
    cout << ((nPos == 3) && sonIguales(positivos, RESULTADO_5, nPos)) << endl;

    copiaPositivos(VECTOR_6, 6, positivos, nPos);
    cout << ((nPos == 3) && sonIguales(positivos, RESULTADO_6, nPos)) << endl;
}


/*
 * Prueba la función «kolakoski», escribiendo los primeros 70 dígitos en la
 * pantalla.
 */
void pruebaKolakoski() {
    cout << endl;
    cout << "Pruebas de la función «kolakoski»: " << endl;
    const int NUM_DIGITOS = 70;
    int k[NUM_DIGITOS];
    kolakoski(k, NUM_DIGITOS);
    for (int i = 0; i < NUM_DIGITOS; i++) {
        cout << k[i];
    }
    cout << endl;
}


/*
 * Programa que realiza pruebas de las funciones «numPositivos», «copiar»,
 * «sonIguales», «moda», «esta», «estaOrdenada», «copiaPositivos» y «kolakoski».
 */
int main() {
    pruebaNumPositivos();
    pruebaCopiar();
    pruebaSonIguales();
    pruebaModa();
    pruebaEsta();
    pruebaEstaOrdenada();
    pruebaCopiaPositivos();
    pruebaKolakoski();
    return 0;
}
