#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "funciones.h"

FILE * openFile(char nameF[15], char openT[4]){

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
    char letraPaux;
    char letraP;
    char letra;
    
        while(!isEmpty(*pal)){
        
            letra=pop(pal);
            push(&pAux,letra);        
        }
    
             while(!isEmpty(pAux) && !isEmpty(*palInv)){
                 
                 letraPaux=pop(&pAux);
                 letraP=pop(palInv);
                 
                 
              if(letraPaux==letraP){
                 
               cantIguales++;
               
              }
                 else{
          
                cantDif++;
                
                }
            }
    
    if(cantDif==0){
            
       return true;
            
    }
    
        else{
    
            return false;
            }

  }

void procesaFilePalabras(FILE *fP, FILE *fNP, STR_PILA **pal,STR_PILA **palInv){
              
    fP= openFile("Palabras.txt", "r+");
    fNP= openFile("NoPalindromos.txt","w+");
    
    char letra;
    
    char *linea=(char*) malloc(sizeof(char)*20);
    memset(linea,'\0',20);
    
    char *palab=(char*) malloc(sizeof(char)*20);
    memset(palab,'\0',20);
    
    int i=0;
    int j=0;
        
    while(fgets(linea,20+1,fP)!=NULL){
        
                 
                while(*linea && *linea!='.'){
                
                *(palab+i)=*linea;
                push(pal,*linea);
                push(palInv,*linea);
                linea++;
                i++;
                j++;
                }
               
                    if(validaPalindromo(pal,palInv)){
                    //printf("La palabra palindromo es %s",palab);
                    fprintf(fNP, "%s\n", palab);
                               
                    }
          memset(palab,'\0',20);
          i=0;
          linea++;
          j++;
          linea=linea-j;
          j=0;
            
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

void imprimeFilePalindormos(FILE *fNP){

    
fNP= openFile("NoPalindromos.txt","r+");


char *palabra=(char*) malloc(sizeof(char)*20);
    
    while(fgets(palabra,20+1,fNP)!=NULL){
        
        printf("La palabra palindromo es: %s", palabra);
        
        memset(palabra,'\0',20);
        
    }

}