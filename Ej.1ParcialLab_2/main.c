#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef struct{
char nombre[12];
int edad;
int cantidad;
}STR_DATOSB;

FILE * openFile (char nF[15+1], char tA[3+1]){

FILE *f=fopen(nF, tA);

if(f==NULL){
printf("El archivo no se pudo abrir");
exit(1);
}
return f;
}

void initializeFile(FILE *f, char nF[15+1], char tA[3+1]){

f=openFile(nF, tA);

STR_DATOSB datos;

strcpy(datos.nombre,"");

for (int i=0; i<10;i++){
        datos.edad=-1;
        datos.cantidad=-1;

fwrite(&datos, sizeof(STR_DATOSB), 1, f);
}
fclose(f);
}

void printFile(FILE *f, char nF[15+1], char tA[3+1]){

STR_DATOSB datos;
f=fopen(nF, tA);

fread(&datos, sizeof(STR_DATOSB), 1, f);

    while(!feof(f)){

        if(datos.cantidad==1){
     printf("Nombre: %s\t Edad: %d\t Cantidad: %d\n", datos.nombre, datos.edad, datos.cantidad);
        }
fread(&datos, sizeof(STR_DATOSB), 1, f);
    }
fclose(f);
}

void printFileC(FILE *f, char nF[15+1], char tA[3+1]){

STR_DATOSB datos;
f=fopen(nF, tA);

fread(&datos, sizeof(STR_DATOSB), 1, f);

    while(!feof(f)){

     printf("Nombre: %s\t Edad: %d\t Cantidad: %d\n", datos.nombre, datos.edad, datos.cantidad);

fread(&datos, sizeof(STR_DATOSB), 1, f);
    }
fclose(f);
}

void ProcesaDatosFileBinD (FILE *fT, FILE *fB){

fT=fopen("datosT.txt", "r+");

char *registro= (char*)malloc(sizeof(char)*20+1);

char *nombre=(char*)malloc(sizeof(char)*12);

char *edad=(char*)malloc(sizeof(char)*7);

int i=0;
int igual=0;
STR_DATOSB datos;

    while((fgets(registro,20+1,fT))!=NULL){

    memset(edad,'\0',7);
    memset(nombre,'\0',12);

    while (*registro && *registro!=','){

        *(nombre+i)=*registro;
        i++;
        registro++;
    }
    i=0;
    printf("Nombre %s\t", nombre);

    while(*registro){
    *(edad+i)=*registro;
    i++;
    registro++;
    }

    i=0;
    printf("Edad %s\n", edad);
    int edadP=atoi(edad);

    fread(&datos, sizeof(STR_DATOSB), 1, fB);

         while(!feof(fB)){

         if ( (strcmp(nombre,datos.nombre))==0 && datos.edad==edadP) {
                igual++;

             fseek(fB, sizeof(STR_DATOSB)*(-1), SEEK_CUR);
             strcpy(datos.nombre,"");
             datos.edad=-1;
             datos.cantidad=-1;
         fwrite(&datos, sizeof(STR_DATOSB), 1, fB);

            fseek(fB, 0, SEEK_END);
            strcpy(datos.nombre, nombre);
            datos.edad= edadP;
            datos.cantidad=1;
         fwrite(&datos, sizeof(STR_DATOSB), 1, fB);

         }

         fread(&datos, sizeof(STR_DATOSB), 1, fB);

         }

    if(igual==0){

            fseek(fB, 0, SEEK_SET);
            fread(&datos, sizeof(STR_DATOSB), 1, fB);

                while(!feof(fB)&& datos.cantidad==1){

            fread(&datos, sizeof(STR_DATOSB), 1, fB);
            }
            fseek(fB, sizeof(STR_DATOSB)*(-1), SEEK_CUR);
            strcpy(datos.nombre, nombre);
            datos.edad= edadP;
            datos.cantidad=1;
        fwrite(&datos, sizeof(STR_DATOSB), 1, fB);

        }
    }
fclose(fT);
fclose(fB);
return;
}


void ObtieneDatosFileTxt (FILE *fT){

fT=fopen("datosT.txt", "r+");

char *registro= (char*)malloc(sizeof(char)*20+1);

char *nombre=(char*)malloc(sizeof(char)*12);

char *edad=(char*)malloc(sizeof(char)*7);

int i=0;

    while((fgets(registro,20+1,fT))!=NULL){

    memset(edad,'\0',7);
    memset(nombre,'\0',12);

    while (*registro && *registro!=','){

        *(nombre+i)=*registro;
        i++;
        registro++;
    }
    i=0;
    printf("Nombre %s\t", nombre);

    while(*registro){
    *(edad+i)=*registro;
    i++;
    registro++;
    }

    i=0;
    printf("Edad %s\n", edad);
    int edadP=atoi(edad);
 }
 fclose(fT);

return;
}

int main()
{

FILE *fT=NULL;
FILE *fB=NULL;

//initializeFile(fB, "datos.data", "wb+");

ProcesaDatosFileBinD(fT, fB);
//ObtieneDatosFileTxt(fT);
//printFileC(fB, "datos.data", "rb+");
//printFileC(fB, "datos.data", "rb+");

return 0;
}
