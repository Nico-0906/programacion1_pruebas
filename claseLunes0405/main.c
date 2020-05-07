#include <stdio.h>
#include <stdlib.h>
#include "DATAWEREHOUSE.H"

#define TAM 10
#define CANTHARDCODE 5


typedef struct{
    int dia[];
    int mes[];
    int anio[];
}eFecha;

typedef struct{
    char nombre[20];



}eEmpleado

int altaEmpleado(int idx, eEmpleado vec[], int tam);

int buscarEmpleado(int id, eEmpleado vec[], int tam);

void hardcodearEmpleados(eEmpleado vec[], int cant);

int menu();

int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    eEmpleado lista[TAM];

    inicializarEmpleados(lista, TAM);  //aca estariamos probando la funcion

    hardcodearEmpleados(lista, CANTHARDCODE);
    proximoId += CANTHARDCODE; //esto seria para que se asignen los ID hardcodeados


    do{
        switch(menu()){
        case 1:
            if(altaEmpleado(proximoId, lista, TAM)){
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(lista, TAM);
            break;
        case 3:
            bajaEmpleado();
            break;
        case 4:
            printf("");
            break;
        case 5:



        }


    }

    return 0;
}

int altaEmpleado(int idx, eEmpleado vec[], int tam){
    int todoOk = 0;

    int indice = buscarLibre(vec, tam);

    int existe;



    return todoOk;
}


int buscarEmpleado(int id, eEmpleado vec[], int tam){
    int indice = -1;

    for(int i = 0; i < tam ; i++){
        if(vec[i].id == id && vec[i].isEmpty == 0){
            indice = i;
            break;
        }
    }

}

void hardcodearEmpleados(eEmpleado vec[], int cant){    //esto serviria para cargar de nuestra almacen de datos "el datawerehouse" para hardcodear y probar
    for(int i = 0; i < cant ; i++){
        vec[i].id = ids[i];
        strcpy(vec.[i].nombre, nombres[i]);
        vec[i].sexo = sexos[i];
        vec[i].edad = edades[i];
        vec[i].sueldo = sueldos[i];
        vec[i].fechaIngreso.dia = dias[i];
        vec[i].fechaIngreso.mes = meses[i];
        vec[i].fechaIngreso.anio = anios[i];
        vec[i].isEmpty = 0;
    }

}
