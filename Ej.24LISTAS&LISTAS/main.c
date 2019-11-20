/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 20 de noviembre de 2019, 12:52
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    STR_LISTA1 *division=NULL;
    
    
    FILE *fAlu=NULL;
    
    //imprimeFile(fAlu);
    
    cargaListaOrdenadaDivyLegajo(fAlu,&division);

    ImprimeListas(fAlu, division);
        

    return (EXIT_SUCCESS);
}

