#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "funciones.h"

FILE * openFile(const char *nameF, const char *openT){

    FILE* f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}

bool validaPalindromo(STR_PILA **pal,STR_PILA **palInv ){
    
    STR_PILA *pAux=NULL;
    
    int cantIguales=0;
    int cantDif=0;
    char letra;
        
        while(!isEmpty(*pal)){
        
            letra=pop(pal);
            push(&pAux,letra);        
        }
    
             while(!isEmpty(pAux) && !isEmpty(*palInv)){
              
                if(pop(&pAux)==pop(palInv)){
                      
                cantIguales++;
                //printf("\nCantIguales: %d\t",cantIguales);
               
              }
                 else{
          
                cantDif++;
                //printf("\nCantDif: %d\t",cantDif);
                }
            }
    
    if(cantDif==0){
            
       return true;
            
    }
    
        else{
    
            return false;
            }

  }

void cargaPilasConPalabra(STR_PILA **pal,STR_PILA **palInv, const char *token){

    char *palab=(char*) malloc(sizeof(char)*20);
    memset(palab,'\0',20);
    int i=0;
    
                while(*token){
                
                *(palab+i)=*token;
                push(pal,*token);
                push(palInv,*token);
                token++;
                i++;
                }
                
                
 return;                   
}

void procesaFilePalabras(FILE *fP, FILE *fNP, STR_PILA **pal,STR_PILA **palInv){
              
    fP= openFile("Palabras.txt", "r+");
    fNP= openFile("Palindromos.txt","w+");
    
    char *linea=(char*) malloc(sizeof(char)*20);
    memset(linea,'\0',20);
    
    char *palab=(char*) malloc(sizeof(char)*20);
    memset(palab,'\0',20);
    
    char *token=NULL;
    
    int i=0;
            
    while(fgets(linea,20+1,fP)!=NULL){
        
            token=strtok(linea,"\n");
                
            palab=token;
            
            cargaPilasConPalabra(pal,palInv,token);    
             
            if(validaPalindromo(pal,palInv)){
            
            fprintf(fNP, "%s\n", palab);
                               
            }
         
    }
 
    fclose(fP);
    fclose(fNP);
return;   
}       
 
STR_PILA *creaNodoP(STR_PILA **p, char letra){

    STR_PILA *nodoP=(STR_PILA*)malloc(sizeof(STR_PILA));
    
    nodoP->letra=letra;
    //printf("\nLetra: %c\t",letra);
    nodoP->ste=NULL;
 
 return nodoP;
}

void push(STR_PILA **p, char letra){

    STR_PILA *nodoP=creaNodoP(p,letra);
 
    nodoP->ste=*p;
    *p=nodoP;
   
    return;
}

char pop(STR_PILA **p){

    char letra=(*p)->letra;
    
    //printf("\nLetra: %c\t",letra);
    
    STR_PILA *aux=*p;
    
    *p=aux->ste;
    
    free(aux);

    return letra;
}

bool isEmpty(STR_PILA *p){
    
return p==NULL;
}

void imprimeFileNoPalindormos(FILE *fNP){

    
fNP= openFile("Palindromos.txt","r+");


char *palabra=(char*) malloc(sizeof(char)*20);
    
    while(fgets(palabra,20+1,fNP)!=NULL){
        
        printf("La palabra palindromo es: %s", palabra);
        
        memset(palabra,'\0',20);
        
    }

}