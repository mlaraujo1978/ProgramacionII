/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mlaraujo1978
 *
 * Created on 5 de septiembre de 2019, 20:04
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char nombre[21]="\0";
    char *p;
    p=&nombre;
    printf("escribir nombres dejando espacio despues de cada ingreso\n");
    gets(nombre);
    printf("Los nombres son:%s\n", nombre);
    printf("Los nombres son:%s\n", p);
    printf("Los nombres son:%p\n", p);
    printf("Los nombres son:%p\n", &nombre);
    return (EXIT_SUCCESS);
}

