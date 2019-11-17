/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 17 de noviembre de 2019, 12:15
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"
int main(int argc, char** argv) {
    
    STR_PILA *pila=NULL;
    
    STR_Q colA;
    inicializaCola(&colA);
    
    STR_Q colB;
    inicializaCola(&colB);
    
    int numCA[4]={1,2,3,4};
    int numCB[4]={5,6,7,8};
    
    creaColaA(&colA,numCA);
    
    creaColaB(&colB,numCB);
    
    GeneraPilaconColas (&colA,&colB,&pila);
       
    imprimePila(&pila);

    return (EXIT_SUCCESS);
}


