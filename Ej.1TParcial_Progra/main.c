#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int myStrCmp(const char *cad1, const char *cad2){

 int retval=0;

    while(*cad1 && *cad2 && *cad1 == *cad2){
        cad1++;
        cad2++;
    }
    printf("cadena 1: %s\t", cad1);
    printf("cadena 2: %s\n", cad2);

    retval = (*cad1 - *cad2) ;
    printf("retval %d\n", retval);

    return retval;
}
/*
 *
 */
int main() {

    char *cad1=(char*)malloc(sizeof(char)*20);
    memset(cad1,'\0',20);
    char *cad2=(char*)malloc(sizeof(char)*20);
    memset(cad2,'\0',20);

    printf("Ingrese una cadena\t");
    scanf("%s", cad1);

    printf("Ingrese una cadena\t");
    scanf("%s", cad2);

    int rdo=myStrCmp(cad1, cad2);

    if(rdo==0){
    printf("Las cadenas son iguales");
     }
    if(rdo<0){
    printf("La segunda cadena es mayor a la primera");
     }
      if(rdo>0){
    printf("La segunda cadena es menor a la primera");
   }
    return 0;
}
