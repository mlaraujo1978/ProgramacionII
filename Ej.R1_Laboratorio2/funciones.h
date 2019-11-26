#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
    int id;
    char des[16];
}STR_DATOS;

void inicializaVector(STR_DATOS *datos[] , int n);

FILE * openFile(const char *nameF, const char *openT);

int CuentaRegistrosFile (FILE * fB);

void cargaVector(FILE* fB, STR_DATOS *datos[] , int n);

void ordenaVector(STR_DATOS *datos[],int n);
    
void cargaSinDuplicadosEnFile(STR_DATOS *datos[],int n,FILE *fT);

void imprimeFile (FILE * fB);

#endif /* FUNCIONES_H */

