/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 18 de noviembre de 2019, 11:46
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct nodoL{
    int num;
    struct nodoL *ste;
}STR_LISTA;


STR_LISTA *creaNodo(STR_LISTA **list, int dato);

int MaxPosNodo (STR_LISTA *list);

void insertAtEnd (STR_LISTA **list, int dato);

STR_LISTA *readAt(STR_LISTA *list, int pos);

void cargaLista(STR_LISTA **list, int n, int numList[n]);
   
int sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2);
    
void creaListaConSuma(int suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3);
 

int main(int argc, char** argv) {
    
    STR_LISTA *list1=NULL;
    STR_LISTA *list2=NULL;
    STR_LISTA *list3=NULL;
    
    int n1;
    int n2;
    
    printf("Inserta la cantidad de elementos lista 1:\n");
    scanf("%d", &n1);
    printf("Inserta la cantidad de elementos lista 2:\n");
    scanf("%d", &n2);
 
    int numLA[n1];
    int numLB[n2];
    
    int suma=0;
     
    cargaLista(&list1,n1, numLA);
    
    cargaLista(&list2, n2, numLB);
    
    suma=sumaNumerosDeListas(list1, list2);
    
    //creaListaConSuma(suma,list1, list2, &list3);
    

    return (EXIT_SUCCESS);
    
}

STR_LISTA *creaNodo(STR_LISTA **list, int dato){

    STR_LISTA *nodoL=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    nodoL->num=dato;
    nodoL->ste=NULL;
    
    return nodoL;

}

int MaxPosNodo (STR_LISTA *list){

    STR_LISTA *listAux=list;
    int i=0;
    
    while(listAux!=NULL){
    
    printf("El numero es: %d", listAux->num); 
    listAux=listAux->ste;
        
    i++;
    
    }

    return i;
}

void insertAtEnd (STR_LISTA **list, int dato){

    STR_LISTA *nodoL=creaNodo(list,dato);
    
    STR_LISTA *listAux=*list;
    
    while(listAux!=NULL && listAux->ste!=NULL){
    
        listAux=listAux->ste;
    }

    if(listAux==NULL){
    
    *list=nodoL;
    }
        else{
        listAux->ste=nodoL;
        }
    
return;
}

STR_LISTA *readAt(STR_LISTA *list, int pos){

    STR_LISTA *listAux=list;
    STR_LISTA *nodoL=NULL;
    int i=0;
    
    while(i<pos && listAux!=NULL){
        nodoL=listAux;
        listAux=listAux->ste;
        i++;
    }
  
    if(i<pos && listAux==NULL){
    
        return NULL;
    }

    return nodoL;
}

void cargaLista(STR_LISTA **list, int n, int numList[n]){

    int dato;
    int maxPosNodo=0;

    for (int i=0; i<n;i++){
    
    printf("Ingrese el numero:\n");
    scanf("%d", &dato);
    insertAtEnd(list,dato);
    maxPosNodo=i;
    }
     
    return;
}
   
int sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2 ){

    int maxPos=0;
    int maxPosL1=MaxPosNodo(list1);
    int maxPosL2=MaxPosNodo(list2);
    int suma=0;
    
       
    if(maxPosL1>maxPos){
        maxPos=maxPosL1;
    }   
        else{
        maxPos=maxPosL2;
         }

    for(int i=0;i<=maxPos;i++){
        
        STR_LISTA *nodoL1=readAt(list1,i);
        STR_LISTA *nodoL2=readAt(list2,i);
        
                
        if(nodoL1!=NULL && nodoL2!=NULL){
        
            suma+= nodoL1->num * pow(10,(i+maxPos)) + nodoL2->num * pow(10,(i+maxPos));
        }
        
         if(nodoL1!=NULL){
        
            suma+=nodoL1->num * pow(10,(i+maxPos));
        }
        
         if(nodoL2!=NULL){
        
            suma+=nodoL2->num * pow(10,(i+maxPos));
        }
        
        
    }
    
 printf("La suma suma es:%d", suma);   
    
return suma;   

}
    
void creaListaConSuma(int suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3){

    int cociente;
    int resto;
    int maxPos=0;
    int maxPosL1=MaxPosNodo(list1);
    int maxPosL2=MaxPosNodo(list2);
   
          
    if(maxPosL1>maxPos){
        maxPos=maxPosL1;
    }   
        else{
        maxPos=maxPosL2;
        }

    for(int i=0;i<=maxPos;i++){
        
        if(i==0){
        
        cociente=suma/pow(10,(maxPos-i));
        insertAtEnd(list3,cociente);
        
        resto= cociente % pow(10,(maxPos-i));
                
        }
        
            else{
            
                if(resto>=10){
            
                cociente=resto/(pow(10,maxPos-i));
                insertAtEnd(list3,cociente);
        
                resto= resto % pow(10,(maxPos-i));
                
                    if(resto<10){
                    insertAtEnd(list3,resto);
                    }
                
                }
            }
    }

 maxPos=MaxPosNodo(*list3);   
    
return;
}
    