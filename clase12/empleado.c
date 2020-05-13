#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "empleado.h"
#include "dataWerehouse.h"



void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamsec){
    char descripcion[20];

    cargarDescripcionSector(descripcion , emp.idSector, sectores, tamsec);

    printf("%4d   %10s    %c      %2d    %10.2f     %02d/%02d/%4d       %10s \n", emp.id, emp.nombre, emp.sexo, emp.edad, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, descripcion);
}

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamsec){

    system("clear");
    printf("            ******* LISTADO DE EMPLEADOS *******\n");
    printf(" ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector \n\n");

    int flag = 0;
    for(int i = 0 ; i < tam ; i++){
        if(lista[i].isEmpty == 0){
            mostrarEmpleado(lista[i], sectores, tamsec);
            flag = 1;
        }
    }
    if(flag == 0){
            printf("No hay empleados que mostrar. \n");
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam){

    eEmpleado empAuxiliar;

    for(int i = 0 ; i < tam - 1; i++){
        for(int j = i + 1; j < tam; j++){
            if(vec[i].sexo < vec[j].sexo){
                 empAuxiliar = vec[i];
                 vec[i] = vec[j];
                 vec[j] = empAuxiliar;
            }else if(vec[i].sueldo > vec[j].sueldo && vec[i].sexo == vec[j].sexo){
                empAuxiliar = vec[i];
                 vec[i] = vec[j];
                 vec[j] = empAuxiliar;
            }
        }
    }

}

int compararFechas(eFecha fecha1, eFecha fecha2){
    int retorno = 0;

    if(fecha1.anio > fecha2.anio){
        retorno = 1;
    }else if(fecha1.anio < fecha2.anio){
        retorno = -1;
    }else if(fecha1.mes > fecha2.mes){
        retorno = 1;
    }else if(fecha1.mes < fecha2.mes){
        retorno = -1;
    }else if(fecha1.dia > fecha2.dia){
        retorno = 1;
    }else if(fecha1.dia < fecha2.dia){
        retorno = -1;
    }


    return retorno;
}

void inicializarEmpleado(eEmpleado vec[], int tam){
     for(int i = 0 ; i < tam ; i++){
        vec[i].isEmpty = 1;
     }
}

int buscarLibre(eEmpleado vec[], int tam){
    int posicion = -1;
        for(int i = 0 ; i < tam ; i++){
            if(vec[i].isEmpty == 1){
                posicion = i;
                break;
            }
        }
    return posicion;
}

int buscarEmpleado(int id, eEmpleado vec[], int tam){
    int retorno = -1;
    for(int i = 0 ; i < tam ; i++){
        if(vec[i].id == id && vec[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }

    return retorno;
}

int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int retorno = 0;

    system("clear");

    printf("****** ALTA EMPLEADO ******\n\n");

    int lugar;
    eEmpleado auxEmpleado;

    lugar = buscarLibre(vec, tam);

    if(lugar == -1){

    printf("\nNo hay lugar sistema completo. \n\n");

    }else{

    auxEmpleado.id = idx;

    printf("Ingrese nombre: \n");
    __fpurge(stdin);
    gets(auxEmpleado.nombre);

    printf("Ingrese sexo: \n");
    scanf("%c", &auxEmpleado.sexo);

    printf("Ingrese edad: \n");
    scanf("%d", &auxEmpleado.edad);

    printf("Ingrese sueldo: \n");
    scanf("%f", &auxEmpleado.sueldo);

    printf("Ingrese fecha de ingreso: dd/mm/aaaa  \n");
    scanf("%d/%d/%d", &auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes, &auxEmpleado.fechaIngreso.anio);

    listarSectores(sectores, tamsec);

    printf("Ingrese secor: \n");
    scanf("%d", &auxEmpleado.idSector);

    printf("\nEmpleado agregado con exito.!");

    auxEmpleado.isEmpty = 0;

    vec[lugar] = auxEmpleado;

    retorno = 1;
    }

    return retorno;
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec){

    system("clear");

    int auxId;
    int busqueda;
    char confirmacion;

    printf("***** BAJA DE EMPLEADO ***** \n\n");

    printf("Ingrese ID de empleado: \n");
    scanf("%d", &auxId);

    busqueda = buscarEmpleado(auxId, vec, tam);

    if(busqueda != -1){
        mostrarEmpleado(vec[busqueda], sectores, tamsec);
        printf("\nDesea confirmar la baja? s/n \n\n");
        __fpurge(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion == 's'){
            vec[busqueda].isEmpty = 1;
            printf("\nDado de baja con exito.! \n\n");
        }else{
            printf("\nOperacion cancelada. \n\n");
        }
    }else{
        printf("\nEmpleado no encontrado. \n\n");
    }
}

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    system("clear");
    int auxId;
    int busqueda;
    char confirmacion;
    char auxChar;
    float auxSueldo;
    char auxNombre[20];
    eFecha auxFecha;
    int opcion;

    printf("***** MODIFICAR EMPLEADO ***** \n\n");

    printf("Ingrese ID de empleado: \n");
    scanf("%d", &auxId);

    busqueda = buscarEmpleado(auxId, vec, tam);

    if(busqueda != -1){
        mostrarEmpleado(vec[busqueda], sectores, tamsec);

        printf("Que desea modificar: \n\n1- Nombre\n 2- Sexo\n 3- Edad \n 4- Sueldo \n 5- Fecha de ingreso\n 6- Cancelar \n\n");


        scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Ingrese nuevo nombre: \n");
            __fpurge(stdin);
            gets(auxNombre);

            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                strcpy(vec[busqueda].nombre, auxNombre);
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 2:
            printf("Ingrese nuevo sexo: \n");
            scanf("%c", &auxChar);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                vec[busqueda].sexo = auxChar;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 3:
            printf("Ingrese nueva edad: \n");
            scanf("%d", &auxId);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                vec[busqueda].edad = auxId;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 4:
            printf("Ingrese nuevo sueldo: \n");
            scanf("%f", &auxSueldo);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                vec[busqueda].sueldo = auxSueldo;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 5:
            printf("Ingrese nueva fecha de ingreso: dd/mm/aaaa \n");
            scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                vec[busqueda].fechaIngreso = auxFecha;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        default:
            break;
    }

    }else{
        printf("\nEmpleado no encontrado. \n\n");
    }
}

void hardcodearEmpleados(eEmpleado vec[], int cantidadEmpleados){

    for(int i = 0 ; i < cantidadEmpleados ; i++){
        vec[i].id = ids[i];
        strcpy(vec[i].nombre, nombres[i]);
        vec[i].sexo = sexos[i];
        vec[i].edad = edades[i];
        vec[i].sueldo = sueldos[i];
        vec[i].fechaIngreso.dia = dias[i];
        vec[i].fechaIngreso.mes = meses[i];
        vec[i].fechaIngreso.anio = anios[i];
        vec[i].isEmpty = 0;
        vec[i].idSector = idsSector[i];

    }
}

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tamsec){
    int retorno = 0;
    for(int i = 0 ; i < tamsec ; i++){
        if(sectores[i].id == id){
            strcpy(descripcion, sectores[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;

}

int menu(){
    int retorno;
    system("clear");
    printf("\n***** GESTION DE EMPLEADOS *****\n\n");
    printf("1- Alta empleado \n ");
    printf("2- Modificar empleado\n ");
    printf("3- Baja empleado\n ");
    printf("4- Ordenar empleados\n ");
    printf("5- Listar empleados\n ");
    printf("6- Informes\n ");
    printf("7- Mostrar almuerzos\n ");
    printf("8- Alta almuerzo\n ");
    printf("9- Nada\n ");
    printf("10- Salir\n ");
    printf("Ingrese opcion:  ");
    __fpurge(stdin);

    scanf("%d", &retorno);

    return retorno;
}

int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleado[], int tam){
    int retorno = 0;
    for(int i = 0; i < tam; i++){
        if(empleado[i].id == id){
            strcpy(nombre, empleado[i].nombre);
            retorno = 1;
        }
    }
    return retorno;
}
