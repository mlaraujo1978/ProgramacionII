#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

FILE * openFile(char nameF[10], char openT[4]){

    FILE* f=fopen(nameF, openT);
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}

void ImprimeFile (FILE * f, char nameF[10], char openT[4]){

STR_ALU alu;

f= openFile(nameF, openT);  

fread(&alu, sizeof(STR_ALU), 1, f);
     
    while(!feof(f)){
    printf("Legajo: %d\t Nombre y apellido: %s\t Dir.: %s\t Email: %s \n", alu.legajo, alu.nYa, alu.dir, alu.email);
    
    fread(&alu, sizeof(STR_ALU), 1, f);
}
fclose(f);  
 }

void ImprimeFileS (FILE * f, char nameF[10], char openT[4]){

f= openFile(nameF, openT);  

char *datos=(char*)malloc(sizeof(char)*122);
     
    while((fgets(datos,122+1,f))!=NULL ){
    printf("%s", datos);
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
        printf("\n El codigo de la carrera. es: %d\n", listC->codigoC);
        printf(" El nombre de la carrera es: %s\n", listC->nombreC);
        listC = listC->ste;
    }
    return;
}

void printListCarrerasAlum(STR_NODOC *list){

STR_NODOC *listAux=list;    
    
    while(listAux != NULL){
        
        printf("\nLa carrera es: %s\t", listAux->nombreC);
        printf("El codigo de la carrera es: %d\t", listAux->codigoC);
        
        while(listAux->alum != NULL){
        
            printf("\nEl legajo es: %d", listAux->alum->legajo);
            
            listAux->alum=listAux->alum->ste ;
        }
        
        listAux=listAux->ste;
    }
    return;
}

void CargaListasconDatosFile(FILE *f, STR_NODOC **list ){

f=openFile("carreras.txt","r+");
    
    char *registro=(char*)malloc(sizeof(char)*47);
    char *token=NULL;
    
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
        
        //printf("\nLa carrera es:%s", list->nombreC);
        fprintf(f,"\nCodigo de la carrera es: %d\t", list->codigoC);
        
            while(list->alum != NULL){
        
            //printf("\n Legajo-Lista:%d\t", list->alum->legajo);
             fseek(fA,((list->alum->legajo)-1)*(sizeof(STR_ALU)),SEEK_SET);
                fread(&alu,sizeof(STR_ALU),1,fA);
                    fprintf(f,"\nLegajo:%d\t Nom. y Ape.:%s\t Email.:%s\t Dir.:%s\n", alu.legajo, alu.nYa, alu.email, alu.dir);
                
            list->alum=list->alum->ste ;
            }
        
    list=list->ste;
    }
       
    fclose(f);
    fclose(fA);
    
    return;
}

