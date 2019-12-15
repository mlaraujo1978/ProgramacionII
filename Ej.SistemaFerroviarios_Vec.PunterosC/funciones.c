/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

FILE * openFile(const char *nameF, const char *openT){

    FILE* f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    
    return f;
}

void imprimeFile(FILE * f){
    
 STR_PASAJE pasaje;   
    
    f=openFile("pasajeFinal.dat", "rb+");  
    

    fread(&pasaje,sizeof(STR_PASAJE), 1, f);   
       
        while(!feof(f)){

            printf("\nCodigo Pas.: %s\t Estado: %s\t EstacionAsc: %s\t EstacionDesc: %s \n",pasaje.codigoPas, pasaje.estadoPas, pasaje.estacionAsc, pasaje.estacionDesc);
            
            fread(&pasaje,sizeof(STR_PASAJE), 1, f);     
        }
    
fclose(f);  
return;
 }

void inicializaVector( STR_PASAJE *pasaje[], int n){

 for(int i=0;i<10;i++){
    
       strcpy(pasaje[i]->codigoPas,"-1");
       strcpy(pasaje[i]->estadoPas,"");
       strcpy(pasaje[i]->estacionAsc,"");
       strcpy(pasaje[i]->estacionDesc,"");
        
    }
return;    
}

void imprimeVector(STR_PASAJE *pasaje[], int n){

 for(int i=0;i<10;i++){
     
    
        printf("\nCODIGO:%s\t",pasaje[i]->codigoPas);
        printf("ESTADO:%s\t",pasaje[i]->estadoPas);
        printf("EST.ASC:%s\t",pasaje[i]->estacionAsc);
        printf("EST.DESC:%s\t",pasaje[i]->estacionDesc);
        
    }
 
 return;
    
}

void cargaCodigoPasaje(STR_PASAJE *pasaje[], int n, FILE* fGP){

STR_PASAJE pasajeB;   

    fGP=openFile("pasajeros.dat", "rb+");  
    int i=0;

    fread(&pasajeB,sizeof(STR_PASAJE), 1, fGP);   
       
        while(!feof(fGP)){

            strcpy(pasaje[i]->codigoPas,pasajeB.codigoPas);
            //printf("\nCODIGOVEC: %d\t",pasaje[i]->codigoPas);
            i++;
            
            fread(&pasajeB,sizeof(STR_PASAJE), 1, fGP);     
        }
    
fclose(fGP);  
return;
}

void actualizaVecFileSuben(const char *nameF, const char* openT,STR_PASAJE *pasaje[], int n, const char *estacion){

    FILE *fSuben=openFile(nameF, openT);

    STR_PASAJE pasajeB;
    
    char delimitador[]=",.";
       
    char *linea=(char*)malloc(sizeof(char)*11);
    memset(linea,'\0',11);
    
    char *token=NULL;  

        while(fgets(linea,11+1,fSuben)!=NULL){

            token=strtok(linea,delimitador);
            strcpy(pasajeB.codigoPas,token);
                                 
            token=strtok(NULL,delimitador);
            strcpy(pasajeB.estacionDesc,token);
            
            strcpy(pasajeB.estadoPas,"sube");
            
            for(int i=0;i<n;i++){
        
                if(strcmp(pasaje[i]->codigoPas,pasajeB.codigoPas)==0){
                    
                    strcpy(pasaje[i]->estacionAsc,estacion);
                    strcpy(pasaje[i]->estacionDesc,pasajeB.estacionDesc);
                    //memset(pasaje[i]->estadoPas,'\0',15);
                    strcpy(pasaje[i]->estadoPas,pasajeB.estadoPas);
                
                }
            }    
              
        }

     
    fclose(fSuben);  

    return;

}

int numeroEstacionDescenso (const char *numEst){

    int numE;
    int i=0;
   
     
    while(*numEst){
        
        numEst++;
        i++;
        
        if(i==1){
    
        numE=atoi(numEst);
        //printf("Numero estacion numE: %d", numE);
    
        }
    }
return numE;
}


void actualizaEstadoPasajeros(STR_PASAJE *pasaje[], int n, int estacion){

int numEDesc;
              
            for(int i=0;i<n;i++){
                                                        
                if(strcmp(pasaje[i]->estadoPas,"sube")==0){
                    
                    numEDesc=numeroEstacionDescenso(pasaje[i]->estacionDesc);
                                        
                    if(numEDesc==estacion){
                        
                    memset(pasaje[i]->estadoPas,'\0',15);
                    strcpy(pasaje[i]->estadoPas,"bajo");
                             
                    }
                
                        else{
                    
                            memset(pasaje[i]->estadoPas,'\0',15);
                            strcpy(pasaje[i]->estadoPas,"transito");
 
                        }
            
                } 
            
                if(strcmp(pasaje[i]->estadoPas,"transito")==0){
                    
                numEDesc=numeroEstacionDescenso(pasaje[i]->estacionDesc);    
                    
                    if(numEDesc==estacion){
                    
                    memset(pasaje[i]->estadoPas,'\0',15);
                    strcpy(pasaje[i]->estadoPas,"bajo");         
                    }
                }
            }    
        
    return;
} 


void actualizaGranPlanilla(STR_PASAJE *pasaje[],int n){

    for(int i=0; i<5;i++){
        
        int estacion=i+1;
        
        
        if(estacion>1){
            actualizaEstadoPasajeros(pasaje, n, estacion);
        }
        
            if(estacion==1){
            
              actualizaVecFileSuben("SubenE1.txt", "r+",pasaje,10,"E1");
            }
        
            if(estacion==2){
            
               actualizaVecFileSuben("SubenE2.txt", "r+",pasaje,10,"E2");
            
            }
        
            if(estacion==3){
            
               actualizaVecFileSuben("SubenE3.txt", "r+",pasaje,10,"E3");
            }
        
            if(estacion==4){
            
               actualizaVecFileSuben("SubenE4.txt", "r+",pasaje,10,"E4");
            }
        
        printf("\n::::::::::::::::::::::ACTUALIZA ESTADO PASAJEROS::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::: ESTACION: %d::::::::::::::::::::::::::::::::::",estacion);
        imprimeVector(pasaje,10);
        
    }
    
    
    return;
}


void cargaFileconVector(STR_PASAJE *pasaje[],int n,FILE* fBP){

        
    fBP=openFile("pasajeFinal.dat","wb+");
        
        for(int i=0;i<10;i++){
        
            fwrite(pasaje[i],sizeof(STR_PASAJE),1,fBP);
        
        }
    
    fclose(fBP);
           
    imprimeFile(fBP);

}

void ordenaVectorVariableCadena2(STR_PASAJE *pasaje[], int n){

    STR_PASAJE *aux= (STR_PASAJE*)malloc(sizeof(STR_PASAJE));
    
    int rdo=0;
    
    for(int i=0;i<n-1;i++){
    
        for(int j=0;j<n-1-i;j++){
        
            rdo=strcmp(pasaje[j]->codigoPas, pasaje[j+1]->codigoPas);
            
            if(rdo<0){
                aux=pasaje[j+1];
                pasaje[j+1]=pasaje[j];
                pasaje[j]=aux;
            
            }
        
        }
    
    }
    
    
    imprimeVector(pasaje,n);
  
}

void ordenaVectorVariableCadena(STR_PASAJE *pasaje[], int n){

    STR_PASAJE *aux= (STR_PASAJE*)malloc(sizeof(STR_PASAJE));
    int rdo=0;
        
    for(int i=0;i<n-1;i++){
    
        for(int j=0;j<n-1-i;j++){
            
            rdo=strcmp(pasaje[j]->estacionAsc,pasaje[j+1]->estacionAsc);
                
                if(rdo > 0){
            
                aux=pasaje[j];
                pasaje[j]=pasaje[j+1];
                pasaje[j+1]=aux; 
                
                }
        }
    }
  
    imprimeVector(pasaje,n);
  
}