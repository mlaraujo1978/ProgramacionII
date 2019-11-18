/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 1 de noviembre de 2019, 18:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


typedef struct{
int legajo;
int nota;
}STR_NOTAS;

typedef struct{
int legajo;
int fecha;
int presente;
}STR_ASIST;


FILE * openFile(char nameF[15], char openT[4]){

    FILE* f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}

void IniciaFileBin (FILE * f,char nameF[15], char openT[4]){
    
    f=openFile(nameF, openT);
    
    STR_NOTAS nota;
        
    fseek(f, (sizeof(STR_NOTAS))*3, SEEK_SET);
    fread(&nota, sizeof(STR_NOTAS),1,f);
    fseek(f, (sizeof(STR_NOTAS))*3, SEEK_SET);
    //for(int i=0; i<6;i++){
    nota.legajo=1; 
    //asist.fecha=1121;
    //asist.presente=0;
    nota.nota=8;
   //strcpy(nota.parcial,"2");
    
    fwrite(&nota,sizeof(STR_NOTAS), 1, f);
   //}
    //STR_ALU alu;
    
        //memset(alu.nYa,'\0',40);
        //memset(alu.dir,'\0',60);
       // memset(alu.email,'\0',20);
       
        //alu.legajo=10;
        //strcpy(alu.nYa, "MARIA ARAUJO");
        //strcpy(alu.dir, "BB");
        //strcpy(alu.email, "MARIA@GMAIL.COM");
              
        //fwrite(&alu,sizeof(STR_ALU), 1, f);
    
    fclose(f);
}

void IngresaDatosFile(FILE * f, char nF[10], char oT[4]){

    STR_ASIST asis;
    
    f=openFile(nF, oT);
    
    //memset(nota.parcial,'\0',2);
    
        printf("Ingrese Legajo:\t");
        scanf("%d",&asis.legajo);
    
    while(asis.legajo>=1){
    
        printf("Ingrese fecha mmdd: \t");
        scanf("%d",&asis.fecha);
        printf("Ingrese presente:\n");
        scanf("%d",&asis.presente);
        
        fwrite(&asis,sizeof(STR_ASIST), 1, f);
        
        printf("Ingrese Legajo:\t");
        scanf("%d",&asis.legajo);
             
    }
  fclose(f);  
    
    }


void ImprimeFile (FILE * f, char nF[10], char oT[4]){

//STR_ALU alu;
//STR_ASIST asis; 
STR_NOTAS nota;

f= openFile(nF, oT);  

//fread(&alu, sizeof(STR_ALU), 1, f);
    fread(&nota, sizeof(STR_NOTAS), 1, f);   
        while(!feof(f)){
//   printf(" Legajo: %d\t Nombre y apellido: %s\t Dir.: %s\t Email: %s \n", alu.legajo, alu.nYa, alu.dir, alu.email);
        printf("LEGAJO: %d\t NOTA: %d\n", nota.legajo, nota.nota);
//   fread(&alu, sizeof(STR_ALU), 1, f);
        fread(&nota, sizeof(STR_NOTAS), 1, f);    
    }
fclose(f);  
 }

int main(int argc, char** argv) {

    FILE * f =NULL;
    //IniciaFileBin(f, "NotasAprobados.data", "rb+");  
    //IngresaDatosFile(f,"Asistencias.data", "wb+");
    ImprimeFile (f, "NotasAprobados.data", "rb+");
    
    
  
return (EXIT_SUCCESS);
}

