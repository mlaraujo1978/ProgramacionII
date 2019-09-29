/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 * Created on 23 de septiembre de 2019, 10:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int myStrCmp (const char *cad1, const char *cad2){
 int i=0;  
 int contCad1=0;
 int contCad2=0;
 int contIguales=0;
 int resultado;
 
    while(*cad1){ 
    cad1++;
    contCad1++;
    }   
        
    while(*cad2){
    cad2++;
    contCad2++;
    }
     
 if(contCad1==contCad2){
     
    for (int i=0; i<contCad1;i++){
    if((*(cad1+i))==*(cad2+i)){
            contIguales++;
        } 
    }
    
    if(contIguales==contCad1 && contIguales==contCad2){
    resultado=0;
    }
 }
 
 if(contCad2 > contCad1){
    resultado=1;
 }
 if(contCad2 < contCad1){
     resultado=-1;   
    }
return resultado;
}

/*
 * 
 */
int main(int argc, char** argv) {

    char *cad1=(char*)malloc(sizeof(char)*20);
    memset(cad1,'\0',20);
    char *cad2=(char*)malloc(sizeof(char)*20);
    memset(cad2,'\0',20);
  
    printf("Ingrese una cadena\t");
    scanf("%s", cad1);
 
    printf("Ingrese una cadena\t");
    scanf("%s", cad2);
 
    int rdo;
 
    if((rdo=myStrCmp(cad1, cad2))==0){
    printf("Las cadenas son iguales");
     }
    if((rdo=myStrCmp(cad1, cad2))==1){
    printf("La segunda cadena es mayor a la primera");
     }
     if((rdo=myStrCmp(cad1, cad2))==-1){
    printf("La segunda cadena es menor a la primera");
    }
 
    return (EXIT_SUCCESS);
}

