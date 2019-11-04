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

void ImprimeFile (FILE * f, char nF[10], char oT[4]){

STR_ALU alu;

f= openFile(nF, oT);  

fread(&alu, sizeof(STR_ALU), 1, f);
     
    while(!feof(f)){
    printf(" Legajo: %d\t Nombre y apellido: %s\t Dir.: %s\t Email: %s \n", alu.legajo, alu.nYa, alu.dir, alu.email);
    
    fread(&alu, sizeof(STR_ALU), 1, f);
}
fclose(f);  
 }

STR_NODOC * search(STR_NODOC *list, STR_CARRERA carrera){
    
    STR_NODOC *listAux = list;
    
    while (listAux!=NULL && listAux->codigoC != (atoi(carrera.codigoC))){
        listAux = listAux->ste;
    }
    return listAux;
}

STR_NODOC *insertOrderedC(STR_NODOC **list,STR_CARRERA carrera){
    
    STR_NODOC *new = (STR_NODOC*)malloc(sizeof(STR_NODOC));
    new->codigoC = atoi(carrera.codigoC);
    strncpy(new->nombreC,carrera.nombreC, 40);
    new->ste = NULL;
    
    STR_NODOC *listAux = *list;
    STR_NODOC *nodoAnt = NULL;
    
    while(listAux != NULL && (atoi(carrera.codigoC)) > listAux->codigoC){
        nodoAnt = listAux;
        listAux = listAux->ste;
    }
    if(nodoAnt == NULL){
       *list = new;
    }
    else {
       nodoAnt->ste = new;
    }
    
    new->ste = listAux;
    
    return new;
}

STR_NODOC * insertWithoutDuplicates(STR_NODOC **list, STR_CARRERA carrera){
        
    STR_NODOC *nodo = search(*list, carrera);
        
    if(nodo == NULL){
    nodo = insertOrderedC(list,carrera);
    }
   return nodo;
}

void insertOrderedA(STR_NODOA **list, int legajo){
    
    STR_NODOA *new = (STR_NODOA*)malloc(sizeof(STR_NODOA));
    new->legajo = legajo;
    printf(" El lejajo es: %d\t", new->legajo);
    new->ste = NULL;
    
    STR_NODOA *listAux = *list;
    STR_NODOA *nodoAnt = NULL;
    
    while(listAux != NULL && legajo> listAux->legajo){
        nodoAnt = listAux;
        listAux = listAux->ste;
    }
    if(nodoAnt == NULL){
       *list = new;
    }
    else {
       nodoAnt->ste = new;
    }
    new->ste = listAux;
    return;
}


void printList(STR_NODOC *listC){
   
    while(listC != NULL){
        printf("\n El codigo de la mat. es: %d\n", listC->codigoC);
        printf(" El nombre de la materia es: %s\n", listC->nombreC);
        listC = listC->ste;
    }
    return;
}

void printListCarrerasAlum(STR_NODOC *list){

    while(list != NULL){
        printf("\n La carrera es: %s\t", list->nombreC);
        printf(" El codigo de la carrera es: %d\t", list->codigoC);
        while(list->alum != NULL){
        printf("\n El legajo es: %d", list->alum->legajo);
        list->alum=list->alum->ste ;
    }
        list=list->ste;
    }
    return;
}

void CargaListasconDatosFile(FILE *f, STR_NODOC **list ){

f=openFile("carreras.txt","r+");
    
    char registro[47+1];
    char *token=(char*)malloc(sizeof(char)*40+1);
    
    STR_CARRERA carrera;
    
    int cont;
    int legajo;
    
    while(fgets(registro,47+1,f)!=NULL){
        
        cont=1;
        
        token=strtok(registro,",");
        memset(carrera.codigoC,'\0',3+1);
        strncpy(carrera.codigoC,token,3);
                        
        while(token!=NULL){
        
        token=strtok(NULL,",");
        cont++;
        
        if(cont==2){  
        legajo=atoi(token);
        }
        
        if(cont==3){  
        memset(carrera.nombreC,'\0',40+1);
        strncpy(carrera.nombreC,token, 40);
        }
        
        }
        
        STR_NODOC *nodoAux=insertWithoutDuplicates(list,carrera);
        
        insertOrderedA(&(nodoAux->alum), legajo);
    }

    return;
}

void GeneraFileSalida(FILE *fA, FILE *f,STR_NODOC *list){

    f=openFile("salida.txt", "w+");
    fA=openFile("alumnos.data", "rb+");
    
    STR_ALU alu;
    
    while(list != NULL){
             
        fprintf(f,"\n La carrera es: %s\t", list->nombreC);
        fprintf(f," Codigo de la carrera es: %d\t\n", list->codigoC);
        
        while(list->alum != NULL){
        
        fseek(fA,list->alum->legajo*(sizeof(STR_ALU)),SEEK_SET);
        fread(&alu,sizeof(STR_ALU),1,fA);
        fprintf(f,"\n Legajo:%d\t", list->alum->legajo);
        fprintf(f," Legajo: %d\t Nom. y Ape.: %s\t Email.: %s\t Dir.: %s\n", alu.legajo, alu.nYa, alu.email, alu.dir);
                
        list->alum=list->alum->ste ;
    }
        list=list->ste;
    }
       
    fclose(f);
    fclose(fA);
    return;
}

