#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "empleado.h"
#include "infoEmpleado.h"


void informesEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec){

    char seguir = 's';
    char confirma;
    do{
        switch(menuInforme())
        {
            case 'a':
                listarEmpleadosXAnio(vec, tam, sectores, tamsec);
                break;
            case 'b':
                listarEmpleadas(vec, tam, sectores, tamsec);
                break;
            case 'c':
                informarTotalSueldos(vec, tam);
                break;
            case 'd':
                informarEmpleadosDeSector(vec, tam, sectores, tamsec);
                break;
            case 'e':
                informarEmpleadosXSector(vec, tam, sectores, tamsec);
                break;
            case 'f':
                informarMayorSueldoSector(vec, tam, sectores, tamsec);
                break;
            case 'g':
                informarEmpleadoCostosoSector(vec, tam, sectores, tamsec);
                break;
            case 'h':
                aumentarSueldoSector(vec, tam, sectores, tamsec);
                break;
            case 'i':
                informarSectorCostoso(vec, tam, sectores, tamsec);
                break;
            case 'j':
                informeTotalSueldosSector(vec, tam, sectores, tamsec);
                break;
            case 'k':
                informeCantEmpleadosSector(vec, tam, sectores, tamsec);
                break;
            case 'l':
                informeEmpleadoMasJovenSector(vec, tam, sectores, tamsec);
                break;
            case 'x':
                printf("\nConfirma salida? s/n \n");
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

}

void listarEmpleadosXAnio(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int flag = 0;
    int anio;

    system("clear");
    printf("***** LISTADO DE EMPLEADOS POR AÑO *****\n\n");
    printf("Ingrese el año que desea listar: \n");
    scanf("%d", &anio);


    printf("\n ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector\n\n");

    for(int i = 0; i < tam; i++){
        if(vec[i].fechaIngreso.anio == anio && vec[i].isEmpty == 0){

            mostrarEmpleado(vec[i], sectores, tamsec);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("\nNo se encontraron empleados con ese año \n");
    }



}

void listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int flag = 0;

    system("clear");
    printf("***** LISTADO DE EMPLEADAS *****\n\n");

    printf("\n ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector\n\n");

    for(int i = 0; i < tam; i++){
        if(vec[i].sexo == 'f' && vec[i].isEmpty == 0){
            mostrarEmpleado(vec[i], sectores, tamsec);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("\nNo se encontraron empleadas \n");
    }



}

void informarTotalSueldos(eEmpleado vec[], int tam){
    float acumulador = 0;
    system("clear");

    for(int i = 0; i < tam; i++){
        if(vec[i].isEmpty == 0){
            acumulador += vec[i].sueldo;
        }
    }

    printf("***** TOTAL DE SUELDOS *****\n\n");
    printf("El total de los sueldos acumulados es $ %.2f", acumulador);

}

char menuInforme(){

    char retorno;

    system("clear");

    printf("***** INFORME EMPLEADOS ***** \n");

    printf("A- Listar empleados por año \n");
    printf("B- Listar empleadas \n");
    printf("C- Total de sueldos \n");
    printf("D- Informar empleados de sector: \n");
    printf("E- Informar empleados de cada sector:\n");
    printf("F- Informar mayor sueldos:  \n ");
    printf("G- Informar empleados de mayor sueldo:\n");
    printf("H- Aumentar sueldo de sector: \n ");
    printf("I- Sector de mayor gasto en sueldos: \n ");
    printf("J- Informe total de sueldos por sector: \n" );
    printf("K- Cantidad de empleados por sector: \n");
    printf("L- Informar empleado mas joven del sector: \n");
    printf("X- SALIR \n \n ");

    __fpurge(stdin);
    scanf("%c", &retorno);

    return retorno;
}

void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int auxSector;
    int flag = 0;
    char nombreSector[20];

    system("clear");
    printf("***** Empleados de sector ***** \n\n");

    listarSectores(sectores, tamsec);

    printf("Ingrese sector: ");
    scanf("%d", &auxSector);

    cargarDescripcionSector(nombreSector, auxSector, sectores, tamsec);

    system("clear");

    printf("***** Empleados del sector%10s *****\n\n", nombreSector);
    printf("\n ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector\n\n");

    for(int i = 0; i < tam; i++){
        if(vec[i].idSector == auxSector && vec[i].isEmpty == 0){
            mostrarEmpleado(vec[i], sectores, tamsec);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("\nNo hay empleados\n");
    }
}

void informarEmpleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int flag = 0;
    system("clear");
    printf("***** Empleados por sector ***** \n");

    for(int s = 0; s < tamsec; s++){
        flag = 0;
        printf("\nSector %s\n", sectores[s].descripcion);
        printf("\n ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector\n\n");

        for(int e = 0; e < tam; e++){
            if(vec[e].idSector == sectores[s].id && vec[e].isEmpty == 0){
                mostrarEmpleado(vec[e], sectores, tamsec);
                flag = 1;
            }
        }

        if(flag == 0){
            printf("\nNo hay empleados\n");
        }
        printf("\n---------------------------------------------------\n");
    }
}

void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int auxSector;
    float auxMayor = 0;
    int flag = 0;
    char nombreSector[20];

    system("clear");
    printf("***** Mayor sueldo del sector ***** \n\n");

    listarSectores(sectores, tamsec);

    printf("Ingrese sector: ");
    scanf("%d", &auxSector);

    cargarDescripcionSector(nombreSector, auxSector, sectores, tamsec);


    for(int e = 0; e < tam; e++){
        if(vec[e].idSector == auxSector && vec[e].isEmpty == 0){
            if(vec[e].sueldo > auxMayor || flag == 0){
                auxMayor = vec[e].sueldo;
                flag = 1;
            }
        }
    }

    printf("***** El sueldo mayor del sector %10s es $ %.2f *****\n\n", nombreSector, auxMayor);

}

void informarEmpleadoCostosoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int auxSector;
    int flag = 0;
    float mayorSueldo = 0;
    char nombreSector[20];

    system("clear");
    printf("***** Empleados costosos del sector ***** \n\n");

    listarSectores(sectores, tamsec);

    printf("Ingrese sector: ");
    scanf("%d", &auxSector);

    cargarDescripcionSector(nombreSector, auxSector, sectores, tamsec);

    system("clear");



    for(int i = 0; i < tam; i++){
        if(vec[i].idSector == auxSector && vec[i].isEmpty == 0){
            if(flag == 0 || vec[i].sueldo > mayorSueldo){
                mayorSueldo = vec[i].sueldo;
                flag = 1;
            }
        }
    }

    if(flag){

        printf("***** El mayor sueldo del sector %10s es $ %.2f y lo cobran: *****\n\n", nombreSector, mayorSueldo);
        printf("\n ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector\n\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].idSector == auxSector && vec[i].isEmpty == 0 && vec[i].sueldo == mayorSueldo){
               mostrarEmpleado(vec[i], sectores, tamsec);
            }
        }
    }else{
        printf("No hay empleados en el sector %10s \n", nombreSector);
    }

}

void aumentarSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int auxSector;
    int porcentaje;
    int flagcita = 0;

    system("clear");
    printf("***** Aumentar sueldo del sector ***** \n\n");

    listarSectores(sectores, tamsec);

    printf("Ingrese sector: ");
    scanf("%d", &auxSector);

    printf("Ingrese porcentaje a aumentar: ");
    scanf("%d", &porcentaje);

    system("clear");

    for(int i = 0 ; i < tam ; i++){
        if(vec[i].idSector == auxSector && vec[i].isEmpty == 0){
            vec[i].sueldo += (float) (porcentaje * vec[i].sueldo) / 100;
            flagcita = 1;
        }
    }
    if(flagcita){
        printf("Aumento realizado con exito.");
    }else{
        printf("No hay empleados en ese sector.");
    }
}

float obtenerTotalSueldosSector(int idSector, eEmpleado vec[], int tam){
    float retorno = 0;
    for(int i = 0; i < tam ; i++){
        if(vec[i].idSector == idSector && vec[i].isEmpty == 0){
            retorno += vec[i].sueldo;
        }
    }
    return retorno;
}

void informarSectorCostoso(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    float sueldosCostosos[tamsec];
    float mayorTotal;
    int flag = 0;

    system("clear");
    printf("***** Los sectores mas costosos son ***** \n\n");

    for(int i = 0 ; i < tamsec ; i++){
        sueldosCostosos[i] = obtenerTotalSueldosSector(sectores[i].id, vec, tam);
    }

    for(int i = 0; i < tamsec ; i++){
        if(sueldosCostosos[i] > mayorTotal || flag == 0){
            mayorTotal = sueldosCostosos[i];
            flag = 1;
        }
    }

    printf("El mayor gasto en sueldos es $ %.2f y se realiza en el sector", mayorTotal);

    for(int i = 0 ; i < tamsec ; i++){
        if(sueldosCostosos[i] == mayorTotal){
            printf("%10s ", sectores[i].descripcion);
        }
    }
    printf("\n\n");
}

void informeTotalSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int idSector;
    float total;
    char nombreSector[20];
    system("clear");

    listarSectores(sectores, tamsec);
    printf("Ingrese sector: ");
    scanf("%d", &idSector);

    total = obtenerTotalSueldosSector(idSector, vec, tam);
    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);

    printf("El informe total de sueldos del sector %s es $%.2f \n", nombreSector, total);

}

void informeCantEmpleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int cantEmp = 0;
    system("clear");
    printf("***** Cantidad de empleados por sector *****\n\n");

    for(int i = 0 ; i < tamsec ; i++){
        for(int s = 0; s < tam ; s++){
            if(vec[s].idSector == sectores[i].id && vec[s].isEmpty == 0){
                cantEmp++;
            }
        }
        printf("En el sector %s hay %d empleados.\n", sectores[i].descripcion, cantEmp);
        cantEmp = 0;
    }

}

void informeEmpleadoMasJovenSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
     int auxSector;
    int flag = 0;
    int menorEdad = 0;
    char nombreSector[20];

    system("clear");
    printf("***** Empleado mas joven del sector ***** \n\n");

    listarSectores(sectores, tamsec);

    printf("Ingrese sector: ");
    scanf("%d", &auxSector);

    cargarDescripcionSector(nombreSector, auxSector, sectores, tamsec);

    system("clear");

    for(int i = 0; i < tam; i++){
        if(vec[i].idSector == auxSector && vec[i].isEmpty == 0){
            if(flag == 0 || vec[i].edad < menorEdad){
                menorEdad = vec[i].edad;
                flag = 1;
            }
        }
    }

    if(flag){

        printf("***** Los empleados mas jovenes del sector tienen %d anios y son *****\n\n", menorEdad);
        printf("\n ID      Nombre    Sexo    Edad    Sueldo     Fecha ingreso          Sector\n\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].edad == menorEdad  && vec[i].isEmpty == 0){
               mostrarEmpleado(vec[i], sectores, tamsec);
            }
        }
    }else{
        printf("No hay empleados en el sector %10s \n", nombreSector);
    }

}
