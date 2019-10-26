#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

FILE * openFile(char nF[15], char oT[4]){

    FILE* f=fopen(nF, oT);
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}

void IniciaFileBin (FILE * f,char nF[15], char oT[4]){
    
    f=openFile(nF, oT);
    
    STR_ALU alu;
    
        alu.div=1;
        strcpy(alu.nomYape, "PEPE PEREZ");
        //alu.legajo=I+1;
                
    for (int i=0; i<5;i++){
       
        alu.legajo=i+1;
             
    fwrite(&alu,sizeof(STR_ALU), 1, f);
    }
    fclose(f);
}

void ImprimeFile (FILE * f, char nF[10], char oT[4]){

STR_ALU alu;

f= openFile(nF, oT);  

fread(&alu, sizeof(STR_ALU), 1, f);
     
    while(!feof(f)){
    printf("Nombre y apellido: %s\t Legajo: %d\t Division: %hd\t \n", alu.nomYape, alu.legajo, alu.div);
    
    fread(&alu, sizeof(STR_ALU), 1, f);
}
fclose(f);  
 }

void createList(STR_NODO **list){
   *list = NULL;
   }
   
STR_NODO *insertOrdered(STR_NODO **list, int legajo, int pos){
    // creación del nodo.
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->legajo = legajo;
    nodo->pos = pos;
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

    void ingresaDatoenListado (STR_NODO **list, FILE *f){
           
    STR_NODO *nodo =(STR_NODO*)malloc(sizeof(STR_NODO));
    
    int pos=0;
    
    STR_ALU alu;

    f= openFile("ARCHA.data", "rb+");  

    fread(&alu, sizeof(STR_ALU), 1, f);
        
    while(!feof(f)){
    nodo=insertOrdered(list,alu.legajo, pos);
    pos++;
    fread(&alu, sizeof(STR_ALU), 1, f);
    }
    return;
    }
    
void printList(STR_NODO *list){
   
    while(list != NULL){
        printf("La posicion de la listA es: %d\t", list->pos);
        printf("El Dato de la listA es: %d\n", list->legajo);
        list = list->ste;
    }
    return;
}

int deleteFirst(STR_NODO **list){
    
    int dato; 
    STR_NODO *nodoAux = *list;
    
    *list=(*list)->ste;
    
    dato= nodoAux->pos;
    free(nodoAux);
    
    return dato;
 }

void generaFileOrdenado(FILE *f, STR_NODO **list,FILE *fO){

    int pos;
    
    STR_ALU alu;

    f= openFile("ARCHA.data", "rb+");  
    fO= openFile("ARCHL.data", "wb+");  

    while(*list!=NULL){
        
        pos=deleteFirst(list);
        
        fseek(f,pos*(sizeof(STR_ALU)), SEEK_SET);
        
        fread(&alu, sizeof(STR_ALU), 1, f);
        
        fwrite(&alu,sizeof(STR_ALU), 1, fO);
        
    }   

}

