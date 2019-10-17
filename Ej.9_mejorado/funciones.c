#include "funciones.h"

STR_NODO *crearNodo(int dato){
    
    STR_NODO *nodo=(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->numero = dato;
    nodo->ste = NULL;

    return nodo;
}

void push(STR_NODO **pila, int dato){
    STR_NODO *nodo = crearNodo(dato);
    nodo->ste = *pila;
    *pila = nodo;
}

int pop(STR_NODO **pila){
    
    STR_NODO *aux = *pila;
    int dato = (*pila)->numero;

    *pila = aux->ste;
    free(aux);
    
    return dato;
}

bool isEmpty(STR_NODO *head){

    return head==NULL;
}

void ordenarPila(STR_NODO **pila){
    
    STR_NODO *aux = NULL;
    STR_NODO *aux2 = NULL;

    int numero = pop(pila);
    push(&aux, numero);
    
        while( !isEmpty(*pila)) {   
            
            numero = pop(pila);
            
            while(!isEmpty(aux) && numero >= aux->numero) {       
                
                push(&aux2, pop(&aux));
            }
            
            push(&aux, numero);
            
            while(!isEmpty(aux2))  {   
              
                push(&aux, pop(&aux2));
            }
            
        }

        while(!isEmpty(aux))  {
        int num=pop(&aux);  
        push(pila,num);
        printf("\n Elementos pila aux: %d\n", num);
        }
        
}