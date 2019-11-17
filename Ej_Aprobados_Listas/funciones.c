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
    
    memset(nodoL->aprob,'\0',2);
    
    if(strcmp(nota.parcial,"1")==0){
    nodoL->notaPP=nota.nota;
    }
    
    if(strcmp(nota.parcial, "2")==0){
    nodoL->notaSP=nota.nota;
    }
    
     if(strcmp(nota.parcial, "R")==0){
    nodoL->notaRP=nota.nota;
    }

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
    
       if(strcmp(nota.parcial,"1")==0){
        nodoL->notaPP=nota.nota;
        
        }
    
        if(strcmp(nota.parcial, "2")==0){
        nodoL->notaSP=nota.nota;
        
        }
    
         if(strcmp(nota.parcial, "R")==0){
         nodoL->notaRP=nota.nota;
         
          }
    
    }

    return;

}

void ProcesaFileNotas(FILE *fNotas,STR_LISTA **list){

    fNotas=openFile("NotasParciales.data","rb+");
    
    STR_NOTAS nota;
    
    fread(&nota,sizeof(STR_NOTAS),1,fNotas);
    
            while(!feof(fNotas)){
            
                insertSinDuplicados(list,nota);            
            
            fread(&nota,sizeof(STR_NOTAS),1,fNotas);
            }
    return;
}

void revisaNotas(STR_LISTA **list){

STR_LISTA *listAux=*list;
    
    
            while(listAux!=NULL){
                
                
                if((listAux->notaPP>=6&&listAux->notaSP>=6)||(listAux->notaPP>=6&&listAux->notaRP>=6)||(listAux->notaSP>=6&&listAux->notaRP>=6)){
                strcpy(listAux->aprob,"A");                
                }                
                listAux=listAux->ste;
            }
return;
}

void insertAtEnd(STR_LISTA **asistencias,int legajoAct,int cantAsis){

    STR_LISTA *nodoL=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    
    nodoL->legajo=legajoAct;
    nodoL->cantAsist=cantAsis;
    nodoL->ste=NULL;
    
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
    
    fread(&asis,sizeof(STR_ASIST),1,fAsistencias);
    
                while(!feof(fAsistencias)){
                              
                    cantAsis=0;   
                    legajoAct=asis.legajo;
    
                            while(!feof(fAsistencias) && asis.legajo==legajoAct){
                                
                                cantAsis+=asis.presente;  
                                
                                printf("La cantidad de asistencia es:%d\n",asis.presente);
            
                                fread(&asis,sizeof(STR_ASIST),1,fAsistencias);
                            }
                    
                            insertAtEnd(asistencias,legajoAct,cantAsis);
                           
                }
    
    fclose(fAsistencias);
    return;
}


void GeneraFileAprobados(FILE *fAprobados,STR_LISTA *notas,STR_LISTA *asistencias){
    
    
    fAprobados= openFile("Aprobaron.data", "wb+");
    
    STR_APROB aprob;
    
    STR_LISTA *listAux=notas;
    STR_LISTA *listAux1=asistencias;
    
            while(listAux!=NULL && listAux1!=NULL){
                
                 if(strcmp(listAux->aprob,"A")==0){
                                
                      aprob.legajo=listAux->legajo;
                    
                      aprob.cantAsis=listAux1->cantAsist;
                      
                      fwrite(&aprob,sizeof(STR_APROB),1,fAprobados);                  
                       
                 }
                 listAux=listAux->ste;
                 listAux1=listAux1->ste;
            }
    
    fclose(fAprobados);
    return;
}

void ImprimeFile (FILE * f){

STR_APROB aprob; 

f= openFile("Aprobaron.data", "rb+");  


        fread(&aprob, sizeof(STR_APROB), 1, f);   
            
        while(!feof(f)){

        printf("LEGAJO: %d\t CANTIDAD ASISTENCIAS: %d\n", aprob.legajo, aprob.cantAsis);

        fread(&aprob, sizeof(STR_APROB), 1, f); 
        
        }
    
fclose(f);  

}

