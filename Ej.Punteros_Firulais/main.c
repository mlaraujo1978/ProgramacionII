/* 
 * File:   main.c
 * Author: mlaraujo1978
 *
 * Created on 23 de septiembre de 2019, 19:01
 */
typedef struct{
int edad;
}Firulais;

Firulais * concebirFirulais(int edad){

    Firulais *firu =(Firulais*)malloc(sizeof(Firulais));
    
    firu->edad=edad;
    
    return firu;
}



#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    Firulais *firu=NULL;
    
    firu= concebirFirulais(10);
    
    printf("La edad es :%d", firu->edad);
    
    
    return (EXIT_SUCCESS);
}

