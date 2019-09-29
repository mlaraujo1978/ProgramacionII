/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include<strings.h>
#include<string.h>
#include"funciones.h"
/*
 * 
 */
void loadVecObj( ObjetoDron vec[], int n){
    for(int i=0; i<n;i++){
    printf("Ingrese el tipo de objeto Dron encontrado\n");fflush(stdin);
        scanf("%s",vec[i].tipo);
    printf("Ingrese el tamanio del objeto Dron encontrado\n");fflush(stdin);
        scanf("%s",vec[i].tam);
    printf("Ingrese la cantidad del objeto Dron encontrado\n");fflush(stdin);
        scanf("%d",&vec[i].cantidad);
    }  
}

FILE * openFileWB(){

    FILE* f= fopen("objeto.bin", "wb+");
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);
    }
    return f;
}

FILE * openFileRB(){

    FILE* f= fopen("objeto.bin", "rb+");
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);
    }
    return f;
}


void initializeFile(FILE *f){

ObjetoDron obj;
f=openFileRB(); 

fseek(f, 2*(sizeof(ObjetoDron)),SEEK_SET);        
strcpy(obj.tipo,"HUMANO");
strcpy(obj.tam,"PEQUENO");
       
//for(int i=0;i<3;i++){
obj.cantidad=5;
fwrite(&obj, sizeof(ObjetoDron),1, f);    
//}    
fclose(f);
}

void printFile(FILE* f){
    
    ObjetoDron obj;
    
    f=openFileRB();
    
    fread(&obj, sizeof(ObjetoDron), 1, f);
      
    while(!feof(f)){
    
        printf(" Tipo %s\t Tamanio %s\t Cantidad %d\n", obj.tipo, obj.tam, obj.cantidad);
        
        fread(&obj, sizeof(ObjetoDron),1, f);
    }
    fclose(f);
}

void processFileObjs(ObjetoDron *vec, int n, FILE * f){

ObjetoDron obj;
    
f=openFileRB();

int cont=0;

for(int i=0; i<n;i++){
   
    cont=0;
    fseek(f, 0, SEEK_SET); 
    
    if((vec[i].cantidad)>0){
    
    fread(&obj, sizeof(ObjetoDron), 1, f);
    while(!feof(f) && cont==0){
     
        if ( (strcmp(obj.tipo,vec[i].tipo))==0 && (strcmp(obj.tam,vec[i].tam))==0){
        cont++;
        obj.cantidad+=vec[i].cantidad;
        fseek(f,(-1)*sizeof(ObjetoDron),SEEK_CUR);
        fwrite(&obj,sizeof(ObjetoDron), 1, f);
        }  
   
        fread(&obj, sizeof(ObjetoDron), 1, f);
    }
      
    if (cont==0){
     fwrite(&vec[i], sizeof(ObjetoDron), 1, f);
    }
  }
}

fclose(f);

}
