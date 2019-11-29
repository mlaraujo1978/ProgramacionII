/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 29 de noviembre de 2019, 15:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
/*
 * 
 */
FILE *OpenFile(const char *nameF, const char *openT){

    FILE *f=fopen(nameF,openT);
    
    if(f==NULL){
    
        printf("El archivo no se puede abrir\n");
        exit(1);
    }

    return f;
}

void reseteaPalabra(char *palabra, int largoPal){

    for(int i=0;i<largoPal+1;i++){
    
    *(palabra+i)='\0';
    
    }

return;
}

int longitudPalabra(const char *palabra){
    
    int longi=0;

        while(*palabra){
            
            palabra++;        
            longi++;
        }
return longi;

}


int cantidadConsonantes(char *palabra){

      
    int cantVoc=0;
       
    int largo=longitudPalabra(palabra);

    char vec[5]={"AEIOU"};
    
            while(*palabra){
                
                for(int i=0;i<5;i++){
                    
                   if(*(palabra)==*(vec+i)){
                        
                       cantVoc++;
                   }
                
                }
                
            palabra++;
            
            }
    
    int cantCons=largo-cantVoc;
    //printf("CANTCONSO: %d\n", cantCons);
    
    return cantCons;
}

void imprimeFile(FILE *fMasCons){
   

 fMasCons=OpenFile("MasConsonantes.dat","rb+");
 
 char *palabra= (char*)malloc(sizeof(char)*80);
 reseteaPalabra(palabra,80);

    fread(palabra, sizeof(char), sizeof(palabra),fMasCons);   
            
            while(!feof(fMasCons)){

                printf("Palabra BIN: %s\n", palabra);

                fread(palabra, sizeof(char), sizeof(palabra),fMasCons);   
            }

fclose(fMasCons);  
}


int main(int argc, char** argv) {
    
   FILE *fPal=NULL;
   FILE *fMasCons=NULL;
   
   fPal=OpenFile("Palabras.txt","r+");
   fMasCons=OpenFile("MasConsonantes.dat","wb+");
    
    char *palabra= (char*)malloc(sizeof(char)*80);
    reseteaPalabra(palabra,80);
    
    char *linea= (char*)malloc(sizeof(char)*80);
    reseteaPalabra(linea,80);
    
    int i=0;
    int largo=0;
    int cantCons=0;
    
 
    while(fgets(linea,80+1,fPal)!=NULL){
            
                  
            while(*linea && *linea!='.'){
        
                *(palabra+i)=*linea;
                linea++;
                i++;
                largo++;
                
            }
                        
            cantCons=cantidadConsonantes(palabra);
            
            if (cantCons>(largo/2)){
                
                fwrite(palabra, sizeof(char), sizeof(palabra),fMasCons);
            }
            
            i=0;
            linea++;
            largo++;
            reseteaPalabra(palabra,80);
            linea=linea-largo;
            largo=0;
            
           }
    
      
    fclose(fPal);
    fclose(fMasCons);

    imprimeFile(fMasCons);
    
    return (EXIT_SUCCESS);
}

