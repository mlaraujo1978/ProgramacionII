/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 20 de octubre de 2019, 17:41
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

bool isEmpty(STR_QUEUE *q){

    return q->frente== NULL && q->fin== NULL;
}


void add(STR_QUEUE *q, int d){

 STR_NODO *new=(STR_NODO*)malloc(sizeof(STR_NODO));
 
 new->dato=d;
 printf("El elemento ingresado en colA es: %d\n", new->dato);
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

void cargaNumeros (STR_QUEUE *q){
    
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

void push(STR_NODO **head, int numero){    
    
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->dato= numero;
    nodo->ste= NULL;
    
    nodo->ste=*head;
    *head=nodo;
return;
}

bool isEmptyP(STR_NODO *head){

    return head==NULL;
}

int pop (STR_NODO **head){
    
    int num=(*head)->dato;
     
     STR_NODO *aux=*head;
     
     *head=(*head)->ste;
     
     free(aux);
     
     return num;
}

int main(int argc, char** argv) {

    STR_QUEUE colA;
    crear(&colA);
    cargaNumeros(&colA);
    int num;
    
    STR_NODO *pila=NULL;
         
    printf(":.Impresion.\n"); 
    if(colA.cant>10){
        while(!isEmpty(&colA)){    
        num=removeUno(&colA);   
        printf("El elemento de la colA es: %d\n",num); 
        }
    }
    else{
        while(!isEmpty(&colA)){ 
        num=removeUno(&colA);
        push(&pila,num);
        }
        while(!isEmptyP(pila)){ 
        num=pop(&pila);
        add(&colA,num);
        }
         while(!isEmpty(&colA)){    
        num=removeUno(&colA);   
        printf("El elemento de la colA Invertida es: %d\n",num); 
        }
    }                
    return (EXIT_SUCCESS);
}