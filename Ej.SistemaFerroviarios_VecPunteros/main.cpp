/* 
 * File:   main.cpp
 * Author: lourdes
 *
 * Created on 23 de noviembre de 2019, 17:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef struct{
int codigoPas;
char estadoPas[15];
char estacionAsc[3];
char estacionDesc[3];
}STR_PASAJE;

typedef struct{
char codigoPas[3];
char estacionDesc[3];
}STR_PASAJESUBEN;

FILE * openFile(const char *nameF, const char *openT);

void inicializaVector(STR_PASAJE *pasaje[], int n);

void cargaCodigoPasaje(STR_PASAJE *pasaje[], int n, FILE* fGP);

int numeroEstacionDescenso (const char *numEst);

void actualizaEstadoPasajeros(STR_PASAJE *pasaje[], int n, int estacion);

void actualizaVecFileSuben(const char *nameF, const char* openT,STR_PASAJE *pasaje[], int n, const char *estacion);

void actualizaGranPlanilla(FILE* fS1,FILE *fS2,FILE *fS3,FILE *fS4,STR_PASAJE *pasaje[],int n);

void imprimeVector(STR_PASAJE *pasaje[], int n);

void imprimeFile(FILE * f);
    

int main(int argc, char** argv) {
    
    FILE *fGP=NULL;
    FILE *fS1=NULL;
    FILE *fS2=NULL;
    FILE *fS3=NULL;
    FILE *fS4=NULL;
    
    int cantPasajeros=10;
    
    STR_PASAJE *pasaje[10];
    
        for(int i=0;i<10;i++){
    
        pasaje[i]=(STR_PASAJE*)malloc(sizeof(STR_PASAJE));
    
        }
    
    inicializaVector(pasaje,10);
    
    cargaCodigoPasaje(pasaje,10, fGP); 
    
    actualizaGranPlanilla(fS1,fS2,fS3,fS4,pasaje,10);
    
    //imprimeVector(pasaje,10);
    
    //imprimeFile(fGP); 

    return 0;
}

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
    
    f=openFile("pasajeros.dat", "rb+");  
    

    fread(&pasaje,sizeof(STR_PASAJE), 1, f);   
       
        while(!feof(f)){

            printf("\nCodigo Pas.: %d\t Estado: %s\t EstacionAsc: %s\t EstacionDesc: %s \n",pasaje.codigoPas, pasaje.estadoPas, pasaje.estacionAsc, pasaje.estacionDesc);
            
            fread(&pasaje,sizeof(STR_PASAJE), 1, f);     
        }
    
fclose(f);  
return;
 }

void inicializaVector( STR_PASAJE *pasaje[], int n){

 for(int i=0;i<10;i++){
    
       pasaje[i]->codigoPas=-1;
       strcpy(pasaje[i]->estadoPas,"");
       strcpy(pasaje[i]->estacionAsc,"");
       strcpy(pasaje[i]->estacionDesc,"");
        
    }
return;    
}

void imprimeVector(STR_PASAJE *pasaje[], int n){

 for(int i=0;i<10;i++){
    
        printf("\nCODIGO:%d\t",pasaje[i]->codigoPas);
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

            pasaje[i]->codigoPas=pasajeB.codigoPas;
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
    
    
    int codPas;
   
    char *linea=(char*)malloc(sizeof(char)*7);
    char *token=NULL;  

        while(fgets(linea,7+1,fSuben)){

            token=strtok(linea,",");
            pasajeB.codigoPas=atoi(token);
                                 
            token=strtok(NULL,".");
            strcpy(pasajeB.estacionDesc,token);
            
            strcpy(pasajeB.estadoPas,"sube");
            
            for(int i=0;i<n;i++){
        
                if(pasaje[i]->codigoPas==pasajeB.codigoPas){
                    
                    strcpy(pasaje[i]->estacionAsc,estacion);
                    strcpy(pasaje[i]->estacionDesc,pasajeB.estacionDesc);
                    memset(pasaje[i]->estadoPas,'\0',15);
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
            
                if(strcmp(pasaje[i]->estadoPas,"transito")==0 && numEDesc==estacion){
                    
                    memset(pasaje[i]->estadoPas,'\0',15);
                    strcpy(pasaje[i]->estadoPas,"bajo");         
                
                }
            }    
        
    return;
} 


void actualizaGranPlanilla(FILE* fS1,FILE *fS2,FILE *fS3,FILE *fS4,STR_PASAJE *pasaje[],int n){

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

