/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <strings.h>
#include <string.h>

FILE* abrirArchivo1ModoRBMas (){
    
    FILE* f = fopen("palabras.bin", "rb+");
    if (f==NULL){
        printf("Error, el archivo no se pudo abrir.");
        exit(1);    
    }
    return f;
}

FILE * abrirArchivo2ModoRBMas(){
 
     FILE *f=fopen("palabras1.bin","rb+");
     if(f==NULL){
         printf("El archivo no se puede abrir");
         exit(1);
     }
return f;
 }
   
FILE* abrirArchivoModoWTMas (){
    FILE* fC = fopen("fC.txt", "w+");
    if (fC==NULL){
        printf("Error, el archivo no se pudo abrir.");
        exit(1);    
    }
    return fC;
}

FILE* abrirArchivoModoRTMas (){
    FILE* fC = fopen("fC.txt", "r+");
    if (fC==NULL){
        printf("Error, el archivo no se pudo abrir.");
        exit(1);    
    }
    return fC;
}

int cantRegistrosFile(FILE *f){
    int cantReg=0;
    fseek(f,0,SEEK_END);
    long pUltF=ftell(f);
    cantReg=pUltF/(LONG_P+1);
    //printf(" Cantidad de registros ultima posicion:%d\n",pUltF);
    //printf(" Cantidad de registros:%d\n", cantReg);
    fclose(f);
    return cantReg;
}

int longitudPal(const char *palabra){
    int longPal=0;
    while(*palabra){
        palabra++;
        longPal++;    
    }
    return longPal;
}

int cantValPalindromo (const char *palabra){
    int longPal=longitudPal(palabra);
    //longPal=strlen(palabra);
    int ini=0;
    int fin=longPal-1;
    int cantVal=0;
    while(*palabra && (*(palabra+ini)==*(palabra+fin)) && ini<fin){
        ini++;
        fin--;
        cantVal++;        
    }
    return cantVal;
}

void copiaPalindromoArchivoTxt (FILE* fA, FILE* fB, FILE* fC){
    
    STR_PAL palFA;
    STR_PAL palFB;
          
    fA=abrirArchivo1ModoRBMas(fA);
    fB=abrirArchivo2ModoRBMas(fB);
    fC=abrirArchivoModoWTMas(fC); 
    
    fread(&palFA,sizeof(STR_PAL),1,fA);
    while(!feof(fA)){
                
        fseek(fB,0,SEEK_SET);       
        fread(&palFB,sizeof(STR_PAL),1,fB);
        while(!feof(fB)){
            //printf(" La palabra fA es: %s\t", palFA.pal);
            //printf(" La palabra fB es: %s\n", palFB.pal);
            
            if((strcmp(palFA.pal,palFB.pal))==0){
                
                if( (cantValPalindromo(palFA.pal))==((strlen(palFA.pal))/2) ){
                
                fputs(palFA.pal,fC);
                //strcpy(palFA.pal, "");
                //fseek(fA,(-1)*sizeof(STR_PAL),SEEK_CUR);
                //fwrite(&palFA, sizeof(STR_PAL),1, fA);
                //strcpy(palFB.pal, "");
                //fseek(fB,(-1)*sizeof(STR_PAL),SEEK_CUR);
                //fwrite(&palFB, sizeof(STR_PAL),1, fB);
                }
            }  
        fread(&palFB,sizeof(STR_PAL),1,fB);
        }
        
    fread(&palFA,sizeof(STR_PAL),1,fA);   
    }
}

void imprimeArchivo1Bin(FILE* f){

f= abrirArchivo1ModoRBMas(f);   
    STR_PAL pal;
fread(&pal,sizeof(STR_PAL),1,f);
    while(!feof(f)){
    printf("%s\n\n", pal.pal);             
    fread(&pal,sizeof(STR_PAL),1,f); 
    }
fclose(f);
}
    
void imprimeArchivo2Bin(FILE* f){

f= abrirArchivo2ModoRBMas();   
    STR_PAL pal;
fread(&pal,sizeof(STR_PAL),1,f);
    while(!feof(f)){
    printf("%s\n\n", pal.pal);             
    fread(&pal,sizeof(STR_PAL),1,f); 
    }
fclose(f);
}
  

void imprimeArchivoTxt(FILE* f){
f= abrirArchivoModoRTMas();   

STR_PAL pal;

while(fgets(pal.pal,(LONG_P)+1,f)!=NULL){
    printf("%s", pal.pal);
        }
fclose(f);
}    

