/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 15 de diciembre de 2019, 16:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"


int main(int argc, char** argv) {
    
    FILE *fGP=NULL;
    FILE *fBP=NULL;
    
    int cantPasajeros=10;
    
    STR_PASAJE **pasaje=(STR_PASAJE**)malloc(sizeof(STR_PASAJE*)*10);
    
            for(int i=0;i<10;i++){
    
        pasaje[i]=(STR_PASAJE*)malloc(sizeof(STR_PASAJE));
    
        }
    
    inicializaVector(pasaje,10);
    
    cargaCodigoPasaje(pasaje,10, fGP); 
    
    actualizaGranPlanilla(pasaje,10);
    
    cargaFileconVector(pasaje,10, fBP);
    
    ordenaVectorVariableCadena2(pasaje,10);
    
    imprimeVector(pasaje,10);
    
    imprimeFile(fGP); 

    return 0;
}
