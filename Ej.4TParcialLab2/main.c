/* 
 * File:   main.c
 * Author: mlaraujo1978
created on 25 de septiembre de 2019, 13:11
 */
#include <stdio.h>
#include <stdlib.h>
#include<strings.h>
#include<string.h>
#include"funciones.h"

int main(int argc, char** argv) {

int n=2;
ObjetoDron vec[n];
FILE *fO=NULL;
 
//initializeFile(fO);
 
loadVecObj( vec, n);

processFileObjs(vec, n, fO);
 
printFile(fO);
 
 
return (EXIT_SUCCESS);
}