#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "sector.h"


void listarSectores(eSector sectores[], int tamsec){
    system("clear");
    printf("***** Listado de sectores ***** \n\n");
    printf("ID      Sector\n\n");

    for(int i = 0; i < tamsec ; i++){
        printf("%d      %10s\n", sectores[i].id, sectores[i].descripcion);
    }

}
