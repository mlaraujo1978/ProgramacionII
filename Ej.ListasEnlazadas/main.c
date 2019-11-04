/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 2 de noviembre de 2019, 12:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char** argv) {

    FILE *fA =NULL;
    //ImprimeFile (fA, "alumnos.data", "rb+");
    FILE *fC=NULL;
    //ImprimeFile (fC, "carreras.txt", "r+");
    FILE *fS=NULL;
    
    STR_NODOC *listC=NULL;
          
    CargaListasconDatosFile(fC, &listC);
    
    printListCarrerasAlum(listC);
      
    GeneraFileSalida(fA, fS,listC);
   
return (EXIT_SUCCESS);
}

