#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "funciones.h"

FILE * openFile(const char *nameF, const char *openT){

    FILE* f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    
    return f;
}
void imprimeFile (FILE * fB){

fB=fopen("datos.dat", "rb+");
    
    STR_DATOS datos;
   
    fread(&datos, sizeof(STR_DATOS),1,fB);
    
            while(!feof(fB)){
                
                printf("\n ID: %d\t",datos.id);
                printf(" DESCRIPCION: %s\t",datos.des);
                                   
            fread(&datos, sizeof(STR_DATOS),1,fB);   
            
            }   
    
fclose(fB);

return;
}

void imprimirVector(STR_DATOS *datos[],int n){

for(int i=0;i<n;i++){
    
        printf("\nID: %d",datos[i]->id);
        printf("Desc: %s",datos[i]->des);
    }
 

}

void inicializaVector(STR_DATOS *datos[] , int n){

    for(int i=0;i<n;i++){
    
        datos[i]->id=-1;
        strncpy(datos[i]->des,"",16);
    }
 
}

int CuentaRegistrosFile (FILE * fB){
   
    fB=fopen("datos.dat", "rb+");
    
    STR_DATOS datos;
    
    int cantReg=0;
    
    fread(&datos, sizeof(STR_DATOS),1,fB);
    
            while(!feof(fB)){
            
                cantReg++;
                
            fread(&datos, sizeof(STR_DATOS),1,fB);   
            
            }
    
fclose(fB);    
return cantReg;

}

void cargaVector(FILE* fB, STR_DATOS *datos[] , int n){

 
  fB=fopen("datos.dat", "rb+");
    
    STR_DATOS datosB;
    
    int i=0;
    
    fread(&datosB, sizeof(STR_DATOS),1,fB);
    
            while(!feof(fB)){
                               
               datos[i]->id=datosB.id;
       
               strcpy(datos[i]->des,datosB.des);
    
                i++;
                
            fread(&datosB, sizeof(STR_DATOS),1,fB);   
            
            }   
fclose(fB);    
    
return;
 }


void ordenaVector(STR_DATOS *datos[],int n){

 STR_DATOS *aux=(STR_DATOS*)malloc(sizeof(STR_DATOS));
   
    for(int i=0;i<n-1;i++){
    
        for(int j=0;j<n-1-i;j++){
            
            if(datos[j]->id > datos[j+1]->id){
                                          
                aux=datos[j];
                datos[j]=datos[j+1];
                datos[j+1]=aux;          
            }
        }
    }
  
 return;
}
    
void cargaSinDuplicadosEnFile(STR_DATOS *datos[],int n,FILE *fB){

   fB=openFile("datos.dat","wb+");
   int i=0;
   int idAnterior;
   
     
        for(int i=0;i<n;i++){
            
            if(i==0){
                
            fwrite(datos[i], sizeof(STR_DATOS),1,fB);
            
            idAnterior=datos[i]->id;
                    
            }
        
                if(datos[i]->id != idAnterior){
                    
                    fwrite(datos[i], sizeof(STR_DATOS),1,fB);
            
                    idAnterior=datos[i]->id;
                    
                }
                    
        }
             
   fclose(fB);
              
}


