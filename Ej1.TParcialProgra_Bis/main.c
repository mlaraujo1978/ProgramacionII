/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 *
 * Created on 23 de septiembre de 2019, 13:57
 */
int myStrCmp(const char *cad1, const char *cad2){
    
    while(*cad1 && *cad2 && *cad1 == *cad2){
        cad1++;
        cad2++;
    }
    printf("cadena 1: %s\t", cad1);
    printf("cadena 2: %s\n", cad2);
    int retval=0;
    
    if(*cad1 && *cad2){
        retval = (*cad1 - *cad2) > 0 ? -1 : 1;
   }
    
    printf("retval %d\n", retval);
    
    //if(*cad1 && !*cad2){
     //   retval = -1;
    //}
    
    //if(!*cad1 && *cad2){
    //    retval = 1;
    //}
    
    return retval;
}

/*
 * Para ejecutar invocar al ejecutable y pasarle por línea de comando las palabras a comparar.
 * Ej: prueba casa casa 
 */

    // char cad1[] = "casa";
        

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
   
    char *cad1=(char*)malloc(sizeof(char)*20);
    memset(cad1,'\0',20);
    char *cad2=(char*)malloc(sizeof(char)*20);
    memset(cad2,'\0',20);
  
    printf("Ingrese una cadena\t");
    scanf("%s", cad1);
 
    printf("Ingrese una cadena\t");
    scanf("%s", cad2);
    
    int rdo=myStrCmp(cad1, cad2);
    
    //if((rdo=myStrCmp(cad1, cad2))==0){
    //printf("Las cadenas son iguales");
     //}
    //if((rdo=myStrCmp(cad1, cad2))==1){
    //printf("La segunda cadena es mayor a la primera");
    // }
    // if((rdo=myStrCmp(cad1, cad2))==-1){
    //printf("La segunda cadena es menor a la primera");
   // }
 
    return (EXIT_SUCCESS);
}
