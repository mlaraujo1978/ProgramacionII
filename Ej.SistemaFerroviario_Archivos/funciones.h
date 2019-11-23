/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 22 de noviembre de 2019, 20:00
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
int codigoPas;
char estadoPas[15];
char estacionAsc[3];
char estacionDesc[3];
}STR_PASAJE;

typedef struct{
char codigoPas[3];
char estacionDesc[3];
}STR_PASAJESUBEN;


FILE * openFile(const char *nameF, const char *openT);

void ImprimeFile(FILE * f);
    
void actualizaPlanillaSuben(FILE *fPlanilla,FILE *fSuben,const char *nameF, const char *openT, const char *estacion);
    
int numeroEstacionDescenso (const char *numEst);

void actualizaEstadoPasajeros(FILE *fPlanilla, int estacion);

void actualizaGranPlanilla(FILE *fPlanilla, FILE *fSuben1,FILE *fSuben2,FILE *fSuben3,FILE *fSuben4);
    
    
    
    


#ifdef __cplusplus
}
#endif

#endif /* FUNCIONES_H */

