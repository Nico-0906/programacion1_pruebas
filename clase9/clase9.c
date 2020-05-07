#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>


#include "clas9.h"

void mostrarEmpleado(eEmpleado emp){
    printf("%4d   %10s    %c      %2d    %5.2f     %02d/%02d/%4d \n", emp.id, emp.nombre, emp.sexo, emp.edad, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);
}


void mostrarEmpleados(eEmpleado lista[], int tam){
    printf("            ******* LISTADO DE EMPLEADOS *******\n");
    printf(" ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso\n");
    for(int i = 0 ; i < tam ; i++){
    mostrarEmpleado(lista[i]);
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam){

    eEmpleado empAuxiliar;

    for(int i = 0 ; i < tam - 1; i++){
        for(int j = i + 1; j < tam; j++){
            if(vec[i].sexo < vec[j].sexo    ){
                 empAuxiliar = vec[i];
                 vec[i] = vec[j];
                 vec[j] = empAuxiliar;
            }else if(vec[i].sueldo < vec[j].sueldo && vec[i].sexo == vec[j].sexo){
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

