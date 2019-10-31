/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 25 de octubre de 2019, 16:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char** argv) {

    FILE * fA =NULL;
    //IniciaFileBin(fA,"ARCHA.data", "ab+");    
    ImprimeFile (fA, "ARCHA.data", "rb+");
    
    //STR_NODO *listA;
    //createList(&listA);
    //ingresaDatoenListado(&listA, fA);
    //printList(listA);
    
    FILE * fO =NULL;
    //IniciaFileBin(fO,"ARCHL.data", "wb+");
    //generaFileOrdenado(fA, &listA,fO);
    ImprimeFile(fO, "ARCHL.data", "rb+");
     
return (EXIT_SUCCESS);
}
