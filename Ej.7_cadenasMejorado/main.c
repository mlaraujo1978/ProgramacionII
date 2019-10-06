/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 6 de octubre de 2019, 13:47
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
/*
 *
 */
int main(int argc, char** argv) {


    char *linea;
    linea=(char*)malloc(sizeof(char)*80+1);
    memset(linea,'\0',80+1);

    char vocales[6]={"AEIOU"};
    
    char palabra[80+1];
    memset(palabra,'\0',80+1);

    char *espacio=" ";

    int OrdPal=0;
    int valVoc=0;
    int valCon=0;
    int validaVoc=0;

    printf("Ingrese palabras separadas por un espacio\n");
    gets(linea);

   int i=0;

    while(*linea && *linea!='\0'){
        
        OrdPal++;

        while(*linea && *linea!=' ' && *linea!='\0'){

        *(palabra+i)=*linea;

        if(OrdPal==2 && validaVoc==0 && valCon==5){
                    
        validaVoc++;
       
        for(int j=0; j<5;j++){   
            
            if(*(linea)==*(vocales+j)){
                valVoc++;
            }
        }
               
        if(valVoc!=1){
        *(palabra+i)=*espacio;
        linea--;        
        }
        }
        linea++;
        i++;
        }

        if(OrdPal==1){
        linea--;
        
        for(int j=0;j<5;j++){
        if(*(linea)!= *(vocales+j)){
        valCon++;
        }
        }
        linea++;
        
        if(valCon!=5){
        *(palabra+i)=*espacio;
        i++;
        }
        }

        if(OrdPal==2){
        *(palabra+i)=*espacio;
        i++;
        OrdPal=0;
        valCon=0;
        valVoc=0;
        validaVoc=0;
        }
        linea++;
        
        }

   printf("La cadena final es: %s\t", palabra);

    return (EXIT_SUCCESS);
}

