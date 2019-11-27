/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 20 de noviembre de 2019, 18:12
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
       
    cargaLista(&list1);
    
    cargaLista(&list2);
    
    int suma=sumaNumerosDeListas(list1, list2);
    
    creaListaConSuma(suma,list1, list2, &list3);
       
    imprimeLista(list3); 
    
    return (EXIT_SUCCESS);
}




