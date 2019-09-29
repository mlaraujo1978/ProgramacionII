/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Lourdes
 *
 * Created on 8 de septiembre de 2019, 14:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

  
            
int ValidaVocal(const char *origen, const char *vecVocales){
int valVoc=0;
    for(int i=0;i<5;i++){
        if(origen[0]==vecVocales[i]){
        valVoc++;
        printf("La vocal es: %s\n", &origen[0]);
        }
    }    
return valVoc;   
}
int ValidaConso(const char *origen, const char *vecVocales,int longA){
int valConso=0;
        for(int i=0;i<5;i++){
            if(origen[longA-1]!=vecVocales[i]){
                valConso++;
            printf("Letra es:%s\n",&origen[longA-1]);
            }    
        }           
return valConso;    
}
void concatenaPalabra(const char *origen, char *const destino, int longT, int longA){
    int i=0;
    if(cantPal==1){
    while(*origen){
     *(destino+(longT-longA+i))=*origen;
    origen++;
    i++;
    }
    printf("Palabra concatenada es:%s\n", destino);
    }
    if(cantPal>1){
        if(cantPal%2!=0){
            if(valCon==5 && valVoc==1){
                
                    
                if(valVocal==1){
                while(*origen){
                *(destino+(longT-longA-1+i))=*origen;
                 origen++;
                 i++;
                }
                destino[longT+1]='\t';
            //printf("Palabra concatenada es:%s\n", destino);
                }
            }
            if(valVocal==1 && valCons!=5 || valVocal!=1 && valCons==5){
                destino[longT-longA-1-1]='\t';
                while(*origen){
                *(destino+(longT-longA-1+i))=*origen;
                 origen++;
                 i++;
                }
                destino[longT+1]='\t';
            //printf("Palabra concatenada es:%s\n", destino);
            }   
            
        }
    return;
    }
        
 
int main(int argc, char** argv) {
    char *linea;
    linea=(char*)malloc(sizeof(char)*80+1);
    memset(linea,'\0',80+1);
    
    char vecVocales[5]={'a','e','i','o','u'};
    
    char palabra[80+1];
    memset(palabra,'\0',80+1);
    
    char *palabraConca;
    palabraConca=(char*)malloc(sizeof(char)*80+1);
    memset(palabraConca,'\0',80+1);
    
    int longT=0;
    int longA=0;
    int cantPal=0;
    int valVoc=-1;
    int valCon=0;
    
    printf("Ingrese palabras separadas por un espacio\n");
    gets(linea);
    
   int i=0;
   int longi=0;
         
    while(*linea){
        while(*linea && *linea!=' ' && *linea!='\0'){ 
        *(palabra+i)=*linea;
        linea++;
        longi++;
        i++;
        } 
    cantPal++;
    longA=longi;
    longT=(longT+longi);
    if(cantPal%2!=0){fcccc
    valCon=ValidaConso(palabra,vecVocales,longA);
    }
    else{
    valVoc=ValidaVocal(palabra,vecVocales);
    }
    if(valCon==5 && valVoc==1){c
    concatenaPalabra(palabra, palabraConca,longT, longA);
    valCon=0;
    valVoc=-1;    
    }
    if(valCon==5&& valVoc==0||valCon==4 && valCon==1)
    concatenaPalabra(palabra, palabraConca,longT, longA); 
    valCon=0;
    valVoc=0; 
    }
    printf("la palabra es: %s\n",palabra);
    linea++;
    i=0;
    longi=0;
    memset(palabra,'\0',80+1);
    }
  
  
   
    //printf("La linea concatenada es:%s\n", palabraConca);
   return (EXIT_SUCCESS);
}

