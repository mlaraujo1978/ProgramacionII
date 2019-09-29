/* 
 * File:   main.c
 * Author: mlaraujo1978
 * Created on 24 de septiembre de 2019, 12:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef struct{
int hora;
float hMin;
float promH;
float hMax;
}STR_REP;


FILE * openFileRM(){

    FILE* f=fopen("medi.txt", "r+");
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}
FILE * openFileWBM(){
    
    FILE* f=fopen("reporte.bin", "wb+");
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1); 
    }    
     return f;
 }

FILE * openFileRBM(){
    
    FILE* f=fopen("reporte.bin", "rb+");
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1); 
    }    
     return f;
 }

void IniciaFileBin (FILE * f){
    
    f=openFileWBM();
    
    STR_REP repo;
     
    for (int i=0; i<24;i++){
        repo.hora=i;
        repo.hMin=1000.00;
        repo.promH=0.00;
        repo.hMax=-1.00;
        fwrite(&repo,sizeof(STR_REP), 1, f);
    }
    fclose(f);
}

void CargaMedFileB(FILE *fM, FILE *fR){
 
    fM=openFileRM();
    fR= openFileRBM();
    
    char reg[49+1];
    STR_REP repo;
    
    int cont=1; 
    int hora;
    float promH;
    float medF;
    char *token=(char*)malloc(sizeof(char)*25);
    
while((fgets(reg,49+1,fM))!=NULL) {

    token=strtok(reg,";");
    if(token==NULL){
        printf("No existe token");
        exit(1);
    }
    while (token!=NULL){
        token=strtok(NULL,";");
        cont++;
        if( cont==3){
            hora=atoi(token);
          }
        if(cont==5){
           medF=atof(token);   
        }
    }
    cont=1;
  
    fseek(fR,(hora)*(sizeof(STR_REP)), SEEK_SET);
    fread(&repo,sizeof(STR_REP),1,fR);
   
    repo.promH=(repo.promH+medF)/60;
        
    if(medF<repo.hMin){
        repo.hMin=medF;
    }
    if(medF>repo.hMax){
        repo.hMax=medF;
        
    }
    fseek(fR,(hora)*(sizeof(STR_REP)), SEEK_SET);
    fwrite(&repo,sizeof(STR_REP),1,fR);
    }
return;
}


void ImprimeFileB (FILE * f){

STR_REP repo;

f= openFileRBM();  

fread(&repo, sizeof(STR_REP), 1, f);
     
    while(!feof(f)){
    printf("Hora %d\t HMin %.2f\t PromH %.2f\t  HMax %.2f|\n", repo.hora, repo.hMin, repo.promH, repo.hMax);
    
    fread(&repo, sizeof(STR_REP), 1, f);
}
fclose(f);  
 }

/*
  */
int main(int argc, char** argv) {

    FILE * fM =NULL;
    FILE * fR =NULL;
     
    IniciaFileBin(fR);
    
    CargaMedFileB(fM,fR);
    
    ImprimeFileB (fR);
    
    return (EXIT_SUCCESS);
}

