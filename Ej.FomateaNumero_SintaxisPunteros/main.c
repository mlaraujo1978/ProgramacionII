/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 26 de noviembre de 2019, 14:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


void reseteaNumero(char *numero,int largo){

    for(int i=0;i<largo+1;i++){
    
        *(numero+i)='\0';    
    }
    
return;
}

int largoNumero(char *numero){

    int largo=0;
    
    while(*numero){
    
        numero++;
        largo++;   
    }

return largo;

}



char * formateaNumero(char *numero){

    char *numeroS=(char*)malloc(sizeof(char)*12);
    reseteaNumero(numeroS,12);
    
    int largo=0;
    
    largo=largoNumero(numero);
    
    int i=0;
    
        while(*numero){
    
            *(numeroS+i)=*numero;
            numero++;
            i++;
      
            if((largo==4 || largo==7)&& i==1){
                 *(numeroS+i)='.';
                i++;
            }
            
            if((largo==5 || largo==8) && i==2){
                *(numeroS+i)='.';
                i++;
            }
            
            if((largo==6 || largo==9) && i==3){
                 *(numeroS+i)='.';
                i++;
            }
            
            if(largo==7 && i==5){
                *(numeroS+i)='.';
                i++;
            }
            
            if(largo==8 && i==6){
                *(numeroS+i)='.';
                i++;
            }
            
            if(largo==9 && i==7){
                *(numeroS+i)='.';
                i++;
            }
        
        }
    
return numeroS;
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    
    char *numero=(char*)malloc(sizeof(char)*12);
    reseteaNumero(numero,12);
    
    printf("ingresa un numero de hasta 9 digitos:");
    scanf("%s",numero);
    
    printf("\nEl numero formateado es: %s", formateaNumero(numero));
        

    return (EXIT_SUCCESS);
}

