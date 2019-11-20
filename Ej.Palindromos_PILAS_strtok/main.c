/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 20 de noviembre de 2019, 17:27
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
    
    imprimeFileNoPalindormos(fNoPalindromos);
    

    return (EXIT_SUCCESS);
}

