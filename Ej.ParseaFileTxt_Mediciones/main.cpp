/* 
 * File:   main.cpp
 * Author: lourdes
 *
 * Created on 24 de noviembre de 2019, 11:06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
/*
 * 
 */

FILE * OpenFile(const char *nameF, const char *openT);

void reseteaPalabra(char *palabra, int largoPal);

char * parseaPalabra (const char *linea, int *indice);

void ProcesaFile (FILE* fT);



int main(int argc, char** argv) {
    
    FILE *f=NULL;
       
    ProcesaFile(f);

    return 0;
}

FILE *OpenFile(const char *nameF, const char *openT){

    FILE *f=fopen(nameF,openT);
    
    if(f==NULL){
    
        printf("El archivo no se puede abrir\n");
        exit(1);
    }

    return f;
}

void reseteaPalabra(char *palabra, int largoPal){

    for(int i=0;i<largoPal+1;i++){
    
    *(palabra+i)='\0';
    
    }

return;
}

char * parseaPalabra (const char *linea, int *indice){

int i=0;
char *palabra=(char*)malloc(sizeof(char)*50);
reseteaPalabra(palabra,50);

            
                                             
            while(*linea && *linea!=';'){
        
                *(palabra+i)=*linea;
                linea ++;
                i++; 
                *indice=*indice+1;
            }

            *indice=*indice+1;
            
return palabra;
}

void ProcesaFile (FILE* f){

    f=fopen("mediciones.txt","r+");
    
    char *linea= (char*)malloc(sizeof(char)*50);
    reseteaPalabra(linea,50);
    
    char *pp=(char*)malloc(sizeof(char)*2);
   
    char *dia=(char*)malloc(sizeof(char)*11);
    
    char *hora=(char*)malloc(sizeof(char)*6);
    
    char *x=(char*)malloc(sizeof(char)*25);
     
    char *decimal=(char*)malloc(sizeof(char)*5);
    
    int indice=0;
    int i=0;
    
    fgets(linea,50+1,f);
        
        while(!feof(f)){
        
        reseteaPalabra(pp,2);
        strcpy(pp,parseaPalabra((linea+indice),&indice));
        printf("\nPP: %s\t",pp);
        
        reseteaPalabra(dia,11);
        strcpy(dia,parseaPalabra((linea+indice),&indice));
        printf("DIA: %s\t",dia);
        
        reseteaPalabra(hora,6);
        strcpy(hora,parseaPalabra((linea+indice),&indice));
        printf("HORA: %s\t",hora);
        
        
        reseteaPalabra(x,25);
        strcpy(x,parseaPalabra((linea+indice),&indice));
        printf("X: %s\t",x);
        
        reseteaPalabra(decimal,5);
        strcpy(decimal,parseaPalabra((linea+indice),&indice));
        printf("DECIMAL: %s\t",decimal); 
        
        indice=0;
        
        fgets(linea,50+1,f);
    }
       
 fclose(f);
  }


