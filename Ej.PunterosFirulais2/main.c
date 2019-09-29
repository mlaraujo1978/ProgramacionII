typedef struct{
int edad;
}Firulais;

void *concebirFirulais(Firulais **firu, int edad){

    *firu =(Firulais*)malloc(sizeof(Firulais));
    
    (*firu)->edad=edad;
    return;
}



#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    Firulais *firu=NULL;
    
    concebirFirulais(&firu, 10);
    
    printf("La edad es :%d", firu->edad);
    
    
    return (EXIT_SUCCESS);
}
