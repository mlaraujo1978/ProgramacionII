/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"


void create(STR_NODO **list){
   *list = NULL;
   }
   
STR_NODO *insertOrdered(STR_NODO **list, int legajo){
    // creación del nodo.
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->legajo = legajo;
    nodo->ste = NULL;
    // avanza hasta encontrar el nodo mayor respecto del nuevo
    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while(listAux != NULL && legajo > listAux->legajo){
        nodoAnt = listAux;
        listAux = listAux->ste;
    }
    if(nodoAnt == NULL){
       *list = nodo;
    }
    else {
       nodoAnt->ste = nodo;
    }
    nodo->ste = listAux;
    return nodo;
}

void ingresaDatoList (STR_NODO **list){
           
    STR_NODO *nodo =(STR_NODO*)malloc(sizeof(STR_NODO));
    int num;
    int i=0;
        
    while(i<3){
    printf("ingrese un numero/elemento a la lista: \t");
    scanf("%d",&num);
    nodo=insertOrdered(list,num);
    i++;
    }
    return;
}

void printList(STR_NODO *list){
   
    while(list != NULL){
        printf("\n El legajo de la lista es: %d\t", list->legajo);
        list = list->ste;
    }
    return;
}
int deleteFirst(STR_NODO **list){
    
    int dato; 
    STR_NODO *nodoAux = *list;
    
    *list=(*list)->ste;
    
    dato= nodoAux->legajo;
    free(nodoAux);
    
    return dato;
 }

STR_NODO * insertAtEnd(STR_NODO **list, int dato){
    // creación del nodo.
    
    STR_NODO *nodo =(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->legajo = dato;
    nodo->ste = NULL;
    // avanza hasta encontrar el último nodo de la lista
    STR_NODO *listAux = *list;
    
        while(listAux != NULL && listAux->ste != NULL){
        listAux = listAux->ste;
        
        }
    // contemplamos el caso de que la lista esté vacía.
        if(listAux == NULL){
        *list = nodo;
        }
        else {
        //insertamos el nuevo nodo al final de la lista
        listAux->ste = nodo;
        }
    //printf("El elemento insertado en el nodo es: %d/t/n", nodo->dato);
    return nodo;
}
void creaListC(STR_NODO **listA, STR_NODO **listB){
   
    STR_NODO *listC;
    create(&listC);

    STR_NODO *nodo=NULL;
      
    int legajoA=deleteFirst(listA);    
    int legajoB=deleteFirst(listB);   
        
    while(*listA != NULL && *listB!=NULL){
    
    if(legajoA<=legajoB){
    nodo=insertOrdered(&listC,legajoA);
    legajoA=deleteFirst(listA);          
    }
    else{insertOrdered(&listC,legajoB);
    legajoB=deleteFirst(listB);  
    }
    }    
            while(*listA != NULL){
    
            nodo=insertOrdered(&listC,legajoA);
            legajoA=deleteFirst(listA);
            }
            nodo=insertOrdered(&listC,legajoA);
                
                while(*listB != NULL){
    
                nodo=insertOrdered(&listC,legajoB);
                legajoB=deleteFirst(listB);
                }
    
                nodo=insertOrdered(&listC,legajoB);
                                 
    printList(listC);
return;    
}
