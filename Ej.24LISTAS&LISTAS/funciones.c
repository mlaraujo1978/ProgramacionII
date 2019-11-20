#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

FILE * openFile(const char *nameF, const char *openT){

    FILE *f= fopen(nameF,openT);
    
    if(f==NULL){
    
        printf("El archivo no se pudo abrir");
        exit(1);
    
    }
    
    return f;
}


void imprimeFile(FILE * f){

STR_ALU alu;
    
f=openFile("ARCHA.data", "rb+");  
    
    fread(&alu,sizeof(STR_ALU), 1, f);   
            
        while(!feof(f)){
            
            printf("\nDIVISION:%hd\t", alu.div);
            
            printf("LEGAJO:%ld\t", alu.legajo);
                           
            printf("NOM. Y APELLIDO:%s\n", alu.nomYape);
                                   
            fread(&alu,sizeof(STR_ALU), 1, f);   
    }
fclose(f);  

}

STR_LISTA1 *insertOrdenadoDiv(STR_LISTA1 **list, int div){

    STR_LISTA1 *new=(STR_LISTA1*)malloc(sizeof(STR_LISTA1));
    new->div=div;
    //printf("\nDIV:%hd\t",new->div);
    new->ste=NULL;
    
    STR_LISTA1 *listAux=*list;
    STR_LISTA1 *nodoAnt=NULL;
    
    while(listAux!=NULL && div>listAux->div){
        nodoAnt=listAux;
        listAux=listAux->ste;
    
    }
    
    if(nodoAnt==NULL){
        *list=new;
    }
        else{
        
        nodoAnt->ste=new;
        }

new->ste=listAux;


}
       
void insertOrdenadoLegajo(STR_LISTA2 **list, int legajo, int pos){

    STR_LISTA2 *new=(STR_LISTA2*)malloc(sizeof(STR_LISTA2));
    new->legajo=legajo;
    
    //printf("\nLEGAJO:%ld\t",new->legajo);
    
    new->pos=pos;
    
   // printf("POS:%d\t",new->pos);
    
    new->ste;
    
    STR_LISTA2 *listAux=*list;
    STR_LISTA2 *nodoAnt=NULL;
    
    while(listAux!=NULL && legajo> listAux->legajo){
        nodoAnt=listAux;
        listAux=listAux->ste;
    
    }
    
    if(nodoAnt==NULL){
        *list=new;
    }
        else{
        
        nodoAnt->ste=new;
        }

    new->ste=listAux;
    
return;

}

STR_LISTA1 *BuscaNodoDiv(STR_LISTA1 *list, int div){

STR_LISTA1 *listAux=list;
    
    while(listAux!=NULL && listAux->div!=div){
    
        listAux=listAux->ste;
    
    }
return listAux;


}

STR_LISTA1 *insertSinDuplicadosDiv(STR_LISTA1 **list, int div){


    STR_LISTA1 *nodoL1=BuscaNodoDiv(*list,div);
    
    if(nodoL1==NULL){
    
        nodoL1=insertOrdenadoDiv(list,div);
    }
    
return nodoL1;

}

void cargaListaOrdenadaDivyLegajo(FILE *f,STR_LISTA1 **list){

STR_ALU alu;

int pos=0;
    
f=openFile("ARCHA.data", "rb+");  
    
    fread(&alu,sizeof(STR_ALU), 1, f);   
            
        while(!feof(f)){
            
            pos++;
            STR_LISTA1 *nodoAux=insertSinDuplicadosDiv(list,alu.div);
            insertOrdenadoLegajo(&nodoAux->legajo,alu.legajo, pos);
            
            fread(&alu,sizeof(STR_ALU), 1, f);   
    }
fclose(f);  

}

void ImprimeListas(FILE* f,STR_LISTA1 *list){

STR_ALU alu;

f=openFile("ARCHA.data", "rb+");  

STR_LISTA1 *listAux=list;
     
            
        while(listAux!=NULL){
        
           printf("\nDIVISION:%hd\t\n", listAux->div);
           
           while(listAux->legajo!=NULL){
           
               fseek(f,(sizeof(STR_ALU)*(listAux->legajo->pos-1)),SEEK_SET);
               fread(&alu,(sizeof(STR_ALU)), 1, f); 
               
               printf("\LEGAJO:%ld\t", listAux->legajo->legajo);
                           
               printf("\tNOM. Y APELLIDO:%s\n", alu.nomYape);
               
               listAux->legajo=listAux->legajo->ste;
           }
        
        listAux=listAux->ste;
        } 
            
 
fclose(f);  
return;
}