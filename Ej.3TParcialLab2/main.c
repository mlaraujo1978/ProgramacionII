/*
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 * Created on 22 de septiembre de 2019, 14:45
 */

#include <stdio.h>
#include <stdlib.h>

FILE* escribeFraseArchivo(){

    FILE* f= fopen("fC.txt","a+");
    if(f==NULL){
        printf("No se puede abrir el archivo.");
        exit(1);  
    }
    char frase[30]="Kokumo es una criatura magica.";  
    fputs(frase,f);
    
    return f;
}

FILE* imprimeArchivo(){

    FILE* f= fopen("fC.txt","a+");
    if(f==NULL){
        printf("No se puede abrir el archivo.");
        exit(1);  
    }

char frase[30];

while(fgets(frase,30+1, f)!=NULL) {
    printf("%s", frase);
}
    return f;
}
/*
 * 
 */
int main(int argc, char** argv) {

    FILE * f=NULL;
    
    f=escribeFraseArchivo();
    fclose(f);
   
    f=imprimeArchivo();
    fclose(f);
    
    
    return (EXIT_SUCCESS);
}

