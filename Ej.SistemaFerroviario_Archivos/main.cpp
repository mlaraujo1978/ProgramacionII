/* 
 * File:   main.cpp
 * Author: lourdes
 *
 * Created on 22 de noviembre de 2019, 13:44
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"



int main() {
    
    FILE *fGranPlanilla=NULL;
    FILE *fSuben1=NULL;
    FILE *fSuben2=NULL;
    FILE *fSuben3=NULL;
    FILE *fSuben4=NULL;

    actualizaGranPlanilla(fGranPlanilla, fSuben1, fSuben2, fSuben3, fSuben4);
     
    //ImprimeFile(fGranPlanilla);     

return 0;
}


