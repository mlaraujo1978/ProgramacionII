/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 18 de noviembre de 2019, 15:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char** argv) {
    
    STR_LIST1 *anio=NULL;
    STR_LIST2 *cantVendida=NULL;
                
    FILE *fBandas=NULL;
    
    creaListaPorAnioYCantVend(fBandas,&anio);
    
    imprimeListaBandas(fBandas,anio);
    
    
    return (EXIT_SUCCESS);
}

