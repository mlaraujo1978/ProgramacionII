/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 18 de noviembre de 2019, 11:46
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "funciones.h"


int main(int argc, char** argv) {
    
    STR_LISTA *list1=NULL;
    STR_LISTA *list2=NULL;
    STR_LISTA *list3=NULL;
    
    int n1;
    int n2;
    
    printf("Ingrese la cantidad de elementos lista 1:\n");
    scanf("%d", &n1);
    printf("Ingrese la cantidad de elementos lista 2:\n");
    scanf("%d", &n2);
 
    double numLA[n1];
    double numLB[n2];
    
    double suma=0;
     
    cargaLista(&list1,n1, numLA);
    
    cargaLista(&list2, n2, numLB);
    
    suma=sumaNumerosDeListas(list1, list2);
    
    creaListaConSuma(suma,list1, list2, &list3);
    
    return (EXIT_SUCCESS);
    
}


    
