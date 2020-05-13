#ifndef INFOEMPLEADO_H_INCLUDED
#define INFOEMPLEADO_H_INCLUDED



#endif // INFOEMPLEADO_H_INCLUDED


void informesEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void listarEmpleadosXAnio(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informarTotalSueldos(eEmpleado vec[], int tam);

char menuInforme();

void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informarEmpleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informarEmpleadoCostosoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void aumentarSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informarSectorCostoso(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

float obtenerTotalSueldosSector(int idSector, eEmpleado vec[], int tam);

void informeTotalSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informeCantEmpleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

void informeEmpleadoMasJovenSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

