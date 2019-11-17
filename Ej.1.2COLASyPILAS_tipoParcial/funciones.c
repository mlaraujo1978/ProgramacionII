#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"

STR_PILA *creaNodoP(STR_PILA **p, int dato){

    STR_PILA *nodoP=(STR_PILA*)malloc(sizeof(STR_PILA));
    
    nodoP->dato=dato;
    nodoP->ste=NULL;
 
 return nodoP;
}

void push(STR_PILA **p, int dato){

    STR_PILA *nodoP=creaNodoP(p,dato);
 
    nodoP->ste=*p;
    *p=nodoP;
   
    return;
}

int pop(STR_PILA **p){

    int dato=(*p)->dato;
    
    STR_PILA *aux=*p;
    
    *p=aux->ste;
    
    free(aux);

    return dato;
}

bool isEmptyP(STR_PILA *p){
    
return p==NULL;
}

void inicializaCola(STR_Q *q){

    q->frente=NULL;
    q->fin=NULL;

}

STR_NODOQ *creaNodoQ(STR_NODOQ *nodoq, int dato){

    STR_NODOQ *nodoQ=(STR_NODOQ*)malloc(sizeof(STR_NODOQ));
    nodoQ->dato=dato;
    nodoQ->ste=NULL;
 
 return nodoQ;
}

void add (STR_Q *q, int dato){

    STR_NODOQ *nodoQ=creaNodoQ(nodoQ,dato);
      
    if(q->frente==NULL){
    
        q->frente=nodoQ;
    }
        else{

        q->fin->ste=nodoQ;
        }
    
    q->fin=nodoQ;
    
return;
}    
    
int removeUno(STR_Q *q){

    int dato;
    
    STR_NODOQ *aux=q->frente;
    
    q->frente=aux->ste;  
    
    dato=aux->dato;
   
    free(aux);
    
        if(q->frente==NULL){
   
        q->fin=NULL;
        }
  
return dato;
}


bool isEmptyQ(STR_Q *q){
    
return q->frente==NULL && q->fin==NULL;
}

void creaColaA(STR_Q *colA,int numCA[4]){
        
    for(int i=0; i<4;i++){
        printf("\nEl numero de la colA es:%d\t", numCA[i]);
        add(colA,numCA[i]);   
        
    }
return;
    
}

void creaColaB(STR_Q *colB,int numCB[4]){
 
    for(int i=0; i<4;i++){
        printf("\nEl numero de la colB es: %d\t", numCB[i]);
        add(colB,numCB[i]);  
    }
return;
}

void GeneraPilaconColas (STR_Q *colA,STR_Q *colB,STR_PILA **p){

 STR_PILA *pAux=NULL;
    
    int dato;
    
    while(!isEmptyQ(colA)){
    
        dato=removeUno(colA);
        push(&pAux,dato);
    }
    
        while(!isEmptyP(pAux)){
    
            dato=pop(&pAux);
            push(p,dato); 
        }
    
            while(!isEmptyQ(colB)){
              dato=removeUno(colB);
              push(p,dato);                
            }

    return;  

}


void imprimePila(STR_PILA **p){

    int dato;
    
        while(!isEmptyP(*p)){
            dato=pop(p);
            printf("\nEl numero de la pila es: %d\t", dato);
        }

}
