/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "funciones.h"

STR_LISTA *creaNodo(STR_LISTA **list, int num){
    
    STR_LISTA *new=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    new->num=num;
    new->ste=NULL;

return new;    
}

void insertAtEnd (STR_LISTA **list, int num){

    STR_LISTA *nodo=creaNodo(list,num);
    
    STR_LISTA *listAux=*list;
    
    while(listAux!=NULL && listAux->ste!=NULL){
    
        listAux=listAux->ste;
    }

        if(listAux==NULL){
    
            *list=nodo;
        }
    
        else{
        
            listAux->ste=nodo;
        }
return;
}

void cargaLista(STR_LISTA **list){

    int num;
    
    printf("Ingrese un numero entero positivo, (-1 para termninar):\n");
    scanf("%d", &num);
    
    while (num>=0){
       
        insertAtEnd(list,num);
        
        printf("Ingrese un numero entero positivo, (-1 para termninar):\n");
        scanf("%d", &num);
              
    }
     
    return;
}

int cuentaNodos (STR_LISTA *list){

    STR_LISTA *listAux=list;
    
    int i=0;
    
    while(listAux!=NULL){
    
        i++;
        listAux=listAux->ste;
    
    }

    return i;
}

STR_LISTA *BuscaNodoPos(STR_LISTA *list, int pos){

    STR_LISTA *listAux=list;
    
    STR_LISTA *nodo=NULL;
       
    int i=0;
    
    while(i<pos && listAux!=NULL){
    
        nodo=listAux;
        listAux=listAux->ste;
    
        i++;
    }

    if(i<pos && listAux==NULL){
    
        return NULL;
    }
return nodo;
}

int sumaLista(STR_LISTA *list, int cantNodos){

    int suma=0;
    int potencia=cantNodos-1;
    int base=10;
    
    
    for(int i=0;i<cantNodos;i++){
    
        STR_LISTA *nodo=BuscaNodoPos(list,i+1);
        suma+=nodo->num * pow(base,potencia-i);
    
    }

return suma;
}

int sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2){

    int cantNodosL1= cuentaNodos(list1);
    int cantNodosL2= cuentaNodos(list2);

    int suma1=sumaLista(list1,cantNodosL1);
    int suma2=sumaLista(list2,cantNodosL2);
    
    int suma=suma1+suma2;
    
return suma;    

}

void creaListaConSuma(int suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3){

    
    int cantNodosL1= cuentaNodos(list1);
    int cantNodosL2= cuentaNodos(list2);
    int cantNodoMax=0;
    int cociente=0;
    int resto=0;
    int base=10;
    int potencia=cantNodoMax-1;
    
    if(cantNodosL1>cantNodoMax){
        
    cantNodoMax=cantNodosL1;
    
    }
        else{
        
        cantNodoMax=cantNodosL2;
    
        }
    
        for(int i=0;i<cantNodoMax;i++){
    
        if(i==0){
            cociente=suma/ (pow(base,potencia-i));
            insertAtEnd(list3,cociente);
            
            resto=suma % ( pow (base, potencia-i));
            
            if(resto<10){
            insertAtEnd(list3,resto);
            }
        
        }    
            else{
                
                if(resto>=10){
            
                cociente=resto/(pow(base,potencia-i));
                insertAtEnd(list3,cociente);
                
                resto=resto % (pow (base, potencia-i));
                
                if(resto<10){
                insertAtEnd(list3,resto);
                }
                
              }
                
            }
    
        }
    return;

}

void imprimeLista(STR_LISTA *list){
    
STR_LISTA *listAux=list;
    
    printf("\n La suma que representa la lista3 es: %d\t",listAux->num);
    
    while(listAux!=NULL){
        
        printf("El numero es: %d",listAux->num);
            
        listAux=listAux->ste;
    
    }

return;
}