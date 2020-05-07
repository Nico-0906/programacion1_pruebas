#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombres[5][20];

    for(int i = 0 ; i < 5 ; i++){
        fgets(nombres[i], 20, stdin);
    }

    char auxNombres[20];

    for(int i = 0; i < 5 - 1 ; i++){
        for(int j = i + 1; j < 5 ; j++){
            if(strcmp(nombres[i], nombres[j]) > 0 ){
                strcpy(auxNombres, nombres[i]); //con esto se ordenan alfabeticamente
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxNombres);
            }
        }
    }

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 20; j++){
            if(nombres[i][j] == '\n'){  //para sacarle los \n al fgets by Nico
                nombres[i][j] = '\0';
            }
        }

    printf("%s ", nombres[i]);

    }
    return 0;
}
