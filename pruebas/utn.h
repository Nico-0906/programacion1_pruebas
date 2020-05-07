#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


#endif // UTN_H_INCLUDED

/** \brief formatea la cadena de caracteres para que quede la primer letra mayuscula y el resto en minuscula
*
* \param vector de cadena que se quiere formatear
* \param tamaño del vector de cadena
*/

void tipoNombre(char vec[], int tam);

/** \brief pide una cadena de caracteres como fgets pero sin el '\n' anterior al '\0'
*
* \param puntero a la direccion de memoria donde se desea guardar la cadena de caracteres
*/

void getStr(char cadena[], int tam);

/** \brief calcula el promedio de los enteros dentro de un vector
*
* \param vector de enteros que se desea calcular
* \param tamaño del vector de enteros
*/

float calcularPromedio(int vec[], int tam);

/** \brief pide un entero dentro de un rango indicado enviando un mensaje, un mensaje de error y teniendo una cierta cantidad de intentos
*
* \param puntero a la variable de entero donde se desea guardar el entero pedido
* \param mensaje a enviar para pedir el entero
* \param mensaje de error en caso de no colocar un entero que este en el rango indicado
* \param limite inferior de enteros a pedir
* \param limite superior de enteros a pedir
* \param cantidad de intentos que tiene el usuario para colocar mal el entero
* \return retorna 1 si tuvo exito o 0 si supero la cantidad de intentos permitida
*/

int pedirEnteroRango(int* pNum, char mensaje[], char mensajeError[], int limiteInf, int limiteSup, int intentos);

/** \brief realiza un printf del vector de enteros indicado
*
* \param vector de enteros que se desea mostrar
* \param tamaño del vector
*/

void mostrarVectorInt(int vec[], int tam);

/** \brief ordena un vector de enteros
*
* \param vector que se desea ordenar
* \param tamaño del vector que se desea ordenar
* \param orden con que se desea ordenar 0 de menor a mayor o 1 de mayor a menor
*/

void ordenarEnteros(int vec[], int tam, int orden); // con 1 de menor a mayor, con 0 de mayor a menor

/** \brief ordena los caracteres de un vector segun el orden que se le indique
*
* \param vector que se desea ordenar
* \param tamaño del vector
* \param orden con el que se desea ordenar 0 es de menor a mayor y 1 de mayor a menor
*/

void ordenarCaracteres(char vec[], int tam, int orden);

/** \brief pasa toda una cadena de caracteres a minuscula
*
* \param la cadena de caracteres que se quiere pasar
*/

void strlwrLinux(char cadena[]);

/** \brief suma dos enteros
*
* \param primer entero a sumar
* \param segundo entero a sumar
* \return retorna el resultado de la suma
*/

int suma(int a, int b);

/** \brief resta dos enteros
*
* \param primer entero a restar
* \param segundo entero a restar
* \return retorna el resultado de la resta
*/

int resta(int a, int b);

/** \brief multiplica dos enteros
*
* \param primer entero a multiplicar
* \param segundo entero a multiplicar
* \return retorna el resultado de la multiplicacion
*/

int multiplica(int a, int b);

/** \brief divide dos enteros
*
* \param primer entero dividendo
* \param segundo entero divisor
* \return retorna el resultado de la division
*/

float divide(int a, int b);

/** \brief calcula el factorial de un entero
*
* \param entero a factorizar
* \return retorna el factorial del numero ingresado
*/

int factorial(int a);

