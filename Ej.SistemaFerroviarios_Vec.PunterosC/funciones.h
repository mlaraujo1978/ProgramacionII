/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 15 de diciembre de 2019, 16:27
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
char codigoPas[6];
char estadoPas[15];
char estacionAsc[3];
char estacionDesc[3];
}STR_PASAJE;

typedef struct{
char codigoPas[6];
char estacionDesc[3];
}STR_PASAJESUBEN;

FILE * openFile(const char *nameF, const char *openT);

void inicializaVector(STR_PASAJE *pasaje[], int n);

void cargaCodigoPasaje(STR_PASAJE *pasaje[], int n, FILE* fGP);

int numeroEstacionDescenso (const char *numEst);

void actualizaEstadoPasajeros(STR_PASAJE *pasaje[], int n, int estacion);

void actualizaVecFileSuben(const char *nameF, const char* openT,STR_PASAJE *pasaje[], int n, const char *estacion);

void actualizaGranPlanilla(STR_PASAJE *pasaje[],int n);

void cargaFileconVector(STR_PASAJE *pasaje[],int n,FILE* fBP);

void ordenoVectorMayoraMenor(STR_PASAJE *pasaje[], int n);

void ordenoVectorMayoraMenor2(STR_PASAJE *pasaje[], int n);

void ordenaVectorVariableCadena2(STR_PASAJE *pasaje[], int n);

void imprimeVector(STR_PASAJE *pasaje[], int n);

void imprimeFile(FILE * f);

#endif /* FUNCIONES_H */

