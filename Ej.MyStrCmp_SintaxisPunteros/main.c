/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 26 de noviembre de 2019, 13:17
 */


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int myStrCmp(const char *cad1, const char *cad2){

 int retVal=0;

    while(*cad1 && *cad2 && *cad1 == *cad2){
        cad1++;
        cad2++;
    }
    
    retVal = (*cad1-*cad2) ;
    
    if(retVal>0){
    
    retVal=1;
    }
    
    if(retVal<0){
    
    retVal=-1;
    }
    
    printf("retval %d\n", retVal);

    return retVal;
}

void reseteaPalabra(char *palabra, int largo){

    for(int i=0;i<largo+1;i++){
    
    *(palabra+i)='\0';
    
    }

return;
}
/*
 *
 */
int main() {

    char *cad1=(char*)malloc(sizeof(char)*20);
    reseteaPalabra(cad1,20);
    char *cad2=(char*)malloc(sizeof(char)*20);
    reseteaPalabra(cad2,20);

    printf("Ingrese una cadena\t");
    scanf("%s", cad1);

    printf("Ingrese una cadena\t");
    scanf("%s", cad2);

    int rdo=myStrCmp(cad1, cad2);

    if(rdo==0){
    printf("Las cadenas son iguales");
     }
    if(rdo==1){
    printf("La segunda cadena es mayor a la primera");
     }
      if(rdo==-1){
    printf("La segunda cadena es menor a la primera");
   }
    return 0;
}
