#include "sector.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;            //campos de una estructura
    eFecha fechaIngreso;
    int isEmpty; //0 tiene datos y 1 es vacio
    int idSector;

}eEmpleado;

#endif // EMPLEADO_H_INCLUDED

int compararFechas(eFecha fecha1, eFecha fecha2);

void hardcodearEmpleados(eEmpleado vec[], int cantidadEmpleados);

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamsec);

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamsec);

void ordenarEmpleados(eEmpleado vec[], int tam);

void inicializarEmpleado(eEmpleado vec[], int tam);

int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[], int tamsec);

int buscarLibre(eEmpleado vec[], int tam);

int buscarEmpleado(int id, eEmpleado vec[], int tam);

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tamsec);

int menu();

int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleado[], int tam);
