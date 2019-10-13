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
    //printf("\n Elemento agregado en la head es :%d\t", numero);
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

srand(time(NULL));
int i=0;

while(i<4){
   push(&head,rand()%100);
    i++;
}

STR_NODO *pilaAux;
create(&pilaAux);

while(!isEmpty(head)){
    num=pop(&head);
    push(&pilaAux, num);
    printf("\n Elemento agregado en Pila Aux.es :%d\t", num);
}

int cont=0;
    while(!isEmpty(pilaAux)){
    cont++;
    if(cont==3){
    i=28;    
    push(&head,i);
    printf("\n Elemento agregado en head: %d\t", i);
    }
    else{
    num=pop(&pilaAux);
    push(&head,num);
    printf("\n Elemento agregado en head: %d\t", num);
    }
}
return (EXIT_SUCCESS);
}