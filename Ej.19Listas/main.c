/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 25 de octubre de 2019, 13:04
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
    
int calculaCantNodos(STR_NODO *list){
    
int cant=0;

    while (list!=NULL){
    list->dato;
    list = list->ste;
    cant++;   
    }
return cant;
}

void printList(STR_NODO *list){
   
    while(list != NULL){
        printf("El Dato de la listA es: %d\n", list->dato);
        list = list->ste;
    }
    return;
}
        
    
int main(int argc, char** argv) {
     
    STR_NODO *listA;
    create(&listA);
    ingresaDatoenListado(&listA);
      
   printf("La cantidad de nodos de la lista A es: %d\n", calculaCantNodos(listA));
    
   printList(listA);
    
    
 return (EXIT_SUCCESS);
}


