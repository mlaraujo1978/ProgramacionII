#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

FILE * OpenFile (const char *nameF, const char *openT){

    FILE *f=fopen(nameF,openT);
    if(f==NULL){
    
        printf("No se puede abrir archivo");
        exit(1);
        
    }
    return f;
}


STR_AVION deleteFirst(STR_LISTA **lista){

    STR_AVION avion;
    
    STR_LISTA *aux=*lista;
   *lista=(*lista)->ste;
    avion=aux->avion;
   
   free(aux);
   
   return avion;
}

STR_AVION insertInfront(STR_LISTA **lista, STR_AVION avion){

    STR_LISTA *nodoL=creaNodoP (lista,avion);

    nodoL->ste=*lista;
    *lista=nodoL;
    
                
    return avion;
}

void imprimeListaZonaEspera (STR_LISTA *zE){

    STR_AVION avion;
    
    STR_LISTA *listAux=zE;
        
    while(listAux!=NULL){
        
            printf("OrdIng.: %d\t", listAux->avion.ordIng);
               printf("Tipo Avion: %s\t", listAux->avion.tipo);
                 printf("Codigo: %s\t",  listAux->avion.codigo);
                     printf("Pas.Arribo: %d\t",listAux->avion.pasArribo);
                         printf("Pas.Desp.: %d\t",  listAux->avion.pasDesp);
                              printf("OrdDesp: %d\n", listAux->avion.ordDesp);
        listAux=listAux->ste;    
    }
}


STR_LISTA * creaNodoP (STR_LISTA **zE, STR_AVION avion){
 
    STR_LISTA *new= (STR_LISTA*)malloc(sizeof(STR_LISTA));
    new->avion=avion;
    new->ste=NULL;
    
return new;

}

void OrdenaAvionesZonaEspera (STR_LISTA **zE, STR_AVION avion){
     
    if( strcmp(avion.tipo,"NIRANIPI")==0){
            insertInfront(zE,avion);
    }
         else{
        
                 STR_LISTA *nodoL= creaNodoP (zE,avion);
                 STR_LISTA *aux=*zE;
                 STR_LISTA *nodoAnt=NULL;

                if(strcmp(avion.tipo,"RANDE")==0){
                  
                     while(aux!=NULL && (strcmp(aux->avion.tipo,"RANDE")!=0) ){
                         nodoAnt=aux;
                            aux=aux->ste;
                     }
          
                         if(nodoAnt==NULL){
                             *zE=nodoL;
                          } 
          
                              else{
                                nodoAnt->ste=nodoL;   
                                }
        
                                nodoL->ste=aux;
                }  

                    if(strcmp(avion.tipo,"PICHITITO")==0){
                   
                         while( aux!=NULL && (strcmp(aux->avion.tipo,"NIRANIPI")==0) ){
                            nodoAnt=aux;
                            aux=aux->ste;
                        }
          
                            if(nodoAnt->ste==NULL){
                           *zE=nodoL;
                             } 
          
                                 else{
                                 nodoAnt->ste=nodoL;   
                                 }
        
                           nodoL->ste=aux;
                    }          
            }         

return;
}


void procesaArribos(FILE *fA,FILE *fM,STR_LISTA **zE){
        
   STR_AVION avion;
    
    avion.ordIng=0;
    avion.pasArribo=-1;
    avion.pasDesp=-1;
    avion.ordDesp=0;
    memset(avion.tipo,'\0',10);
    memset(avion.codigo,'\0',6);
    
    char *linea=(char*) malloc(sizeof(char)*20);
    memset(linea,'\0',21);
    
    char *dato=(char*)malloc(sizeof(char)*10);
    
    int i=0;
    int j=0;
    int cantIte=0;
    int posIng=0;
    
    fA= OpenFile ("arribos.txt", "r+");
    fM= OpenFile ("movimientos.data","wb+");
    
    while(fgets(linea,21+1,fA)!=NULL){
            
            while(*linea){
                        
                while(*linea && *linea!=',' && *linea!='.'){
    
                 *(dato+i)=*linea;
                 linea++;
                  i++;
                  j++;
                }
        
            cantIte++;
              
            if(cantIte==1){
            strncpy(avion.tipo, dato, 10);   
            
            }
            if(cantIte==2){
            strncpy(avion.codigo, dato, 6); 
            
            }
            if(cantIte==3){
            avion.pasArribo=atoi(dato);
            
            }
               
            memset(dato,'\0',10);
            i=0;
            linea++;
            j++;
            }
            
     linea=linea-j;
     j=0;
     cantIte=0;
     posIng++;
        
     avion.ordIng=posIng;
                
     fwrite(&avion,sizeof(STR_AVION), 1, fM);
        
     OrdenaAvionesZonaEspera(zE,avion);
     
            
    }
    
fclose(fA);
fclose(fM);

return;
}

void actualizaFileMovimientos(FILE *fP, FILE *fM, STR_AVION avion){

fM= OpenFile ("movimientos.data","rb+");

STR_AVION avionM;

fread(&avionM,sizeof(STR_AVION), 1, fM);
 
         while(!feof(fM)){
         
            if(strcmp(avion.codigo,avionM.codigo)==0){
             
                avionM.pasDesp=avion.pasDesp;
                fseek(fM,(sizeof(STR_AVION))*(-1),SEEK_CUR);
                fwrite(&avionM,sizeof(STR_AVION), 1, fM); 
             
            }
                 
            fread(&avionM,sizeof(STR_AVION), 1, fM); 
         }

fclose(fM);
return;
}

void procesaPartidas(FILE *fP, FILE *fM){

STR_AVION avion;
STR_PILA *pAux;

fP= OpenFile ("partidas.txt","r+"); 

 char *linea=(char*) malloc(sizeof(char)*20);
 memset(linea,'\0',20);
     
 char *dato=(char*)malloc(sizeof(char)*10);
    
    int i=0;
    int j=0;
    int cantIte=0;
    
    while(fgets(linea,21+1,fP)!=NULL){
            
            while(*linea){
                        
                while(*linea && *linea!=',' && *linea!='.'){
    
                 *(dato+i)=*linea;
                 linea++;
                  i++;
                  j++;
                }
        
            cantIte++;
           
            if(cantIte==2){
            strncpy(avion.codigo, dato, 6); 
           
            }
            if(cantIte==3){
            avion.pasDesp=atoi(dato);
            
            }
               
            memset(dato,'\0',10);
            i=0;
            linea++;
            j++;
            }
            
     linea=linea-j;
     j=0;
     cantIte=0;
        
     actualizaFileMovimientos(fP,fM,avion);
              
   }  

fclose(fP);
}

void actualizaPosDespegueFile(FILE *fM,STR_AVION avion){

    fM= OpenFile ("movimientos.data","rb+");
    
    STR_AVION avionM;

    fread(&avionM,sizeof(STR_AVION), 1, fM);
 
         while(!feof(fM)){
         
            if(strcmp(avion.codigo,avionM.codigo)==0){
             
                avionM.ordDesp=avion.ordDesp;
                fseek(fM,(sizeof(STR_AVION))*(-1),SEEK_CUR);
                fwrite(&avionM,sizeof(STR_AVION), 1, fM); 
             
            }
                 
            fread(&avionM,sizeof(STR_AVION), 1, fM); 
         }

fclose(fM);
}

void procesaDespegues(STR_LISTA **zE,STR_LISTA **despegue, FILE *fM){

STR_AVION avion;

int posDesp=0;

        while(*zE!=NULL){
                              
            avion=deleteFirst(zE);
            insertInfront(despegue,avion);
          
        } 

         *zE=*despegue;   
                 
            while(*despegue!=NULL){
                              
            avion=deleteFirst(despegue);
            
            posDesp++;
            avion.ordDesp=posDesp;
                        
            actualizaPosDespegueFile(fM,avion);
                    
            }
        
return;
}

void ImprimeFileMovimientos (FILE *fM){

 fM= OpenFile ("movimientos.data", "rb+");
 
 STR_AVION avion;
 
    fread(&avion,sizeof(STR_AVION), 1, fM);
 
         while(!feof(fM)){
 
           printf("OrdIng.: %d\t", avion.ordIng);
            printf("Tipo Avion: %s\t", avion.tipo);
             printf("Codigo: %s\t", avion.codigo);
              printf("Pas.Arribo: %d\t", avion.pasArribo);
                printf("OrdDesp: %d\t", avion.ordDesp);
                  printf("Pas.Desp.: %d\n", avion.pasDesp);
              
            fread(&avion,sizeof(STR_AVION), 1, fM);
 }

    return;
}