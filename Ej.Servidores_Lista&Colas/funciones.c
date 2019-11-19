#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "funciones.h"

void create(STR_LISTA **lista){
*lista=NULL;
}

void crearCola(STR_Q *q){

    q->frente=NULL;
    q->fin=NULL;
    q->cantPedidos=0;
    q->cantCPU=0;
    q->cantES=0;
    q->maxCcES=0;
   
}

STR_LISTA *BuscaNodoMenorCantPedidos(STR_LISTA *lista){

    STR_LISTA *listAux=lista;
    STR_LISTA *nodoMenor=NULL;
    
    int menorCant;
    int i=1;
    
                while(listAux!=NULL){
            
                if(i==1){
                    menorCant=listAux->q.cantPedidos;
                    nodoMenor=listAux;
                }
                else{
                
                    if(listAux->q.cantPedidos<menorCant){
                        
                        menorCant=listAux->q.cantPedidos;
                        nodoMenor=listAux;
                    }
                
                }
            
                i++;    
                listAux=listAux->ste;
            
            }

    return nodoMenor;
}



STR_PEDIDO  ingresaPedido (STR_PEDIDO pedido){
    
        printf("\nIngrese el numero de id: \t"); 
        scanf("%d", &pedido.id);
        printf("Ingrese cantidad de ciclos: \t"); 
        scanf("%d", &pedido.cantCiclos); 
        printf("Ingrese tipo: CPU o E/S: \t"); 
        scanf("%s", pedido.tipo);       
           
 return pedido;       
}

void addQ(STR_Q *q, STR_PEDIDO pedido){

    STR_NODOQ *nodoq=(STR_NODOQ*)malloc(sizeof(STR_NODOQ));
    nodoq->pedido=pedido;
    nodoq->ste=NULL;
    
    q->cantPedidos++;
        
    if( strcmp(pedido.tipo,"CPU")==0 ){
        q->cantCPU++;
    }
    
    if( strcmp(pedido.tipo,"E/S")==0 ){
        q->cantES++;
        
        if(nodoq->pedido.cantCiclos>q->maxCcES){
            q->maxCcES=nodoq->pedido.cantCiclos;
        }
    }
    
    if(q->frente==NULL){
        q->frente=nodoq;
    }
        else{
        q->fin->ste=nodoq;
        }
    
    q->fin=nodoq;
}

STR_PEDIDO removeQ (STR_Q *q){

    STR_PEDIDO pedido;
    
    STR_NODOQ *aux=q->frente;
    q->frente=aux->ste;
    
    pedido= aux->pedido;
    
        q->cantPedidos--;
        
        if( strcmp(aux->pedido.tipo,"CPU")==0 ){
        q->cantCPU--;
        }
    
            if( strcmp(aux->pedido.tipo,"E/S")==0 ){
             q->cantES--;
             }
        
    free(aux);
   
    if(q->frente==NULL){
        q->fin=NULL;
    }   
    
return pedido;
    
}

bool isEmpty (STR_Q *q){

return q->frente==NULL && q->fin ==NULL;    

}

void insertAtEnd(STR_LISTA **lista, STR_PEDIDO pedido){

    int numNodo;
        
    STR_Q q;
    crearCola(&q);
    
    addQ(&q,pedido);
    
    STR_LISTA *nodol=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    nodol->q=q;
    nodol->ste=NULL;
    
    STR_LISTA *listAux=*lista;
            
    while (listAux!=NULL && listAux->ste!=NULL){
       
        listAux=listAux->ste;
    }
    
    if(listAux==NULL){
    *lista=nodol;
    numNodo=1;
    }
    else{
        listAux->ste=nodol;
        numNodo++;  
    }
    
return;    
}

void ingresaPedidoenCola (STR_LISTA **lista, STR_PEDIDO pedido, int n, int m){

    
        STR_LISTA *new=BuscaNodoMenorCantPedidos(*lista);
    
        if(new==NULL){
    
          insertAtEnd(lista, pedido);
              
        }
            else{
            
                if(new->q.cantPedidos<m){
            
                addQ(&new->q,pedido);
                
                } 
                else{
                
                    insertAtEnd(lista, pedido);
                }
            }
   return;   
}


void imprimeEstadisticasPedidos(STR_LISTA *lista){

    int porcCPU;
    int porcES;
    int MaxCPU=0;
    int MaxESCantCiclos=0;
    int i=1;
    int numNodoCPU;
    int numNodo;
    
    STR_LISTA *listAux=lista;
    
    
            while(listAux!=NULL){
                
            porcCPU=listAux->q.cantCPU/listAux->q.cantPedidos;   
            porcES=listAux->q.cantES/listAux->q.cantPedidos; 
            
            printf("\nCantidad de CPU:%d\t",listAux->q.cantCPU);
            //printf("Porc de CPU:%d\t",porcCPU);
            printf("Cantidad de E/S:%d\t",listAux->q.cantES);
            //printf("Porc de E/S:%d\t",porcES);
            
            if(listAux->q.cantCPU>MaxCPU){
            
            MaxCPU=listAux->q.cantCPU;
            numNodoCPU=i;
            }
                
                if(listAux->q.maxCcES>MaxESCantCiclos){
            
                    MaxESCantCiclos=listAux->q.maxCcES;
                    numNodo=i;
                }    
           
            i++;
            
            listAux=listAux->ste;
            
            }

                      
            printf("\nEl nodo con maxCPU es:%d\t",numNodoCPU); 
            printf(", cantidad CPU:%d\t",MaxCPU);
            printf("\nEl nodo E/S proceso mayor cant.ciclos es:%d\t",numNodo); 
            printf(", cantidad de ciclos:%d\t",MaxESCantCiclos);
            
}