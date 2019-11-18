#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

FILE * openFile(char nameF[15], char openT[4]){

    FILE* f=fopen(nameF, openT);
    
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}

STR_LISTA *creaNodo(STR_LISTA **list,STR_NOTAS nota){

    STR_LISTA *nodoL=(STR_LISTA*)malloc(sizeof(STR_LISTA));  
    
    nodoL->legajo=nota.legajo;
    
    nodoL->sumaNotas=nota.nota;
    
    nodoL->ste=NULL;
   
    return nodoL;

}

STR_LISTA *search(STR_LISTA *list, int legajo){

    STR_LISTA *listAux=list;
    
    while(listAux!=NULL && listAux->legajo!=legajo){
    
        listAux=listAux->ste;
    
    }
    
    return listAux;

}

STR_LISTA *insertOrdenado(STR_LISTA **list, STR_NOTAS nota){

   STR_LISTA *nodoL=creaNodo(list,nota);
   
   STR_LISTA *listAux=*list;
   STR_LISTA *nodoAnt=NULL;
   
   while(listAux!=NULL && listAux->legajo < nota.legajo){
   
       nodoAnt=listAux;
       listAux=listAux->ste;
    }

   if(nodoAnt==NULL){
   
      *list=nodoL;
   }    
         else{
            nodoAnt->ste=nodoL;
         
         }
   nodoL->ste=listAux;
   
   return nodoL; 
   
}

void insertSinDuplicados(STR_LISTA **list, STR_NOTAS nota){

    STR_LISTA *nodoL=search(*list,nota.legajo);
    
    if(nodoL==NULL){
    
        nodoL=insertOrdenado(list,nota);
    }

    else{
    
        nodoL->sumaNotas+=nota.nota;
                
    }
    
    return;

}

void ProcesaFileNotas(FILE *fNotas,STR_LISTA **list){

    fNotas=openFile("NotasAprobados.data","rb+");
    
    STR_NOTAS nota;
    
    fread(&nota,sizeof(STR_NOTAS),1,fNotas);
    
            while(!feof(fNotas)){
            
                insertSinDuplicados(list,nota);            
            
                fread(&nota,sizeof(STR_NOTAS),1,fNotas);
            }
    return;
}

void insertAtEnd(STR_LISTA **asistencias,int legajoAct,int cantAsis, int cantClases){

    STR_LISTA *nodoL=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    
    nodoL->legajo=legajoAct;
    nodoL->cantAsist=cantAsis;
    nodoL->cantClases=cantClases;
    nodoL->ste=NULL;
    
    printf("\nLEGAJO:%d\t",nodoL->legajo);
    printf("Q_ASISTENCIA:%d\t",nodoL->cantAsist);
    printf("CANT_CLASES:%d\t",nodoL->cantClases);
    
    STR_LISTA *listAux=*asistencias;
    
    while(listAux!=NULL && listAux->ste!=NULL){
    
        listAux=listAux->ste;
    }
    
         if(listAux==NULL){
    
        *asistencias=nodoL;
        }   
         else{
             listAux->ste=nodoL;
         }
   return;
}

void ProcesaFileAsistencias(FILE *fAsistencias,STR_LISTA **asistencias){

   fAsistencias= openFile("Asistencias.data", "rb+"); 
   
   STR_ASIST asis;
   
   int cantAsis;
   int legajoAct;
   int cantClases;
    
    fread(&asis,sizeof(STR_ASIST),1,fAsistencias);
    
                while(!feof(fAsistencias)){
                              
                    cantAsis=0; 
                    cantClases=0;
                    legajoAct=asis.legajo;
    
                            while(!feof(fAsistencias) && asis.legajo==legajoAct){
                                
                                cantAsis+=asis.presente; 
                                
                                cantClases++;
                                                                         
                                fread(&asis,sizeof(STR_ASIST),1,fAsistencias);
                            }
                            //printf("\nLEGAJO:%d\t",legajoAct);
                            //printf("Q_ASISTENCIA:%d\t",cantAsis);
                            //printf("CANT_CLASES:%d\t",cantClases);
                            insertAtEnd(asistencias,legajoAct,cantAsis,cantClases);
                            
                }
    
    fclose(fAsistencias);
    return;
}


void GeneraFileAprobados(FILE *fAprobados,STR_LISTA *notas,STR_LISTA *asistencias){
        
    fAprobados= openFile("Aprobados.data", "wb+");
    
    STR_APROB aprob;
    
    STR_LISTA *listAux=notas;
        
            while(listAux!=NULL){
                
                STR_LISTA *nodoL=search(asistencias,listAux->legajo);
                            
                    if( (nodoL->cantAsist/nodoL->cantClases)>=0.8 ){
                                
                      aprob.legajo=listAux->legajo;
                      
                      aprob.promedio=listAux->sumaNotas/2;
                    
                      aprob.cantAsis=nodoL->cantAsist;
                      
                      fwrite(&aprob,sizeof(STR_APROB),1,fAprobados);                  
                       
                 }
                 listAux=listAux->ste;
            }
    
    fclose(fAprobados);
    return;
}

void ImprimeFile (FILE * f){

STR_APROB aprob; 

f= openFile("Aprobados.data", "rb+");  


        fread(&aprob, sizeof(STR_APROB), 1, f);   
            
        while(!feof(f)){

        printf("LEGAJO: %d\t PROMEDIO: %d CANTIDAD ASISTENCIAS: %d\n", aprob.legajo, aprob.promedio, aprob.cantAsis);

        fread(&aprob, sizeof(STR_APROB), 1, f); 
        
        }
    
fclose(f);  

}


void ImprimeFileNotas (FILE *fNotas){

    fNotas=openFile("NotasAprobados.data","rb+");
    
    STR_NOTAS nota;
    
    fread(&nota,sizeof(STR_NOTAS),1,fNotas);
    
            while(!feof(fNotas)){
            
               printf("LEGAJO: %d\t NOTAS: %d\n", nota.legajo, nota.nota);          
            
               fread(&nota,sizeof(STR_NOTAS),1,fNotas);
            }
    return;
}


void ImprimeFileAsistencias(FILE *fAsistencias){
    
   fAsistencias= openFile("Asistencias.data", "rb+"); 
   
   STR_ASIST asis;
      
    fread(&asis,sizeof(STR_ASIST),1,fAsistencias);
    
                while(!feof(fAsistencias)){
                              
                printf("LEGAJO: %d\t CANTIDAD ASISTENCIAS: %d\n", asis.legajo, asis.presente);
                                           
                fread(&asis,sizeof(STR_ASIST),1,fAsistencias);
                            }
                    
    return;
}








