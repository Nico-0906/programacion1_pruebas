#include "empleado.h"
#include "comida.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int id;
    int idComida;
    int idEmpleado;
    eFecha fecha;
    int isEmpty;

}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzo(eAlmuerzo almuerzo[], int tam);
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado empleados[], int tamemp, eComida comidas[], int tamcom);
int mostrarAlmuerzos(eAlmuerzo almuerzo[], int tamal, eEmpleado empleados[], int tamemp, eComida comidas[], int tamcom);
int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam);
int altaAlmuerzo(int id, eAlmuerzo almuerzo[], int tamal, eEmpleado empleados[], int tamemp, eSector sectores[], int tamsec, eComida comidas[], int tamcom);
