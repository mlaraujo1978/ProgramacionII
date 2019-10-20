 /*
 * File:   main.c
 * Author: lourdes
 *
 * Created on 19 de octubre de 2019, 21:37
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
 printf("El elemento ingresado en cola es: %d\n", new->dato);
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

creacolaB (STR_QUEUE *colA, STR_QUEUE *colB){

STR_QUEUE colaB;
crear(&colaB);

int num;

while(!isEmpty(colA) && !isEmpty(colB)){

    while(!isEmpty(colA)){
        
        num=removeUno(colA);        
        add(&colaB, num);
        //printf("El elemento ingresado en colaB es: %d\n", num);
    
    }
    while(!isEmpty(colB)){
        num=removeUno(colB);  
        add(&colaB, num);
        //printf("El elemento ingresado en colaB es: %d\n", num);
    
    }
}
printf("La cantidad de elementos de la colaB es: %d\n", colaB.cant);

}


int main(int argc, char** argv) {

    STR_QUEUE colA;
    crear(&colA);
    cargaNumeros(&colA);
    printf("La cantidad de elementos de la colA es: %d\n", colA.cant); 
    
    STR_QUEUE colB;
    crear(&colB); 
    cargaNumeros(&colB);
    printf("La cantidad de elementos de la colB es: %d\n", colB.cant); 
     
    
    creacolaB(&colA,&colB);
      
            
    return (EXIT_SUCCESS);
}