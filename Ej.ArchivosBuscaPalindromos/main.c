/* 
 * File:   main.c
 * Author: mlaraujo1978
 * Created on 20 de septiembre de 2019, 17:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char** argv) {
    FILE* fA=NULL;
    FILE* fB=NULL;
    FILE* fC=NULL;
    
    int canRegFa=0;
    int canRegFb=0;
    int fRmenor=0;
    
    fA=abrirArchivo1ModoRBMas(fA);
    canRegFa=cantRegistrosFile(fA);
        
    fB=abrirArchivo2ModoRBMas(fB);
    canRegFb=cantRegistrosFile(fB);
      
    if(canRegFa<canRegFb){
        fRmenor=canRegFa;
        }
    else{
        fRmenor=canRegFb;
        }
    //printf("El archivo de menor registro es: %d\n", fRmenor);
     
    //copiaPalindromoArchivoTxt(fA,fB,fC);
  
    //imprimeArchivo1Bin(fA);
   
    //imprimeArchivo2Bin(fB);
    
    imprimeArchivoTxt(fC);
           
return (EXIT_SUCCESS);
}

