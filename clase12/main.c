#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "empleado.h"
#include "sector.h"
#include "infoEmpleado.h"


#define TAM 10
#define TAMSEC 5
#define CANTHARDCODE 9


int main()
{

    char seguir = 's';
    char confirma;
    int proximoId = 1000;

    eEmpleado lista[TAM];
    eSector sectores[TAMSEC] = {{1, "Sistemas"},{2, "RRHH"},{3, "Compras"},{4, "Ventas"},{5, "Contable"}};


    inicializarEmpleado(lista, TAM);


    hardcodearEmpleados(lista, CANTHARDCODE);
    proximoId += CANTHARDCODE;


    do{
        switch(menu())
        {
            case 1:
                printf("Alta\n");
                if(altaEmpleado(proximoId, lista, TAM, sectores, TAMSEC)){
                    proximoId++;
                }
                break;
            case 2:
                printf("Modificar\n");
                modificarEmpleado(lista, TAM, sectores, TAMSEC);
                break;
            case 3:
                printf("Baja\n");
                bajaEmpleado(lista, TAM, sectores, TAMSEC);
                break;
            case 4:
                printf("Ordenar\n");
                break;
            case 5:
                printf("Listar\n");
                mostrarEmpleados(lista, TAM, sectores, TAMSEC);
                break;
            case 6:
                printf("Informes\n");
                informesEmpleados(lista, TAM, sectores, TAMSEC);
                break;
            case 7:
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

    return 0;
}

