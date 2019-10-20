/* 
 * File:   main.c
 * Author: lourdes
 * Created on 17 de octubre de 2019, 19:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int dato;
  struct nodo *ste;  
}STR_NODO;

typedef struct{
    STR_NODO *frente;
    STR_NODO *fin;
    int cant;  
}STR_QUEUE;

void crear (STR_QUEUE *q){

    q->frente=NULL;
    q->fin=NULL;
    q->cant=0;
            
}

void add (STR_QUEUE *q, int d){

 STR_NODO *new=(STR_NODO*)malloc(sizeof(STR_NODO));
 
 new->dato=d;
 new->ste=NULL;
 q->cant++;
 
 if(q->frente==NULL){
     q->frente=new;
 }
 else{
     q->fin->ste=new; 
 }
    q->fin=new;
                
}

void cargaNumeros (STR_QUEUE * q){
    
srand(time(NULL));

int i=0;

while(i<5){
add(q,rand()%100);
i++;
}

return;
}


int removeUno (STR_QUEUE *q){

 STR_NODO *aux= q->frente;
 
int dato= aux->dato;
 
 q->frente=aux->ste;
 q->cant--;
 aux->ste=NULL;
 free(aux);
 
 if(q->frente==NULL){
     q->fin=NULL;
 }
 return dato;                
}


int main(int argc, char** argv) {

    STR_QUEUE queue;
    
    crear(&queue);
      
    cargaNumeros(&queue);
    
    printf("La cantidad de elementos de la cola es: %d\n", queue.cant);    
    
    return (EXIT_SUCCESS);
}

