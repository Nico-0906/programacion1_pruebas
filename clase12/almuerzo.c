#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "empleado.h"
#include "comida.h"
#include "almuerzo.h"


void inicializarAlmuerzo(eAlmuerzo almuerzo[], int tam){
    for(int i = 0; i < tam ; i++){
        almuerzo[i].isEmpty = 1;
    }

}
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado empleados[], int tamemp, eComida comidas[], int tamcom){
    char nombreEmpleado[20];
    char nombreComida[20];


    cargarNombreEmpleado(nombreEmpleado, almuerzo.idEmpleado, empleados, tamemp);
    cargarDescripcionComida(nombreComida, almuerzo.idComida, comidas, tamcom);

    printf("%d     %d    %10s    %10s    %02d/%02d/%4d \n", almuerzo.id, almuerzo.idEmpleado, nombreEmpleado, nombreComida, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);

}
int mostrarAlmuerzos(eAlmuerzo almuerzo[],int tamal, eEmpleado empleados[], int tamemp, eComida comidas[], int tamcom){
    int retorno = 0;
    system("clear");
    printf("***** Listado de almuerzos *****\n\n");
    printf("ID     IdEmpleado      Nombre      Comida      Fecha \n\n");

    for(int i = 0; i < tamal ; i++){
        if(almuerzo[i].isEmpty == 0){
            mostrarAlmuerzo(almuerzo[i], empleados, tamemp, comidas, tamcom);
            retorno = 1;
        }
    }
    if(retorno == 0){
        printf("No hay almuerzos cargados. \n");
    }
    printf("\n\n");
    return retorno;
}
int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam){
    int posicion = -1;
        for(int i = 0 ; i < tam ; i++){
            if(almuerzos[i].isEmpty == 1){
                posicion = i;
                break;
            }
        }
    return posicion;
}
int altaAlmuerzo(int id, eAlmuerzo almuerzo[], int tamal, eEmpleado empleados[], int tamemp, eSector sectores[], int tamsec, eComida comidas[], int tamcom){
    int retorno = 0;
    int indice;
    eAlmuerzo nuevoAlmuerzo;

    system("clear");
    printf("***** Alta almuerzo *****\n\n");

    indice = buscarLibreAlmuerzo(almuerzo, tamal);

    if(indice == -1){
        printf("No hay lugar para otro almuerzo. \n");
    }else{
        mostrarEmpleados(empleados, tamemp, sectores, tamsec);
        printf("Ingrese ID empleado: ");
        scanf("%d", &nuevoAlmuerzo.idEmpleado);

        mostrarComidas(comidas, tamcom);
        printf("\nIngrese ID comida: ");
        scanf("%d", &nuevoAlmuerzo.idComida);

        printf("\nIngrese fecha: ");
        scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

        nuevoAlmuerzo.isEmpty = 0;
        nuevoAlmuerzo.id = id;

        almuerzo[indice] = nuevoAlmuerzo;
        retorno = 1;
        printf("\nAlmuerzo agregado con exito.\n");

    }

    return retorno;
}
