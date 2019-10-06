#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

/*
 *
 */
int main() {

    char *linea;
    linea=(char*)malloc(sizeof(char)*80+1);
    memset(linea,'\0',80+1);

    char vecVoc[5]={'A','E','I','O','U'};
    for(int i=0;i<5;i++){
        printf("vocales: %c\n",vecVoc[i]);
    }
    char palabra[80+1];
    memset(palabra,'\0',80+1);

    char *espacio=" ";

    int OrdPal=0;
    int valVoc=-1;
    int valCon=0;
    int validaVoc=0;

    printf("Ingrese palabras separadas por un espacio\n");
    gets(linea);

   int i=0;

    while(*linea){


        while(*linea && *linea!=' ' && *linea!='\0'){

        OrdPal++;

        *(palabra+i)=*linea;

        if(OrdPal==2 &&validaVoc==0){
        validaVoc++;

        for(int j=0;j<5;j++){
            if(*(palabra+i)== *(vecVoc+j)){
                valVoc++;
        printf("valida vocal: %d\n", valVoc);
            }
        }
        if(valCon==5 && valVoc==0){
        *(palabra+i)=*espacio;
        linea--;
        linea--;
        }
        }
        linea++;
        i++;
        }

        if(OrdPal==1){

        for(int j=0;j<5;j++){
        if(*(palabra+i)!= *(vecVoc+j)){
        valCon++;
        printf("valida consonante: %d\t", valCon);
        }
        }
        if(valCon!=5){
        *(palabra+i)=*espacio;
        i++;
        }
        }

        if(OrdPal==2){
        if(valCon==5 && valVoc==1){
        *(palabra+i)=*espacio;
        i++;
        }
        OrdPal=0;
        valCon=0;
        valVoc=-1;
        validaVoc=0;
        }
        linea++;
        }
    printf("La nueva cadena es: %s", palabra);
    return 0;
}

