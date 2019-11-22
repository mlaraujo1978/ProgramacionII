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

void ImprimeFile(FILE * f){
    
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

void actualizaPlanillaSuben(FILE *fPlanilla,FILE *fSuben,const char *nameF, const char *openT){
    
    fPlanilla=openFile("pasajeros.dat", "rb+");  
    fSuben=openFile(nameF, openT);

    
    STR_PASAJE pasaje;
    STR_PASAJESUBEN pasajeS;
    
    int codPas;
   
    char *linea=(char*)malloc(sizeof(char)*7);
    char *token=NULL;  

        while(fgets(linea,7+1,fSuben)){

            token=strtok(linea,",");
            codPas=atoi(token);
                                 
            fseek(fPlanilla,sizeof(STR_PASAJE)*(codPas-1),SEEK_SET);
            fread(&pasaje,sizeof(STR_PASAJE),1,fPlanilla);
            
            token=strtok(NULL,".");
            strcpy(pasaje.estacionDesc,token);
            
            strcpy(pasaje.estadoPas,"sube");
            
            fseek(fPlanilla,sizeof(STR_PASAJE)*(codPas-1),SEEK_SET);
            fwrite(&pasaje,sizeof(STR_PASAJE), 1, fPlanilla);
              
    }

    fclose(fPlanilla);  
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


void actualizaEstadoPasajeros(FILE *fPlanilla, int estacion){

fPlanilla=openFile("pasajeros.dat", "rb+"); 

STR_PASAJE pasaje; 

int numEDesc;
    
        fread(&pasaje,sizeof(STR_PASAJE), 1, fPlanilla);   
        
            while(!feof(fPlanilla)){
                
                numEDesc=numeroEstacionDescenso(pasaje.estacionDesc);
                
                          
                if(strcmp(pasaje.estadoPas,"sube")==0){
                    
                    if(numEDesc==estacion){
               
                    memset(pasaje.estadoPas,'\0',15);
                    strcpy(pasaje.estadoPas,"bajo");
                
                    fseek(fPlanilla,sizeof(STR_PASAJE)*(-1),SEEK_CUR);
                    fwrite(&pasaje,sizeof(STR_PASAJE), 1, fPlanilla);          
                
                    }
                
                        else{
                    
                            memset(pasaje.estadoPas,'\0',15);
                            strcpy(pasaje.estadoPas,"transito");
                            fseek(fPlanilla,sizeof(STR_PASAJE)*(-1),SEEK_CUR);
                            fwrite(&pasaje,sizeof(STR_PASAJE), 1, fPlanilla);  
                        }
            
                } 
            
                if(strcmp(pasaje.estadoPas,"transito")==0 && numEDesc==estacion){
                    
                    memset(pasaje.estadoPas,'\0',15);
                    strcpy(pasaje.estadoPas,"bajo");
                    fseek(fPlanilla,sizeof(STR_PASAJE)*(-1),SEEK_CUR);
                    fwrite(&pasaje,sizeof(STR_PASAJE), 1, fPlanilla);          
                
                }
                
            fread(&pasaje,sizeof(STR_PASAJE), 1, fPlanilla);     
    }
        
    fclose(fPlanilla);  
    
    return;
} 

void actualizaGranPlanilla(FILE *fPlanilla, FILE *fSuben1,FILE *fSuben2,FILE *fSuben3,FILE *fSuben4){

    
    for(int i=0; i<5;i++){
        
        int estacion=i+1;
        
        
        if(estacion>1){
            actualizaEstadoPasajeros(fPlanilla, estacion);
        }
        
            if(estacion==1){
            
            actualizaPlanillaSuben(fPlanilla, fSuben1, "SubenE1.txt", "r+");
            }
        
            if(estacion==2){
            
            actualizaPlanillaSuben(fPlanilla, fSuben2, "SubenE2.txt", "r+");
            }
        
            if(estacion==3){
            
            actualizaPlanillaSuben(fPlanilla, fSuben3, "SubenE3.txt", "r+");
            }
        
            if(estacion==4){
            
            actualizaPlanillaSuben(fPlanilla, fSuben4,"SubenE4.txt", "r+");
            }
        
        printf("\n::::::::::::::::::::::ACTUALIZA ESTADO PASAJEROS::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::: ESTACION: %d::::::::::::::::::::::::::::::::::",estacion);
        ImprimeFile(fPlanilla);
    }
    
    return;
}

