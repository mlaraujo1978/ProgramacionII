/* 
 * File:   main.c
 * Author: lourdes
 * Created on 25 de octubre de 2019, 09:15
 */
#include <stdio.h>
#include <stdlib.h>

   typedef struct nodo{
   int dato;
   struct nodo *ste;
   } STR_NODO;

   void create(STR_NODO **list){
   *list = NULL;
   }
   
    STR_NODO * insertAtEnd(STR_NODO **list, int dato){
    // creación del nodo.
    
    STR_NODO *nodo =(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->dato = dato;
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
    
    void ingresaDatoenListado (STR_NODO **list){
           
    STR_NODO *nodo =(STR_NODO*)malloc(sizeof(STR_NODO));
    int num;
    int i=0;
    
    while(i<3){
    printf("ingrese un numero/elemento a la lista: \t");
    scanf("%d",&num);
    nodo=insertAtEnd(list,num);
    i++;
    }
    return;
    }
    
    void ingresaDatoenListadoC (STR_NODO **list,STR_NODO *nodo){
           
    nodo=insertAtEnd(list,nodo->dato);
    
    return;
    }
    
 STR_NODO *readAt(STR_NODO **list, int pos){
    
    STR_NODO *listAux = *list;
    STR_NODO *nodo = NULL;
    
    int i = 0;
    while( i < pos && listAux != NULL) {
        nodo = listAux;
        listAux = listAux->ste;
    i++;
    }
    if(i < pos && listAux == NULL){
    return NULL;
    }
    
 return nodo;
 }
 
 int deleteFirst(STR_NODO **list){
    
    int dato; 
    STR_NODO *nodoAux = *list;
    
    *list=(*list)->ste;
    
    dato= nodoAux->dato;
    free(nodoAux);
    
    return dato;
 }

int main(int argc, char** argv) {
    
    int num;
        
    STR_NODO *listA;
    create(&listA);
    ingresaDatoenListado(&listA);
    
    STR_NODO *listB;
    create(&listB);
    ingresaDatoenListado(&listB);
    
    STR_NODO *listC;
    create(&listC);
    STR_NODO *nodo =NULL;
    
    
    while (listA!=NULL){
    num=deleteFirst(&listA);
    insertAtEnd(&listC,num);
    }
    
    while (listB!=NULL){
    num=deleteFirst(&listB);
    insertAtEnd(&listC,num);
    }
    
    while(listC != NULL){
        printf("El dato de lista C es: %d\n",  listC->dato);
        listC = listC->ste;
    }
    
    return (EXIT_SUCCESS);
}

