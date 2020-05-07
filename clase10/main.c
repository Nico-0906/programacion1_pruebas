#include <stdio.h>
#include <stdlib.h>

#include <stdio_ext.h>

#define TAM 2

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

}eEmpleado;

int compararFechas(eFecha fecha1, eFecha fecha2);

void mostrarEmpleado(eEmpleado emp);

void mostrarEmpleados(eEmpleado lista[], int tam);

void ordenarEmpleados(eEmpleado vec[], int tam);

void inicializarEmpleado(eEmpleado vec[], int tam);

void altaEmpleado(eEmpleado vec[], int tam);

int buscarLibre(eEmpleado vec[], int tam);

int buscarEmpleado(int id, eEmpleado vec[], int tam);

void bajaEmpleado(eEmpleado vec[], int tam);

int menu();

int main()
{
    char seguir = 's';
    char confirma;

    eEmpleado lista[TAM]; /* = {
                            {1234, "Nicolas", 'm', 27, 35000.60, {9, 7, 2010}},
                            {1233, "Fabiana", 'f', 25, 35000.32,{5, 2, 2012}},
                            {1322, "Daniel", 'm', 24, 40000.30, {6, 4, 2010}},
                            {1111, "Emanuel", 'f', 30, 82934.32,{10, 11, 2020}},
                            {1233, "Natalia", 'f', 24, 40000.32,{7, 4, 2019}}
                            };
                          */

    inicializarEmpleado(lista, TAM);

    do{
        switch(menu())
        {
            case 1:
                printf("Alta\n");
                altaEmpleado(lista, TAM);
                break;
            case 2:
                printf("Modificar\n");
                break;
            case 3:
                printf("Baja\n");
                bajaEmpleado(lista, TAM);
                break;
            case 4:
                printf("Ordenar\n");
                break;
            case 5:
                printf("Listar\n");
                mostrarEmpleados(lista, TAM);
                break;
            case 6:
                printf("Informes\n");
                break;
            case 7:
                printf("Confirma salida? s/n \n");
                __fpurge(stdin);
                scanf("%c", &confirma);
                if(confirma == 's'){
                    seguir = 'n';
                }
                break;
        }

        __fpurge(stdin);
        getchar();

    }while(seguir == 's');
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

    //ordenarEmpleados(lista, TAM);

    //mostrarEmpleados(lista, TAM);

    return 0;
}
void mostrarEmpleado(eEmpleado emp){
    printf("%4d   %10s    %c      %2d    %5.2f     %02d/%02d/%4d \n", emp.id, emp.nombre, emp.sexo, emp.edad, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);
}


void mostrarEmpleados(eEmpleado lista[], int tam){
    printf("            ******* LISTADO DE EMPLEADOS *******\n");
    printf(" ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso\n\n");

    int flag = 0;
    for(int i = 0 ; i < tam ; i++){
        if(lista[i].isEmpty == 0){
            mostrarEmpleado(lista[i]);
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

int menu(){
    int retorno;
    system("clear");
    printf("\n***** GESTION DE EMPLEADOS *****\n");
    printf("1- Alta empleado \n 2- Modificar empleado\n 3- Baja empleado\n 4- Ordenar empleados\n 5- Listar empleados\n 6- Informes\n 7- Salir\n Ingrese opcion:  ");
    __fpurge(stdin);

    scanf("%d", &retorno);

    return retorno;
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

void altaEmpleado(eEmpleado vec[], int tam){

    system("clear");

    printf("****** ALTA EMPLEADO ******\n");

    int lugar;
    eEmpleado auxEmpleado;

    lugar = buscarLibre(vec, tam);

    if(lugar == -1){

    printf("No hay lugar sistema completo. \n");

    }else{

    int busqueda;
    int auxId;

    printf("Ingrese ID: \n");
    scanf("%d", &auxId);

    busqueda = buscarEmpleado(auxId, vec, tam);

    if(busqueda != -1){

        printf("Ya existe un empleado con ese ID. \n");

    }else{

    auxEmpleado.id = auxId;

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

    printf("Empleado agregado con exito.!");

    auxEmpleado.isEmpty = 0;

    vec[lugar] = auxEmpleado;
    }
    }

}


void bajaEmpleado(eEmpleado vec[], int tam){

    system("clear");

    int auxId;
    int busqueda;
    char confirmacion;

    printf("***** BAJA DE EMPLEADO ***** \n");

    printf("Ingrese ID de empleado: \n");
    scanf("%d", &auxId);

    busqueda = buscarEmpleado(auxId, vec, tam);

    if(busqueda != -1){
        //mostrarEmpleado(vec);
        printf("Desea confirmar la baja? s/n\n");
        scanf("%c", &confirmacion);

        if(confirmacion == 's'){
            vec.isEmpty = 1;
            printf("Dado de baja con exito.! \n");
        }else if(confirmacion == 'n'){
            break;
        }
    }else{
        printf("Empleado no encontrado. \n");
        break;
    }
}

//      1627680EXCGXL81901

