/*
 * To change this license header, choose License Headers in Project Properties.
  * File:   main.c
 * Author: lourdes
 * Created on 7 de octubre de 2019, 19:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
 */
typedef struct nodo{
    int valor;
    struct nodo *ste;
}STR_NODO;

void create (STR_NODO **head){
*head=NULL;
}

void push(STR_NODO **head, int numero){    
    
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->valor= numero;
    
    nodo->ste= NULL;
    
    nodo->ste=*head;
    *head=nodo;
return;
}

bool isEmpty(STR_NODO *head){

    return head==NULL;
}

int pop (STR_NODO **head){
    
    int numero=(*head)->valor;
     
     STR_NODO *aux=*head;
     
     *head=(*head)->ste;
     
     free(aux);
     
     return numero;
      
}


int main(int argc, char** argv) {
    
STR_NODO *head;
create (&head);

int num;

printf("Ingrese un numero: \t");fflush(stdin);
scanf("%d",&num);
    
    while(num!=0){
                
        push(&head,num);
        printf("Ingrese un numero: \t");fflush(stdin);
        scanf("%d",&num);
  }

STR_NODO *pilaAux;
create(&pilaAux);

while(!isEmpty(head)){
    num=pop(&head);
    push(&pilaAux, num);
    printf("\n Elemento agregado en Pila Aux.es :%d\t", num);
}

int i=0;
    while(i<2){
    printf("\n Elemento borrado de la Pila Aux. es: %d\t", pop(&pilaAux));
    i++;
     }

i=28;    
push(&head,i);
printf("\n Elemento agregado en head: %d\t", i);

while(!isEmpty(pilaAux)){
    num=pop(&pilaAux);
    push(&head,num);
    printf("\n Elemento agregado en head: %d\t", num);
}

return (EXIT_SUCCESS);
}

