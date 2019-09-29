/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 *
 * Created on 7 de septiembre de 2019, 22:23
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int cantidadPalabras(const char *linea){
    int cantP=0;
    while(*linea){
        while(*linea && *linea!=' ' && *linea!='\0'){
         linea++;   
    }
        cantP++;
        linea++;
 }
    //printf("la cantidad de palabras es: %d\n", cantP);
    return cantP;
}
int LongitudPalLarga(const char *linea){
     int longi=0;
     int longiMax=0;
     while(*linea){
        while(*linea && *linea!=' ' && *linea!='\0'){ 
            linea++;
            longi++;
        }
        linea++;
        if(longi>longiMax){
            longiMax=longi;
        }
        longi=0;        
     }
     return longiMax;
 }
void copiaPalabra(const char *origen, char *const destino){
    int i=0;
    while(*origen){
     *(destino+i)=*origen;
     origen++;
     i++;
  }
  return;
 }
void PalabraMasLarga(const char *linea, char *const palabra, char *const palMax, int longMax) {  
    int longM=0;
    int i=0;
    int longit=0;
    while(*linea){
         memset(palabra,'\0',longMax);
         i=0;
         longit=0;
           while(*linea && *linea!=' ' && *linea!='\0'){ 
            *(palabra+i)=*linea;
            linea++;
            longit++;
            i++;
            } 
        printf("palabra %s\n", palabra);
        linea++;
        if(longit>longM){
            longM=longit;
            memset(palMax,'\0',longMax);
            //strcpy(palMax,palabra);
            copiaPalabra(palabra, palMax);
        }
    } 
  return;
}
/*
 * 
 */
int main(int argc, char** argv) {
    char *linea;
    linea=(char*)malloc(sizeof(char)*80+1);
    memset(linea,'\0',80+1);
    
    printf("Ingrese palabras separadas por un espacio\n");
    gets(linea);
    
    printf("La cantidad de palabras es: %d\n", cantidadPalabras(linea));
    
    int longMax=LongitudPalLarga(linea);
    printf("la longitud de la palabra mas larga es: %d\n", longMax);
    
    char palabra[longMax+1];
    memset(palabra, '\0', longMax+1);
    
    char palMax[longMax+1];
    memset(palMax,'\0', longMax+1);
    
    PalabraMasLarga(linea, palabra, palMax, longMax);
    
    printf("la palabra de longitud maxima es: %s\n", palMax);     
    return (EXIT_SUCCESS);
}

