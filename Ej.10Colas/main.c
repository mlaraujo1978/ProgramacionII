/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 18 de octubre de 2019, 10:49
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

while(i<4){
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


void EliminaDosNodos (STR_QUEUE *q, char letra){
 
int eliminados=0;
int num;

while(q->frente!=NULL && eliminados<2){
    num=removeUno(q);
    printf("El elemento eliminado de la cola es:%d\n", num);
    eliminados++;
    }

    if( eliminados==2){
        letra='S';
    }
    else{
         letra='N'; 
    }
printf("Se eliminaron los dos nodos:%c\t", letra);
}


int main(int argc, char** argv) {

    STR_QUEUE queue;
    
    crear(&queue);
      
    cargaNumeros(&queue);
    
    char parametro;
    
    EliminaDosNodos(&queue, &parametro);
    
    printf(" Se eliminaron los dos nodos: %c\t", parametro);   
    
    
    return (EXIT_SUCCESS);
}


