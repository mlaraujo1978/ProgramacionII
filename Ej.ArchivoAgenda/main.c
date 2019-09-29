/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 *
 * Created on 11 de septiembre de 2019, 10:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/*
 * 
 */

typedef struct{
    char nombre[20];
    char mail[20];
    int telefono;
}ST_AGENDA;

void cargaPersona(ST_AGENDA persona[],int cant){
   for(int i=0; i<cant;i++){
       printf("Ingrese el nombre\n");
       scanf("%s", persona[i].nombre);
       printf("Ingrese el mail\n");
       scanf("%s", persona[i].mail);
       printf("Ingrese el telefono\n");
       scanf("%d", &persona[i].telefono);
    } 
   return;
}

FILE * abrirArchivo(){
    FILE *archivo= fopen("Agenda.b","wb+");
    if(archivo == NULL){
    printf("No se pudo abrir el archivo\n");
    exit (1);
    }
    return archivo;
}

void guardarPersona(FILE *archivo, ST_AGENDA *persona,int cant){
    for(int i=0;i<cant;i++){
     fwrite(&persona[i], sizeof(ST_AGENDA), 1,archivo);   
    }
}

void imprimirPersona(FILE *archivo){
ST_AGENDA persona;
fseek(archivo, 0,SEEK_SET);
fread(&persona,sizeof(ST_AGENDA),1, archivo);
while(!feof(archivo)){
printf("Nombre:%s\t Mail: %s\t Telefono: %i\n", persona.nombre,persona.mail,persona.telefono);
    
fread(&persona,sizeof(ST_AGENDA),1, archivo);
}
}
void calculaeImprimeCantRegistros(FILE *archivo){
    ST_AGENDA persona;
    long actualPos=ftell(archivo);
    printf("POSICION ACTUAL %d", actualPos);
    fseek(archivo, 0,SEEK_END);
    long ultimo=ftell(archivo);
    printf("POSICION ULTIMA %d", ultimo);
    fseek(archivo, actualPos,SEEK_SET);
    printf("POSICION ACTUAL %d", actualPos);
    printf("La cantidad de registros: %d\n", (int)(ultimo)/sizeof(persona));
}
    
int main(int argc, char** argv) {
   int cant=3;
   ST_AGENDA persona[cant];
   FILE *archivo;
   
   cargaPersona(persona,cant);
   
   archivo= abrirArchivo(archivo);
   
   guardarPersona(archivo,persona,cant);
   
   imprimirPersona(archivo);
   
   calculaeImprimeCantRegistros(archivo);
   
   fclose(archivo);
   
    return (EXIT_SUCCESS);
}
