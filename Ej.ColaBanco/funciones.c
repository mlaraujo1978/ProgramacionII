#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

FILE * OpenFile(char nF[15],char oT[4]){

    FILE *f=fopen(nF,oT);
    
    if(f==NULL){
    "El archivo no se pudo leer";
    exit(1);
    }
    return f;
}

void crear (STR_QUEUE *q){
    q->frente=NULL;
    q->fin=NULL;
    q->cant=0;
}

void add (STR_QUEUE *q, STR_CLIENTE cliente){
    
 STR_NODO *new=(STR_NODO*)malloc(sizeof(STR_NODO));
  
    strncpy( new->cli.nomYape,cliente.nomYape, 15);
    
    new->cli.dni=cliente.dni;
    
    strncpy( new->cli.tipoC,cliente.tipoC, 2);
    
    strncpy( new->cli.sexo,cliente.sexo, 2);
  
    strncpy( new->cli.embara,cliente.embara,2);
   
    new->cli.tOp=cliente.tOp;   
    
    new->ste = NULL;

    q->cant++;
 
 if(q->frente==NULL){
     q->frente=new;
 }
 else{
     q->fin->ste=new; 
 }
    q->fin=new;
}

void cargaDatosenCola (STR_QUEUE *cP, STR_QUEUE *cC, STR_QUEUE *cA ){
     
    STR_CLIENTE cli;
         
    memset(cli.nomYape,'\0',15);
    memset(cli.tipoC,'\0',2);
    memset(cli.sexo,'\0',2);
    memset(cli.embara,'\0',2);
    strncpy (cli.embara,"NO",2);
       
    printf(" Ingrese el DNI: \t");fflush(stdin);
    scanf("%d", &cli.dni); 
               
    printf(" Ingrese el nombre y apellido: \t");fflush(stdin);
    scanf("%s", cli.nomYape);
    
    printf(" Ingrese el tipo de Cliente (PR/CO): \t");fflush(stdin);
    scanf("%s", cli.tipoC);
    
    printf(" Ingrese el sexo (FE/MA): \t");fflush(stdin);
    scanf("%s", cli.sexo);
    
    if((strcmp(cli.sexo,"FE"))==0){
    printf(" Ingrese si esta embarazada (SI/NO: \t");fflush(stdin);
    scanf("%s", cli.embara);
    }
    
    printf(" tipo Operacion (1al10): \t");fflush(stdin);
    scanf("%d", &cli.tOp);
    
    if((strcmp(cli.embara,"SI"))==0){
        
        if(cC==NULL){
        add(cC,cli);
        }
        
        else{
        add(cA,cli);            
            while(cC!=NULL){
            cli=remove1(cC);
            add(cA,cli); 
            }
            while(cA!=NULL){
            cli=remove1(cA);
            add(cC,cli); 
            }
        }
    }
    if((strcmp(cli.embara,"NO"))==0){
    
        if((strcmp(cli.tipoC,"PR"))==0){
        add(cP,cli);
        }
        if((strcmp(cli.tipoC,"CO"))==0){
        add(cC,cli); 
        }
    }
    
    printf(" Cantidad Cola CO: %d", cC->cant);
    printf(" Cantidad Cola PR: %d", cP->cant);

return;
}

STR_CLIENTE remove1 (STR_QUEUE *q){
 
    STR_NODO *aux= q->frente;
 
    STR_CLIENTE cliente= aux->cli;
 
    printf("\n DNI:%d\t",cliente.dni);
    printf(" Nombre y Apellido: %s\t",cliente.nomYape);
    printf(" Nombre y Apellido: %s\t",cliente.tipoC);
    printf(" Nombre y Apellido: %d\t",cliente.tOp);
  
    q->frente=aux->ste;
    q->cant--;
    aux->ste=NULL;
    free(aux);
 
 if(q->frente==NULL){
     q->fin=NULL;
 }
 return cliente;                
}

void procesaColas(STR_QUEUE *cP, STR_QUEUE *cC, FILE *f){

STR_CLIENTE cliente;  

f=OpenFile("archivoAtencion","a+");
    
    while ( cP!=NULL && cC!=NULL){
    
        if(cP->cant >=3){
        cliente=remove1(cP);
        fprintf(f,"\n DNI:%d\t",cliente.dni);
        fprintf(f," Nombre y Apellido: %s\t",cliente.nomYape);
        fprintf(f," Nombre y Apellido: %s\t",cliente.tipoC);
        fprintf(f," Nombre y Apellido: %d\t",cliente.tOp);
        }
        if(cP->cant <3){
        cliente=remove1(cP);
        fprintf(f,"\n DNI:%d\t",cliente.dni);
        fprintf(f," Nombre y Apellido: %s\t",cliente.nomYape);
        fprintf(f," Nombre y Apellido: %s\t",cliente.tipoC);
        fprintf(f," Nombre y Apellido: %d\t",cliente.tOp);
        
        cliente=remove1(cC);
        fprintf(f,"\n DNI:%d\t",cliente.dni);
        fprintf(f," Nombre y Apellido: %s\t",cliente.nomYape);
        fprintf(f," Nombre y Apellido: %s\t",cliente.tipoC);
        fprintf(f," Nombre y Apellido: %d\t",cliente.tOp);
        }
    }
        
            while ( cP!=NULL){
            cliente=remove1(cP);
            fprintf(f,"\n DNI:%d\t",cliente.dni);
            fprintf(f," Nombre y Apellido: %s\t",cliente.nomYape);
            fprintf(f," Nombre y Apellido: %s\t",cliente.tipoC);
            fprintf(f," Nombre y Apellido: %d\t",cliente.tOp);
            }
    
                while ( cC!=NULL){
                cliente=remove1(cC);
                fprintf(f,"\n DNI:%d\t",cliente.dni);
                fprintf(f," Nombre y Apellido: %s\t",cliente.nomYape);
                fprintf(f," Tipo Cliente: %s\t",cliente.tipoC);
                fprintf(f," Tipo Operacion: %d\t",cliente.tOp);
                }  
fclose(f);
return;    
}

void imprimiFileAtencion(FILE *f){

f=OpenFile("archivoAtencion","r+");
char registro[40];

while(fgets(registro,41,f)!=NULL){

    printf("%s",registro);
}

return;
}