#ifndef CLAS9_H_INCLUDED
#define CLAS9_H_INCLUDED

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

}eEmpleado;

#endif // CLAS9_H_INCLUDED

int compararFechas(eFecha fecha1, eFecha fecha2);

void mostrarEmpleado(eEmpleado emp);

void mostrarEmpleados(eEmpleado lista[], int tam);

void ordenarEmpleados(eEmpleado vec[], int tam);
