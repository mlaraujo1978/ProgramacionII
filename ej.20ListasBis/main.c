/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 25 de octubre de 2019, 14:27
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
 
 void printList(STR_NODO *list){
   
    while(list != NULL){
        printf("El Dato de la lista es: %d\n", list->dato);
        list = list->ste;
    }
    return;
}
 
void generaListC (STR_NODO **listA, STR_NODO **listB){
    
int num;
STR_NODO *listC=NULL;

    
    while(*listA!=NULL){
    num=(*listA)->dato;
    *listA = (*listA)->ste;
    insertAtEnd(&listC,num);
    }
    
    while(*listB!=NULL){
    num=(*listB)->dato;
    *listB = (*listB)->ste;
    insertAtEnd(&listC,num);
    }

printList(listC);

}


int main(int argc, char** argv) {
    
    int num;
        
    STR_NODO *listA;
    create(&listA);
    ingresaDatoenListado(&listA);
    
    STR_NODO *listB;
    create(&listB);
    ingresaDatoenListado(&listB);
   
    generaListC (&listA,&listB);
   
return (EXIT_SUCCESS);
}


