/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lourdes
 *
 * Created on 1 de octubre de 2019, 13:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
/*
 * 
 */
FILE * openFile(char nF[15],char tA[4]){

FILE * f=fopen(nF, tA);
if(f==NULL){
    printf("el archivo no se puede abrir");
    exit(1);
}    
return f;
}

int sumaMje(char *mje){

    char *aux=(char*)malloc(sizeof(char)*1);
    int suma=0;
    
    while(*mje && *mje!='\0'){
    
        int i=0;
    
    while (*mje && *mje!='\0' && i<1){
    
        *(aux+i)=*mje;
        mje++;
        i++;
      }
    suma+=atoi(aux);    

    }
return suma;
}

void justDoIt(FILE* fT, FILE* fM){

fT=openFile("Tramas.txt", "r+");
fM=openFile("Mensajes.txt", "w+");

int cantR=0;

char *flujo= (char*)malloc(sizeof(char)*250+1);

char *cabe=(char*)malloc(sizeof(char)*2);
char *lmje=(char*)malloc(sizeof(char)*3);
char *mje=(char*)malloc(sizeof(char)*100);
char *cR=(char*)malloc(sizeof(char)*3);
char coma={','};

while((fgets(flujo, 250+1, fT))!=NULL){

while(*flujo){

memset(cabe,'\0',2);
memset(lmje,'\0',3);
memset(mje,'\0',100);
memset(cR,'\0',3); 
    
int i=0;
int suma=0;

while(*flujo &&i<1){
    *(cabe+i)=*flujo;
    i++;
    flujo++;
}
printf("flujo: %s\t", flujo);
i=0;
printf("cabe: %s\t", cabe);

while(*flujo &&i<2){
    *(lmje+i)=*flujo;
    i++;
    flujo++;
}
printf("el largo es: %s\t", lmje);
int num=atoi(lmje);
i=0;

while(*flujo && i<num){
    *(mje+i)=*flujo;
    i++;
    flujo++;
    }

suma=sumaMje(mje);

printf("el mje es: %s", mje);
printf("la suma es: %d", suma);
i=0;

while(*flujo &&i<2){
    *(cR+i)=*flujo;
    i++;
    flujo++;
   }

cantR++;

    if( cantR==1 && suma==atoi(cR)&&(strcmp(flujo,""))!=0){
    fputs(mje,fM);
 
    }
    if( cantR==1 && suma!=atoi(cR)&&(strcmp(flujo,""))!=0){
    char mje1[]={"error en <número de la trama>"};
    fputs(mje,fM);
    }

    if(cantR>1 && suma==atoi(cR) && (strcmp(flujo,""))!=0){
    fputc(coma, fM);
    fputs(mje,fM);
   
    }
    if(cantR>1 && suma!=atoi(cR)&& (strcmp(flujo,""))!=0){
    char mje1[]={"error en <número de la trama>"};
    fputc(coma, fM); 
    fputs(mje1,fM);
    }
  }
}
fclose(fM);
fclose(fT);
return;
}

void imprimirFileT (FILE *f, char nF[15], char tA[4]){

f=openFile(nF, tA);

char mje[250+1];

while((fgets(mje, 250+1, f))!=NULL){

printf("El texto es: %s\n", mje);    
    
}
return;
}


int main(int argc, char** argv) {
    FILE* fT=NULL;
    FILE* fM=NULL;
    
    justDoIt(fT, fM); 
    
    imprimirFileT (fT, "Tramas.txt", "r+");
    imprimirFileT (fM, "Mensajes.txt", "r+");
    
    return (EXIT_SUCCESS);
}


