#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//tolower(parametro); retorna el caracter de la cadena indicado como minuscula
//toupper(paramero);  retorna el caracter de la cadena indicado como mayuscula
#include <string.h>
//strupr(cadena); pasa toda la cadena de caracteres a mayuscula
//strlwr pasa toda la cadena de caracteres a minuscula
//strlen capta la longitud de una cadena y lo retorna
//strcpy copia el contenido de una cadena en otra cadena strcpy(destino, origen);
//strncpy copia el contenido de una cadena pero limitado por el tercer factor de el segundo aprametro al primero
//strcat(parametro1, parametro2);  concatena dos cadenas de caracteres; el parametro2 en el parametro1 y lo guarda en el parametro1
//strcmp(cadena1, cadena2); compara las dos cadenas y devuelve 0 si son iguales, -1 si lo primero esta antes que lo segundo en el diccionario, y 1 si lo segundo esta antes
//stricmp(cadena1, cadena2); compara igual que strcmp(); pero ignora la diferencia de mayusculas y minusculas

/*int getCadena(int pCadena[], int tam, char mensaje[], char mensajeError[], int intentos){
   int retorno = -1;
   char buffer[tam];

    printf("%s", mensaje);

    if(intentos != -1){

    fgets(buffer, tam, stdin);
    if(buffer)
    intentos--;
    }else{
    printf("%s", mensajeError);
    }

}
*/

void tipoNombre(char vec[], int tam){
    vec[0] = toupper(vec[0]);

    for(int i = 1 ; i < tam ; i++){
        vec[i] = tolower(vec[i]);
    }

}

void getStr(char cadena[], int tam){    //falta desarrollar o probar
    fgets(cadena, tam, stdin);

    for(int i = 0; i < tam; i++){
        if(cadena[i] == '\n'){
            cadena[i] = '\0';
        }
    }

}

float calcularPromedio(int vec[], int tam){
    float promedio;
    int acumulador = 0;
        for(int i = 0; i < tam; i++){
            acumulador += vec[i];
        }
    promedio = (float) acumulador / tam;

    return promedio;
}

int pedirEnteroRango(int* pNum, char mensaje[], char mensajeError[], int limiteInf, int limiteSup, int intentos){
    int exito = 0;
    int flag = 0;
    int entero;

    printf("%s", mensaje);
    scanf("%d", &entero);

    while(entero > limiteSup || entero < limiteInf){
        intentos--;
        if(intentos == -1){
            flag = 1;
            break;
        }
        printf("%s", mensajeError);
        scanf("%d", &entero);
    }

    if(flag == 0){
        *pNum = entero;
        exito = 1;
    }

    return exito;
}


void mostrarVectorInt(int vec[], int tam){
    for(int i = 0 ; i < tam ; i++){
        printf("%d", vec[i]);
    }
    printf("\n");
}

/*  brief ordena un vector de enteros
 *
 *  param   vector que se quiere ordenar
 *  param   tamaño del vector
 *  param   orden en que se quiere ordenar = 1 de menor a mayor o 0 de mayor a menor
**/

void ordenarEnteros(int vec[], int tam, int orden)
{
    int auxiliar;

    for(int i = 0; i < tam - 1 ; i++){
        for(int j = i + 1; j < tam ; j++){
                if(vec[i] < vec[j] && orden){
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }else if(vec[i] > vec[j] && !orden){
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;

                }
        }
    }
}

/*  brief ordena un cadena de caracteres
 *
 *  param   cadena que se quiere ordenar
 *  param   tamaño de la cadena
 *  param   orden en que se quiere ordenar = 1 de menor a mayor o 0 de mayor a menor
**/

void ordenarCaracteres(char vec[], int tam, int orden)
{
    char auxiliar;

    for(int i = 0; i < tam - 1 ; i++){
        for(int j = i + 1; j < tam ; j++){
            if(orden == 0){
                if(vec[i] < vec[j]){
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }
            }else if(orden == 1){
                if(vec[i] > vec[j]){
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }
            }
        }
    }
}

void strlwrLinux(char cadena[]){
    int i = 0;

    while(cadena[i] != '\0'){
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}

int suma(int a, int b){
    int rta;
    rta = a + b;
    return rta;
}

int resta(int a, int b){
    int rta;
    rta = a - b;
    return rta;
}

int multiplica(int a, int b){
    int rta;
    rta = a * b;
    return rta;
}

float divide(int a, int b){
    float rta;
    rta = (float) a / b;
    return rta;
}

int factorial(int a){
    int rta;
    rta = a * factorial(a - 1);
    return rta;
}

