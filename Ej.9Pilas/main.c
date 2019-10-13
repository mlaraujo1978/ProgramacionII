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

STR_NODO *headA;
create(&headA);

STR_NODO *headO;
create(&headO);

STR_NODO *headAA;
create(&headAA);

int num;
int menorV=0;
int cantO=0;
int cantE=0;
int i=0;

printf("Ingrese un numero: \t");fflush(stdin);
scanf("%d",&num);
    
    while(num!=0){
                
        push(&head,num);
        printf("Ingrese un numero: \t");fflush(stdin);
        scanf("%d",&num);
    }
    
    while(!isEmpty(head)){
    cantE++;
    num=pop(&head);
    push(&headA,num);
    printf("\n Inserta en la Pila Aux el valor: %d\t", num);
    }

printf("\n La cant. de elementos de la pila son: %d\t", cantE);
    
    while (cantO<cantE){
        
        while(!isEmpty(headA)){
        i++;
        num=pop(&headA);
        
            if(i==1 || num<menorV){
            if(i==1){
            menorV=num;
            push(&headO,menorV);
            cantO++;
            }
            else{
            pop(&headO);
            push(&head,menorV);
            menorV=num;
            push(&headO,menorV);
            }
            }
            else{
            push(&head,num); 
            }
        }
        i=0;
        
       while(!isEmpty(head)){
        i++;
        num=pop(&head);
        
            if(i==1 || num<menorV){
            if(i==1){
            menorV=num;
            push(&headO,menorV);
            cantO++;
            }
            else{
            pop(&headO);
            push(&headA,menorV);
            menorV=num;
            push(&headO,menorV);
            }
            }
            else{
            push(&headA,num); 
            }
        }
    }

cantE=0;

while(!isEmpty(headO)){
    cantE++;
    num=pop(&headO);
    push(&headAA, num);
    printf("\n Inserta en la Pila Aux. Dos el valor: %d\t", num);fflush(stdin);
    }

while(!isEmpty(headAA)){
    cantE++;
    num=pop(&headAA);
    push(&headO, num);
    printf("\n Inserta en la Pila Ordenada el valor: %d\t", num);fflush(stdin);
    }

return (EXIT_SUCCESS);
}