/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* File:   main.c
 * Author: mlaraujo1978
 * Created on 21 de septiembre de 2019, 13:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#define LONG_P 256

typedef struct{
char cadena[LONG_P+1];
}STR_PAL;


FILE * abreFile_WB(){

FILE *file=fopen("palabras1.bin","wb+");
if(file==NULL){
    printf("El archivo no se puede abrir\n");
    exit(1);
}
return file;
}
FILE * abreFile_RmasB(){

FILE *file=fopen("palabras1.bin","rb+");
if(file==NULL){
    printf("El archivo no se puede abrir\n");
    exit(1);
}
return file;
}

void ingresaPalabrasFile(FILE *file){
    STR_PAL pal;
    for(int i=0;i<7;i++){
        printf("Ingrese palabra \n");
        scanf("%s", pal.cadena);
        fwrite(&pal,sizeof(STR_PAL), 1,file);
    }
    fclose(file);
    return;
}

void imprimiFile(FILE *file){
    STR_PAL pal;
    fread(&pal, sizeof(pal),1,file);
        while(!feof(file)){
        printf("%s\n", pal.cadena);
        fread(&pal, sizeof(pal),1,file);
    }
    fclose(file);
    return;
}
/*
 */
int main(int argc, char** argv) {
    FILE *palabras=NULL;
    STR_PAL pal;
    memset(pal.cadena,'\0',LONG_P+1);
        
    //palabras=abreFile_WB(palabras);
    //ingresaPalabrasFile(palabras);
    
    palabras=abreFile_RmasB(palabras);
    imprimiFile(palabras);
    
    return (EXIT_SUCCESS);
}

