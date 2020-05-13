#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "empleado.h"
#include "sector.h"
#include "infoEmpleado.h"
#include "comida.h"
#include "almuerzo.h"


#define TAM 10
#define TAMSEC 5
#define CANTHARDCODE 9
#define TAMC 5
#define TAMA 100

int main()
{

    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    int proximoIdAlmuerzo = 20000;
    eEmpleado lista[TAM];
    eSector sectores[TAMSEC] = {{1, "Sistemas"},{2, "RRHH"},{3, "Compras"},{4, "Ventas"},{5, "Contable"}};
    eComida comidas[TAMC] = { {100, "Milanesa", 150}, {101, "Ensalada", 170}, {102, "Fideos", 120}, {103, "Sopa", 110}, {104, "Panchos", 100}};
    eAlmuerzo almuerzos[TAMA];

    inicializarAlmuerzo(almuerzos, TAMA);
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
                printf("Mostrar almuerzos\n");
                mostrarAlmuerzos(almuerzos, TAMA, lista, TAM, comidas, TAMC);
                break;
            case 8:
                printf("Alta almuerzos \n");
                if(altaAlmuerzo(proximoIdAlmuerzo, almuerzos, TAMA, lista, TAM, sectores, TAMSEC, comidas, TAMC)){
                    proximoIdAlmuerzo++;
                }
                break;
            case 9:
                printf("NADA\n");
                break;
            case 10:
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

