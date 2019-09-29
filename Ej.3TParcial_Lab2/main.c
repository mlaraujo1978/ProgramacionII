/*
 * File:   main.c
 * Author: mlaraujo1978
 * Created on 26 de septiembre de 2019, 11:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
/*
 * 
 */
FILE * openFileTRMT(){

FILE * f=fopen("Tramas.txt", "r+");
if(f==NULL){
    printf("el archivo no se puede abrir");
    exit(1);
}    
return f;
}

FILE * openFileMRMT(){

FILE * f=fopen("Mensajes.txt", "r+");
if(f==NULL){
    printf("el archivo no se puede abrir");
    exit(1);
}    
return f;
}

FILE * openFileWMT(){

FILE * f=fopen("Mensajes.txt", "w+");
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

fT=openFileTRMT();
fM=openFileWMT();

char *flujo= (char*)malloc(sizeof(char)*250);
char *cabe=(char*)malloc(sizeof(char)*2);
char *lmje=(char*)malloc(sizeof(char)*3);
char *mje=(char*)malloc(sizeof(char)*40);
char *cR=(char*)malloc(sizeof(char)*3);
char coma={','};

while((fgets(flujo, 250+1, fT))!=NULL){

while(*flujo &&*flujo!='\0'){
   
int i=0;
int suma=0;
memset(cabe,'\0',2);
memset(lmje,'\0',3);
memset(mje,'\0',40);
memset(cR,'\0',3);

while(*flujo &&*flujo!='\0' &&i<1){
    *(cabe+i)=*flujo;
    i++;
    flujo++;
}
i=0;
printf("cabe es: %s", cabe);
while(*flujo &&*flujo!='\0' &&i<2){
    *(lmje+i)=*flujo;
    i++;
    flujo++;
}
printf("el largo es: %s", lmje);
int num=atoi(lmje);
i=0;
while(*flujo &&*flujo!='\0' &&i<num){
    *(mje+i)=*flujo;
    i++;
    flujo++;
    }
suma=sumaMje(mje);
printf("el mje es: %s", mje);
printf("la suma es: %d", suma);
i=0;
while(*flujo &&*flujo!='\0' &&i<2){
    *(cR+i)=*flujo;
    i++;
    flujo++;
   }

if(suma==atoi(cR)){
fputs(mje,fM);
fputc(coma, fM);
printf("el cR es: %s", cR);
}
else{
char mje1[]={"error en <número de la trama>"};
fputs(mje1,fM);
fputc(coma, fM);  
}
}
}
fclose(fM);
fclose(fT);
return;
}

void imprimirFileT (FILE *f){

f=openFileMRMT();
char mje[41];

while((fgets(mje, 41+1, f))!=NULL){

printf("Los mensaje son: %s", mje);    
    
}
return;
}


int main(int argc, char** argv) {
    FILE* fT=NULL;
    FILE* fM=NULL;
    
    justDoIt(fT, fM); 
    
    imprimirFileT (fM);
    
    return (EXIT_SUCCESS);
}

