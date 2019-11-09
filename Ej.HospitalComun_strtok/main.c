/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 8 de noviembre de 2019, 15:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nombre[20];
    char dni[15];
    char sexo[10];
    char edad[4];
}STR_PACIENTE;

typedef struct nodoC{
    STR_PACIENTE pacientes;
    struct nodoC *ste;

}STR_NODOC;

typedef struct{
    STR_NODOC *frente;
    STR_NODOC *fin;
    int cantPacientes;
}STR_Q;

bool isEmpty(STR_Q *q){

    return q->frente==NULL && q->fin==NULL;
}

FILE * fileOpen(char nomFile[10], char tipoAp[4]){

    FILE *f=fopen(nomFile,tipoAp);
    
    if( f==NULL){
    
        printf("El archivo no se pudo abrir");
        exit(1);
    }
    return f;
}
void addQ (STR_Q *q, STR_PACIENTE paciente){

    STR_NODOC *new= (STR_NODOC*)malloc(sizeof(STR_NODOC));
    new->pacientes=paciente;
    new->ste=NULL;

    if(q->frente==NULL){
        q->frente=new;
    }
    else{
        q->fin->ste=new;
    }
    q->fin=new;
   
}

void cargaPacientesCola(FILE *f, STR_Q *q){

    STR_PACIENTE paciente;
  
    f=fileOpen("datos.txt", "r+");
  
    char* linea= (char*)malloc(sizeof(char)*49); 
    char *token=NULL;
    
    int cantIte=0;
           
    while(fgets(linea,49+1,f)!=NULL){
        
        cantIte=1;
               
        token=strtok(linea,",");
        memset(paciente.nombre,'\0',20);
        strncpy(paciente.nombre,token,20);
        
        while(token!=NULL){
            
            token=strtok(NULL,",");
        
            cantIte++;  

            if(cantIte==2){
                memset(paciente.dni,'\0',15);
                strncpy(paciente.dni,token,15);
            }
            if(cantIte==3){
                memset(paciente.sexo,'\0',10);
                strncpy(paciente.sexo,token,10);
            }
            if(cantIte==4){
                memset(paciente.edad,'\0',4);
                strncpy(paciente.edad,token,2);
            }
           
            }
        addQ(q,paciente);        
    }
    
fclose(f);
return;   
}


void crearCola(STR_Q *q){

    q->frente=NULL;
    q->fin=NULL;
    q->cantPacientes=0;   
    
}

STR_PACIENTE remove1 (STR_Q *q){

    STR_NODOC *aux=q->frente;
    q->frente=aux->ste;
    STR_PACIENTE paciente= aux->pacientes;
    free(aux);
    
    q->cantPacientes--;
   
    if(q->frente==NULL){
        q->fin=NULL;
    }
      
return paciente;
}

void cargaPacienteFileBin(FILE *f, STR_Q *q){

    f=fileOpen("turnosPacientes.data", "w+");
    
    STR_PACIENTE paciente;

    while(!isEmpty(q)){
        paciente=remove1(q);
        fwrite(&paciente,sizeof(STR_PACIENTE),1,f);
    }
    fclose(f);
return;
}

void imprimeFileBin (FILE *f){

    f=fileOpen("turnosPacientes.data", "r+");
    
    STR_PACIENTE paciente;
    
    fread(&paciente,sizeof(STR_PACIENTE),1,f);
    while (!feof(f)){
    
        printf("\nNombre: %s\t",paciente.nombre);
        printf("DNI: %s\t",paciente.dni);
        printf("sexo: %s\t",paciente.sexo);
        printf("Edad: %s\t",paciente.edad);
      
    fread(&paciente,sizeof(STR_PACIENTE),1,f);
    
    }
    
 return;   
}



int main(int argc, char** argv) {
    
FILE *fT=NULL;

FILE *fB=NULL;
STR_Q q;
crearCola(&q);

cargaPacientesCola(fT,&q);

cargaPacienteFileBin(fB,&q);

imprimeFileBin (fB);


return (EXIT_SUCCESS);
}


