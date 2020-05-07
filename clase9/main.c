#include <stdio.h>
#include <stdlib.h>

#include <stdio_ext.h>

#include "clas9.h"

#define TAM 5


int main()
{
    eEmpleado lista[TAM] = {
                            {1234, "Nicolas", 'm', 27, 35000.60, {9, 7, 2010}},
                            {1233, "Fabiana", 'f', 25, 35000.32,{5, 2, 2012}},
                            {1322, "Daniel", 'm', 24, 40000.30, {6, 4, 2010}},
                            {1111, "Emanuel", 'f', 30, 82934.32,{10, 11, 2020}},
                            {1233, "Natalia", 'f', 24, 40000.32,{7, 4, 2019}}
                            };  //asi se declararia una variable con el nuevo tipo

   // eEmpleado otroEmpleado; // = {1243, "Macarena", 'f', 26, 30000.50};

   /*
   for(int i = 0; i < TAM ; i++){
    printf("Ingrese ID: \n");
    scanf("%d", &lista[i].id);

    printf("Ingrese su nombre \n");
    __fpurge(stdin);
    gets(lista[i].nombre);

    printf("Ingrese sexo: \n");
    __fpurge(stdin);
    scanf("%c", &lista[i].sexo);

    printf("Ingrese su edad \n");
    scanf("%d", &lista[i].edad);

    printf("Ingrese sueldo \n");
    scanf("%f", &lista[i].sueldo);

    printf("Ingrese fecha de ingreso: dd/mm/aaaa\n");
    scanf("%d/%d/%d", &lista[i].fechaIngreso.dia, &lista[i].fechaIngreso.mes, &lista[i].fechaIngreso.anio);

    }
    */

    mostrarEmpleados(lista, TAM);

    ordenarEmpleados(lista, TAM);

    mostrarEmpleados(lista, TAM);

    return 0;
}
