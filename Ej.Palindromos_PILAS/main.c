/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 17 de noviembre de 2019, 19:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "funciones.h"


int main(int argc, char** argv) {
    
    STR_PILA *palabra=NULL;
    STR_PILA *palabraInv=NULL;
    
    FILE *fPalabras=NULL;
    
    FILE *fNoPalindromos=NULL;
    
    procesaFilePalabras(fPalabras,fNoPalindromos,&palabra,&palabraInv);
    
    imprimeFilePalindormos(fNoPalindromos);
    
 return (EXIT_SUCCESS);
}


