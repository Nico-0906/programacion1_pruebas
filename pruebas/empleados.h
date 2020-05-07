#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmpleado;

#endif // EMPLEADOS_H_INCLUDED


int printEmpleado(eEmpleado* lista, int tam);

int ordEmpleados(eEmpleado* lista, int tam, int orden);

int borrarEmpleado(eEmpleado* lista, int tam, int id);

int buscaEmpleadoPorId(eEmpleado* lista, int tam, int id);

int addEmpleado(eEmpleado* lista, int tam, int id, char name[], char lastName[], float salary, int sector);

int iniEmpleado(eEmpleado* lista, int tam);
