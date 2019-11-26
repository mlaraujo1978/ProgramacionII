/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 25 de noviembre de 2019, 21:35
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "funciones.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    int cantReg=0;
    
    FILE *fB=NULL;
    
    cantReg=CuentaRegistrosFile(fB);
    
    STR_DATOS **datos=(STR_DATOS**)malloc(sizeof(STR_DATOS*)*cantReg);
    
    for(int i=0;i<cantReg;i++){
    
        datos[i]=(STR_DATOS*)malloc(sizeof(STR_DATOS));
    }
    
    inicializaVector(datos,cantReg);
    
    cargaVector(fB, datos,cantReg);
    
    ordenaVector(datos,cantReg);
    
    cargaSinDuplicadosEnFile(datos,cantReg,fB);
    
    imprimeFile(fB);

    return (EXIT_SUCCESS);
}


