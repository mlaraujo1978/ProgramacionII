
/* Author: lourdes
 *
 * Created on 9 de diciembre de 2019, 10:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

typedef struct nodoL{
   char letra;
   struct nodoL *ste;
}STR_LISTA;

typedef struct{
    STR_LISTA *list;
}STR_VEC;

typedef struct nodoP{
    char letra;
    struct nodoP *ste;
}STR_PILA;

FILE * openFile(const char *nameF,const char *openT){

    FILE* f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}


STR_PILA *creaNodoP( char letra){

    STR_PILA *nodoP=(STR_PILA*)malloc(sizeof(STR_PILA));
    
    nodoP->letra=letra;
    //printf("\nLetra: %c\t",letra);
    nodoP->ste=NULL;
 
 return nodoP;
}

void push(STR_PILA **p, char letra){

    STR_PILA *nodoP=creaNodoP(letra);
 
    nodoP->ste=*p;
    *p=nodoP;
   
    return;
}
char pop(STR_PILA **p){

    char letra=(*p)->letra;
    
    printf("\nLetra: %c\t",letra);
    
    STR_PILA *aux=*p;
    
    *p=aux->ste;
    
    free(aux);

    return letra;
}    
    
bool isEmpty(STR_PILA *p){
    
return p==NULL;
}

STR_LISTA *insertAtEnd(STR_LISTA **list,char letra){
    
    
    STR_LISTA *nodo =(STR_LISTA*)malloc(sizeof(STR_LISTA));
    nodo->letra = letra;
    nodo->ste = NULL;
  
    STR_LISTA *listAux = *list;
    
        while(listAux != NULL && listAux->ste != NULL){
        listAux = listAux->ste;
        
        }
    
    if(listAux == NULL){
        *list = nodo;
        }
        else {
        
        listAux->ste = nodo;
        }
    
    return nodo;
}

void cargaPilaConLista(STR_VEC *vec[],int n,STR_PILA **p1,STR_PILA **p2){

    STR_LISTA *listAux=vec;
    
    for(int i=0;i<n;i++){
    
        while(listAux!=NULL){
        
            push(p1,vec[i]->list->letra);
            push(p1,vec[i]->list->letra);
            
        listAux=listAux->ste;
        }
    
      
    }

    return;

}

bool validaSiPalabraEsPalindromo(STR_PILA **p1,STR_PILA **p2){

STR_PILA *pAux=NULL;
    
    int cantIguales=0;
    int cantDif=0;
    
        while(!isEmpty(*p2)){
            push(&pAux,pop(p2)); 
           
        }
    
             while(!isEmpty(*p1) && !isEmpty(pAux)){
               
              if(pop(p1)==pop(&pAux)){
                  
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

/*
 * 
 */
int main(int argc, char** argv) {
    
    STR_VEC *vec[5];
    
     for(int i=0;i<5;i++){
    
      vec[i]=(STR_VEC*)malloc(sizeof(STR_VEC));
    
   }
    
    STR_PILA *p1=NULL;
    STR_PILA *p2=NULL;
    
    FILE *fP= openFile("Palabras.txt", "r+");

     
    char *linea=(char*) malloc(sizeof(char)*20);
    memset(linea,'\0',20);
    
    char *palabra=(char*) malloc(sizeof(char)*20);
    memset(palabra,'\0',20);
    
    int i=0;
    int j=0;
    int k=0;
    
    
    while(fgets(linea,20+1,fP)!=NULL){
        
       
       memset(palabra,'\0',20);
        
                        
        while(*linea && *linea!='.'){
                
                *(palabra+i)=*linea;
                
               insertAtEnd(vec[k]->list,*linea);
                
               linea++;
                i++;
                j++;
        }
        printf("PALABRA %s",palabra);
        i=0;
        linea++;
        j++;
        linea=linea-j;
        j=0;
        k++;            
       
    }
 
    fclose(fP);

    cargaPilaConLista(vec,5,&p1,&p2);
    
    if(validaSiPalabraEsPalindromo(&p1,&p2)){
               printf("La palabra es palindromo");
    }
    
        else{
               printf("La palabra no es palindromo");
        }
            
    return (EXIT_SUCCESS);
}

