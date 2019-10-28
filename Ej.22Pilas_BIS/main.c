/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 28 de octubre de 2019, 09:43
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char** argv) {

    STR_NODO *listA;
    create(&listA);
    ingresaDatoList(&listA);
    //printList(listA);
    
    STR_NODO *listB;
    create(&listB);
    ingresaDatoList(&listB);
    //printList(listB);
    
    creaListC(&listA, &listB);
         
return (EXIT_SUCCESS);
}


