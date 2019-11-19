#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "funciones.h"

STR_LISTA *creaNodo(STR_LISTA **list, double dato){

    STR_LISTA *nodoL=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    nodoL->num=dato;
    nodoL->ste=NULL;
    
    return nodoL;

}

int MaxPosNodo (STR_LISTA *list){

    STR_LISTA *listAux=list;
    double i=1;
    
    while(listAux!=NULL){
    
    //printf("El numero es: %fd", listAux->num); 
    listAux=listAux->ste;
        
    i++;
    
    }

return i;
}

void insertAtEnd (STR_LISTA **list, double dato){

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

STR_LISTA *readAt(STR_LISTA *list, double pos){

    STR_LISTA *listAux=list;
    STR_LISTA *nodoL=NULL;
    double i=0;
    
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

void cargaLista(STR_LISTA **list, int n, double numList[n]){

    int dato;
    double maxPosNodo=0;

    for (double i=0; i<n;i++){
    
        printf("Ingrese el numero:\n");
        scanf("%d", &dato);
        insertAtEnd(list,dato);
        maxPosNodo=i;
    }
     
    return;
}
   
double sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2 ){

    double maxPos=0;
    double maxPosL1=MaxPosNodo(list1);
    double maxPosL2=MaxPosNodo(list2);
    double suma=0;
    double base=10;
  
    for(double i=1;i<=maxPosL1;i++){
        
        STR_LISTA *nodoL1=readAt(list1,i);
        
        double potencia=maxPosL1-i;
        
        suma+= nodoL1->num * pow(base,potencia);
        
    }
                     
        for(double i=1;i<=maxPosL2;i++){
        
        STR_LISTA *nodoL2=readAt(list2,i);
        
        double potencia=maxPosL2-i;
        
        suma+= nodoL2->num * pow(base,potencia);
        
       }
    
    //printf("La suma suma es:%d", suma);   
    
return suma;   

}

void creaListaConSuma(double suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3){

    double cociente;
    double resto;
    double base=10;
    double maxPos;
    double maxPosL1=MaxPosNodo(list1);
    double maxPosL2=MaxPosNodo(list2);
   
          
    if(maxPosL1>maxPos){
        maxPos=maxPosL1;
    }   
        else{
        maxPos=maxPosL2;
        }

            for(double i=1;i<=maxPos;i++){
                
                double potencia=maxPos-i;
        
                if(i==1){
        
                cociente=suma/pow(base,potencia);
                insertAtEnd(list3,cociente);
        
                resto= suma % pow(base,potencia);
                
                }
        
                else{
            
                    if(resto>=10){
            
                    cociente=resto/(pow(base,potencia));
                    insertAtEnd(list3,cociente);
        
                    resto= resto % pow(base,(potencia));
                
                        if(resto<10){
                        insertAtEnd(list3,resto);
                        }
                
                    }
                }
            }

 
return;
}
