/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 *
 * Created on 9 de septiembre de 2019, 19:36
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
    int dni;
}ST_INVITADOS;

void CargarInvitados (ST_INVITADOS invitados[], int cant){
       for(int i=0; i<cant;i++){
       printf("Ingrese el nombre del invitado\n");
       scanf("%s", invitados[i].nombre);
       printf("Ingrese el dni del invitado\n");
       scanf("%d", &invitados[i].dni);
    } 
}
FILE * abrirArchivo(){
    FILE * archivo= fopen("/tmp/archP.b","wb+");
    if(archivo == NULL){
    printf("No se pudo crear el archivo\n");
    exit (1);
    }
    return archivo;
}

void guardarInvitados(FILE *archivo, ST_INVITADOS *invitados,int cant){
    for(int i=0;i<cant;i++){
     fwrite(&invitados[i], sizeof(ST_INVITADOS), 1,archivo);   
    }
}
void imprimirInvitados(FILE *archivo){
    ST_INVITADOS invitados;
    fseek(archivo, 1*sizeof(ST_INVITADOS), SEEK_SET);
    fread(&invitados,sizeof(ST_INVITADOS),1, archivo);
    while(!feof(archivo)){
        printf("Nombre: %s\t DNI: %i\n", invitados.nombre, invitados.dni);
        
        
        fread(&invitados,sizeof(ST_INVITADOS),1, archivo);
    }
}


int main(int argc, char** argv) {
   int cant=3;
   ST_INVITADOS invitados[cant];
   
   CargarInvitados (invitados, cant);
   
   FILE *archivo= NULL;
           
   archivo= abrirArchivo(archivo);
   
   guardarInvitados(archivo,invitados,cant);
   
   imprimirInvitados(archivo);
   
   fclose(archivo);
   
   return (EXIT_SUCCESS);
}


