/* 
 * File:   main.cpp
 * Author: lourdes
 *
 * Created on 22 de noviembre de 2019, 22:46
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#define LONG 64

void reseteaPalabra(char *palabra){

    for(int i=0;i<LONG+1;i++){
    
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

bool esPalindromo(const char *palabra){
    
int longi=longitudPalabra(palabra);
int inicio=0;
int fin=longi-1;
int cantVal=longi/2;
int valida=0;

        while(*palabra && (*(palabra+inicio)==*(palabra+fin)) && inicio<fin){
            valida++;                     
            inicio++;
            fin--;
        }

            if(valida==cantVal){
            return true;
            }
                else{
                    return false;
                }
}



int main(int argc, char** argv) {
    
    char *palabras=(char*)malloc(sizeof(char)*LONG);
    reseteaPalabra(palabras);
    
    printf("Ingresar palabras separadas por espacio \n");fflush;
    scanf("%s",palabras);
    
    char *palabra=(char*) malloc(sizeof(char)*LONG);
    reseteaPalabra(palabra);
    
    int i=0;
    int cantPalin=0;
    
        while(*palabras){
    
            while(*palabras && *palabras!=','){
            
                *(palabra+i)=*palabras;
                i++;            
                palabras++;
            }
            
            if(esPalindromo(palabra)){
            printf("La palabra palindromo es:%s\n", palabra);
            cantPalin++;
            }
            
            palabras++;
            i=0;
            reseteaPalabra(palabra);
    
        } 
    
        printf("La cantidad de palindromos es:%d\n", cantPalin);

    return 0;
}

