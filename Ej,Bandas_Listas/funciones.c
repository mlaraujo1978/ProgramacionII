#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

FILE* openFile (const char *nameF, char const *openT){

    FILE *f= fopen(nameF,openT);
    
    if(f==NULL){
    
        printf("El archivo no se pudo abrir");
        exit(1);
    
    }
    
    return f;
}

STR_LIST1 *buscaAnio(STR_LIST1 *list, int anio){

    STR_LIST1 *listAux=list;
    
    while(listAux!=NULL && listAux->anioDisco!=anio){
    
        listAux=listAux->ste;
    
    }
    return listAux;
}

STR_LIST1 *insertOrdenadoAnio(STR_LIST1 **list, int anio){

    STR_LIST1 *new=(STR_LIST1*)malloc(sizeof(STR_LIST1));
    new->anioDisco=anio;
    new->ste=NULL;
    
    STR_LIST1 *listAux=*list;
    STR_LIST1 *nodoAnt=NULL;
    
    while(listAux!=NULL && anio>listAux->anioDisco){
        nodoAnt=listAux;
        listAux=listAux->ste;
    
    }
    
    if(nodoAnt==NULL){
        *list=new;
    }
        else{
        
        nodoAnt->ste=new;
        }

    new->ste=listAux;
    
return new;
}

void insertOrdenadoCantDiscos(STR_LIST2 **list, int cantVen, int posFile){

    
    STR_LIST2 *new=(STR_LIST2*)malloc(sizeof(STR_LIST2));
    new->cantVend=cantVen;
    new->posFile=posFile;
    new->ste;
    
    STR_LIST2 *listAux=*list;
    STR_LIST2 *nodoAnt=NULL;
    
    while(listAux!=NULL && cantVen> listAux->cantVend){
        nodoAnt=listAux;
        listAux=listAux->ste;
    
    }
    
    if(nodoAnt==NULL){
        *list=new;
    }
        else{
        
        nodoAnt->ste=new;
        }

    new->ste=listAux;
    
return;
}

STR_LIST1 * insertSinDuplicadosAnio(STR_LIST1 **list, int anio){

    STR_LIST1 *nodoL1=buscaAnio(*list,anio);
    
    if(nodoL1==NULL){
    
        nodoL1=insertOrdenadoAnio(list,anio);
    }
    
return nodoL1;
}

void creaListaPorAnioYCantVend(FILE * f, STR_LIST1 **list){

STR_BANDA banda;

int posFile=0;
    
    f=openFile("bandas.dat", "rb+");  
    
    fread(&banda,sizeof(STR_BANDA), 1, f);   
            
        while(!feof(f)){
            
            posFile++;
            STR_LIST1 *nodo=insertSinDuplicadosAnio(list,banda.anioDisco);
            insertOrdenadoCantDiscos(&nodo->cantVendida,banda.cantVen, posFile);
            
        fread(&banda,sizeof(STR_BANDA), 1, f);    
    }


fclose(f);  

}
    
void imprimeListaBandas(FILE * f, STR_LIST1 *list1){


STR_BANDA banda;

int posFile=0;
    
f=openFile("bandas.dat", "rb+");  

STR_LIST1 *listAux=list1;
     
            
        while(listAux!=NULL){
        
           printf("\nEl anio de publicación es %d\t\n", listAux->anioDisco);
           
           while(listAux->cantVendida!=NULL){
           
               fseek(f,(sizeof(STR_BANDA)*(listAux->cantVendida->posFile-1)),SEEK_SET);
               fread(&banda,sizeof(STR_BANDA), 1, f); 
               
               printf("Banda: %s\t Nombre Disco: %s\t",banda.nomBanda, banda.nomDisco);
                           
               printf("\tCantidad vendida:%d\n", listAux->cantVendida->cantVend);
               
               listAux->cantVendida=listAux->cantVendida->ste;
           }
        
        listAux=listAux->ste;
        } 
            
 
fclose(f);  
return;
}
          
void ImprimeFile (FILE * f){

  STR_BANDA banda;
    
    f=openFile("bandas.dat", "rb+");  
    
    fread(&banda,sizeof(STR_BANDA), 1, f);   
        while(!feof(f)){

          printf(" Banda: %s\t Nombre Disco: %s\t Anio Disco: %d\t Cant. Vendida: %d \n",banda.nomBanda, banda.nomDisco, banda.anioDisco, banda.cantVen);
            
            fread(&banda,sizeof(STR_BANDA), 1, f);    
    }
fclose(f);  
 }