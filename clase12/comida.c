#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "comida.h"

void mostrarComidas(eComida comida[], int tam){
    printf("Listado de comidas \n\n");
    printf("ID     Descripcion     Precio \n");
    for(int i = 0 ; i < tam ; i++){
        printf("%d   %10s       $%5.2f \n", comida[i].id, comida[i].descripcion, comida[i].precio);
    }
}


int cargarDescripcionComida(char descripcion[], int id, eComida comidas[], int tam){
    int retorno = 0;
    for(int i = 0; i < tam ; i++){
        if(comidas[i].id == id){
            strcpy(descripcion, comidas[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}
