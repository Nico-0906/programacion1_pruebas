#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//tolower(parametro); cambia a minuscula la posicion indicada en el parametro de la cadena
//toupper(paramero);  cambia a majuscula la posicion indicada en el parametro de la cadena
#include <string.h>
//strlen capta la longitud de una cadena y lo retorna
//strcpy copia el contenido de una cadena en otra cadena strcpy(destino, origen);
//strncpy copia el contenido de una cadena pero limitado por el tercer factor de el segundo aprametro al primero
//strcat(parametro1, parametro2);  concatena el parametro2 en el parametro 1
//strcmp(parametro1, parametro2); devuelve un numero negativo si el parametro de la izquierda esta antes en el diccionario que el de la derecha o un numero positivo si esta despues en el diccionario del q esta a la derechal
#include <stdio_ext.h>
//__fpurge(stdin);  es como el fflush(stdin); en windows, sirve para vaciart el buffer del teclado para el fgets o gets o scanf con char

#include "utn.h"
#include "empleados.h"

void ordenarAlumnos(int l[], char sex[], int nota1[], int nota2[], float prom[], int tam, int atributo, int criterio); //tenemos que desarrolar esta funcion para que ordene segun atributo y riterio de orden

void mostrarAlumnos(int l[], char nomb[][20], char apell[][20], char sex[], int nota1[], int nota2[], float prom[], int tam); //desarrollar funcion para que nos muestre los alumnos

void mostrarAlumno(int l, char nomb[], char apell[], char sex, int nota1, int nota2, float prom); //desarrollar

int main()
{
    char sexo[5] = {'m', 'f', 'm', 'f', 'm'};
    int legajo[5] = {1223, 4456, 2331, 1565, 1121};
    int auxInt;
    int notasP1[5] = {5, 6, 7, 8, 9};
    int notasP2[5] = {7, 8, 9, 10, 9};
    float promedios[5] = {6, 7, 8, 9, 9};
    char nombres[5][20] = {"Pedro", "Lucia", "Emanuel", "Cristina", "Nicolas"};
    char apellidos[5][20] = {"Perez", "Gomez", "Lopez", "Benavente", "Reuter"};
    float auxFloat;
    char auxChar;
    char auxStr[20];
/*
    for(int i = 0 ; i < 5 ; i++){
        printf("Ingrese legajo: \n");
        scanf("%d", &legajo[i]);

        printf("Ingrese Nombre: \n");
        __fpurge(stdin);
        getStr(nombres[i], 20);

        printf("Ingrese Apellido: \n");
        __fpurge(stdin);
        getStr(apellidos[i], 20);

        printf("Ingrese sexo: \n");
        __fpurge(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese nota P1: \n");
        scanf("%d", &notasP1[i]);

        printf("Ingrese nota P2: \n");
        scanf("%d", &notasP2[i]);

    }
*/
    for(int i = 0 ; i < 5 - 1 ; i++){
        for(int j = i + 1 ; j < 5 ; j++){
            if(sexo[i] < sexo[j]){
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;

                auxInt = notasP1[i];
                notasP1[i] = notasP1[j];
                notasP1[j] = auxInt;

                auxInt = notasP2[i];
                notasP2[i] = notasP2[j];
                notasP2[j] = auxInt;

                auxFloat = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxFloat;

                strcpy(auxStr, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxStr);

                strcpy(auxStr, apellidos[i]);
                strcpy(apellidos[i], apellidos[j]);
                strcpy(apellidos[j], auxStr);

            }else if(sexo[i] == sexo[j] && promedios[i] > promedios[j]){
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;

                auxInt = notasP1[i];
                notasP1[i] = notasP1[j];
                notasP1[j] = auxInt;

                auxInt = notasP2[i];
                notasP2[i] = notasP2[j];
                notasP2[j] = auxInt;

                auxFloat = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxFloat;

                strcpy(auxStr, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxStr);

                strcpy(auxStr, apellidos[i]);
                strcpy(apellidos[i], apellidos[j]);
                strcpy(apellidos[j], auxStr);
            }
        }

    }

    mostrarAlumnos(legajo, nombres, apellidos, sexo, notasP1, notasP2, promedios, 5);
    /*
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];

    printf("Ingrese nombre: ");
    getStr(nombre, 20);

    printf("\nIngrese apellido: ");
    getStr(apellido, 20);


    tipoNombre(apellido, 20);

    strcpy(nombreCompleto, nombre);

    tipoNombre(nombreCompleto, 39);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, apellido);

    printf("\n El nombre completo es: %s", nombreCompleto);
    */

    return 0;
}
void mostrarAlumnos(int l[], char nomb[][20], char apell[][20], char sex[], int nota1[], int nota2[], float prom[], int tam){ //desarrollar funcion para que nos muestre los alumnos

    printf("***** NOTAS *****\n");
    printf("Legajo       Nombre     Apellido    Sexo    Nota 1P     Nota 2P    Promedio\n");

    for(int i = 0 ; i < tam ; i++){
        prom[i] = (float) (nota1[i] + nota2[i]) / 2;
        mostrarAlumno(l[i], nomb[i], apell[i], sex[i], nota1[i], nota2[i], prom[i]);
    }
}

void mostrarAlumno(int l, char nomb[], char apell[], char sex, int nota1, int nota2, float prom){

    printf("  %4d   %10s   %10s      %c     %2d          %2d         %5.2f  \n", l, nomb, apell, sex, nota1, nota2, prom);

}
