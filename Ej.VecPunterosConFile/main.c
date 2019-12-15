/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 15 de diciembre de 2019, 13:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define long 12

typedef struct{
    int cod;
    char desc[long];
}STR_DATOS;

FILE* OpenFile(const char *nameF,const char *openT){

    FILE *f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("No se puede abrir archivo");
        exit(1);
    }

return f;
}

int CuentaDatosArchivo(FILE * fD){

int cantReg=0;

fD=OpenFile("datos.txt", "r+");

char *linea=(char*)malloc(sizeof(char)*14);
memset(linea, '\0',15);

    while(fgets(linea,15+1,fD)!=NULL){

        cantReg++;
    }
fclose(fD);
free(linea);
return cantReg;
}

void cargaDatosFileEnVector(FILE * fD, STR_DATOS *vec[], int n){

fD=OpenFile("datos.txt", "r+");

char *linea=(char*)malloc(sizeof(char)*15);
memset(linea, '\0',15);

int i=0;
char *token=NULL;

    while(fgets(linea,15+1,fD)!=NULL){
        
        token=strtok(linea,",.");
        vec[i]->cod=atoi(token);
        printf("CODIGO VEC: %d",vec[i]->cod);
        
        token=strtok(NULL,",.");
        memset(vec[i]->desc,'\0',long);
        strncpy(vec[i]->desc,token,long);
        printf("DESCRIPCION VEC: %s\n",vec[i]->desc);
        
        i++;
        
    }

fclose(fD);
free(linea);
return;
}

void ordenaDatosEnVector(STR_DATOS *vec[], int n){

    STR_DATOS *aux= (STR_DATOS*)malloc (sizeof(STR_DATOS));
    
    for(int i=0;i<n-1;i++){
        
        for(int j=0;j<n-1-i;j++){
        
            if(vec[j]->cod < vec[j+1]->cod){
            
                aux=vec[j+1];
                vec[j+1]=vec[j];
                vec[j]=aux;
                           
            }
        }
    }
return;
}

void imprimeVector(STR_DATOS *vec[], int n){

    for(int i=0;i<n;i++){
    
       printf("CODIGO %d",vec[i]->cod);
       printf("DESCRIPCION %s\n",vec[i]->desc);
    }

}


void CargaDatosOrdenadosEnFile(STR_DATOS *vec[], int n,FILE * fD){

fD=OpenFile("datos.txt", "w+");

int codAnt=0;

    for(int i=0;i<n;i++){
    
        if(i==0){
        
            fprintf(fD, "%d,%s\n", vec[i]->cod, vec[i]->desc);
            codAnt=vec[i]->cod;        
        }
        
        if(vec[i]->cod != codAnt){
        
            fprintf(fD, "%d,%s\n", vec[i]->cod, vec[i]->desc);
            codAnt=vec[i]->cod;        
        }
    }

fclose(fD);
return;
}

void imprimeFile(FILE * fD){

fD=OpenFile("datos.txt", "r+");

char *linea=(char*)malloc(sizeof(char)*15);
memset(linea, '\0',15);

    while(fgets(linea,15+1,fD)!=NULL){

    printf("%s",linea);       

    }

fclose(fD);
return;
}  

int main(int argc, char** argv) {
    
FILE *fD=NULL;

int cantDatos=0;

cantDatos=CuentaDatosArchivo(fD);

printf("cantidad de registros %d\n", cantDatos);

STR_DATOS **vec=(STR_DATOS**)malloc (sizeof(STR_DATOS*)*cantDatos);

for(int i=0;i<cantDatos;i++){

    vec[i]=(STR_DATOS*)malloc (sizeof(STR_DATOS));
}

cargaDatosFileEnVector(fD, vec, cantDatos);

ordenaDatosEnVector(vec,cantDatos);

imprimeVector(vec,cantDatos);

CargaDatosOrdenadosEnFile(vec,cantDatos,fD);

imprimeFile(fD);  

return (EXIT_SUCCESS);
}

