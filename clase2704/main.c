#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define TAM 3
typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{ // asi se declara una estructura   -- struct{}; desp se iniciaria como struct nombre estructura nombre variable nueva

    int id;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
    eFecha fechaIngreso;    //se pueden usar estructuras dentro de estructuras

}eEmpleado; //estoy definiendo un nuevo tipo

void mostrarEmpleado(eEmpleado emp);

void ordenarEmpleados(eEmpleado vec[],int tam);

void mostrarEmpleados(eEmpleado vec[], int tam);

int main()
{
    // itoa(destino, origen, base)
    //primer parcial laboratorio es el 11/05 segunda parte el 18/05 y el 15/05 el parcial de programacion

    //--------------VAMOS A VER ESTRUCTURAS -------------------
    //similar a lo que seria una clase en un lenguaje orientado a objetos


    eEmpleado unEmpleado = {1234, "Juan", 'm', 31, 24500.50, {14,5,2017}};//cargarlo hardcodeado //como declarando una variable nueva.

    eEmpleado lista[TAM] = {{1234, "Juan", 'm', 31, 24500.50, {14,5,2017}},
                            {1122, "Daniela", 'f', 29, 26500.20, {23,8,2018}},
                            {2123, "Andres", 'm', 32, 28400.30, {17,3,2014}}
                            };//esto seria nuestro vector de tres empleados hardcodeado


    mostrarEmpleados(lista, TAM);

    //esto seria como para crear una funcion void ordenarEmpleados();
    ordenarEmpleados(lista, TAM);


    mostrarEmpleados(lista, TAM);

    eFecha auxFecha;

    printf("Ingrese ID \n");
    scanf("%d", &unEmpleado.id);
    printf("Ingrese nombre\n");
    __fpurge(stdin);
    fgets(unEmpleado.nombre, 20, stdin);

    printf("Ingrese sexo\n");
    __fpurge(stdin);
    scanf("%c", &unEmpleado.sexo);

    printf("ingrese edad:\n");
    scanf("%d", &unEmpleado.edad);

    printf("Ingrese sueldo:\n");
    scanf("%f", &unEmpleado.sueldo);

    printf("Ingrese dia/mes/anio: \n");
    scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);



    for(int i = 0; i < TAM; i++){

        printf("Ingrese ID \n");
        scanf("%d", &lista[i].id);

        printf("Ingrese nombre\n");
        __fpurge(stdin);
        fgets(lista[i].nombre, 20, stdin);

        printf("Ingrese sexo\n");
        __fpurge(stdin);
        scanf("%c", &lista[i].sexo);

        printf("ingrese edad:\n");
        scanf("%d", &lista[i].edad);

        printf("Ingrese sueldo:\n");
        scanf("%f", &lista[i].sueldo);

        printf("Ingrese dia/mes/anio: \n");
        scanf("%d/%d/%d", &lista[i].fechaIngreso.dia, &lista[i].fechaIngreso.mes, &lista[i].fechaIngreso.anio);

    }

    unEmpleado.fechaIngreso = auxFecha; // esto se puede hacer porque auxFecha es del mismo tipo que la fechade ingreso dentro de unEmpleado

/*
    printf("%d \n", unEmpleado.id);
    printf("%s \n", unEmpleado.nombre);
    printf("%c \n", unEmpleado.sexo);
    printf("%d", unEmpleado.edad);
    printf("%.2f", unEmpleado.sueldo); //de esta manera se accede a lo qu esta cargado dentro de esa variale

    //declaramos otra del tipo eEmpleado
*/
    //eEmpleado otroEmpleado;

    //otroEmpleado = unEmpleado; // de esta manera se podria copiar uno en el otro

    //  printf("\n %d \n", sizeof otroEmpleado ); aca estabamos viendo cuanto pesaba la estrucura

    mostrarEmpleado(unEmpleado);

    return 0;
}


void ordenarEmpleados(eEmpleado vec[],int tam){
    eEmpleado auxEmpleado;

    for(int i = 0; i < tam - 1; i++){
        for(int j = i + 1; j < tam ; j++){   //esto ordenaria la lista por ID en este caso de lista.
            if( vec[i].id > vec[j].id )  //(strcmp( lista[i].nombre, lista[j].nombre) > 0) asi ordenaria por orden alfabetico por nombre
            {                               //(lista[i].sexo > lista[j].sexo) esto ordenaria por sexo
                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
            }else if(vec[i].sexo == vec[j].sexo && vec[i].sueldo < vec[j].sueldo){
              auxEmpleado = vec[i];
              vec[i] = vec[j];
              vec[j] = auxEmpleado;
             }      //   con esto ordenaria ademas de por sexo, por sueldo tambien dentro de los mismos
        }
    }
}

void mostrarEmpleado(eEmpleado emp){
    printf("%4d       %10s        %c         %2d      %.2f          %2d / %2d / %4d \n", emp.id, emp.nombre, emp.sexo, emp.edad, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);
        //se vuelve a colocar puntos apra ingresar a campos dentro de campos como en dia mes y anio
}

void mostrarEmpleados(eEmpleado vec[], int tam){
    printf("***** Listado de empleados *****\n");
    printf(" ID             Nombre      Sexo      Edad       Sueldo        Fecha de ingreso\n");

    for(int i = 0; i < tam; i++){
        mostrarEmpleado(vec[i]);
    }
}
