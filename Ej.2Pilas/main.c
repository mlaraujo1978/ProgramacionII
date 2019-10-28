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

void ingresaDatosenPila(STR_NODO **pila){

int num;

srand(time(NULL));
int i=0;

while(i<4){
   num=rand()%100;
   push(pila,num);
    printf("\n Elemento de la Pila es :%d\t", num);
    i++;
}
return;
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

void insertaTercerPos(STR_NODO **pila){

    
STR_NODO *pilaAux;
create(&pilaAux);

int num;
int i;

while(!isEmpty(*pila)){
    num=pop(pila);
    push(&pilaAux, num);
    printf("\n Elemento agregado en Pila Aux.es :%d\t", num);
}

int cont=0;
int pos=0;
    while(!isEmpty(pilaAux)){
    cont++;
    pos++;
    if(cont==3){
    i=28;    
    push(pila,i);
    printf("\n Elemento agregado en  la pila es: %d\t", i);
    printf("\n la posicion es: %d\t", pos);
    }
    else{
    num=pop(&pilaAux);
    push(pila,num);
    printf("\n Elemento de la pila es: %d\t", num);
    printf("\n la posicion es: %d\t", pos);
    }
}
}

int main(int argc, char** argv) {
    
STR_NODO *pila;
create (&pila);
ingresaDatosenPila(&pila);

insertaTercerPos(&pila);

return (EXIT_SUCCESS);
}