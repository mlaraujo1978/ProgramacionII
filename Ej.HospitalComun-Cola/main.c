/* 
 * File:   main.c
 * Author: lourdes
 * Created on 8 de noviembre de 2019, 10:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

int main(int argc, char** argv) {
    
FILE *fT=NULL;

FILE *fB=NULL;

STR_Q q;
crearCola(&q);

cargaPacientesCola(fT,&q);

cargaTurnosFileBin(fB,&q);

imprimeFileBin (fB);

return (EXIT_SUCCESS);
}


