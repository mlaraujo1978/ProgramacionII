/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.c
 * Author: Lourdes
 * Created on 10 de septiembre de 2019, 20:46
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int ValidaConso(const char *origen, const char *vecVocales, int longA) {
    int valConso = 0;
    for (int i = 0; i < 5; i++) {
        if (*(origen + (longA - 1)) != *(vecVocales + i)) {
            valConso++;
        }
    }
    return valConso;
}

int ValidaVocal(const char *origen, const char *vecVocales) {
    int valVoc = 0;
    for (int i = 0; i < 5; i++) {
        if (*(origen) == *(vecVocales + i)) {
            valVoc++;
        }
    }
    return valVoc;
}

int main(int argc, char** argv) {
    char *linea;
    linea = (char*) malloc(sizeof (char)*80 + 1);
    memset(linea, '\0', 80 + 1);

    char vecVocales[6] = {'A', 'E', 'I', 'O', 'U', '\0'};

    char *palabraConca;
    palabraConca = (char*) malloc(sizeof (char)*80 + 1);
    memset(palabraConca, '\0', 80 + 1);

    char palabra[80 + 1];
    memset(palabra, '\0', 80 + 1);

    int OrdPal = 0;
    int valVoc = -1;
    int valCon = 0;

    printf("Ingrese palabras separadas por un espacio\n");
    gets(linea);

    int i = 0;
    int longi = 0;

    while (*linea) {
        OrdPal++;
        while (*linea && *linea != ' ' && *linea != '\0') {
            *(palabra + i) = *linea;
            if (OrdPal == 2 && i == 0) {
                valVoc = ValidaVocal(palabra, vecVocales);
            }
            linea++;
            longi++;
            i++;
        }

        if (OrdPal == 1) {
            valCon = ValidaConso(palabra, vecVocales, longi);
            strcat(palabraConca, palabra);
        }

        if (OrdPal == 2) {

            if (valCon == 5 && valVoc == 1) {
                printf("%s%s ", palabraConca, palabra);
            }
            if ((valCon == 5 && valVoc != 1) || (valCon != 5 && valVoc == 1) || (valCon != 5 && valVoc != 1)) {
                printf("%s %s ", palabraConca, palabra);
            }
            OrdPal = 0;
            valCon = 0;
            valVoc = -1;
            memset(palabraConca, '\0', 80 + 1);

        }
        linea++;
        longi = 0;
        i = 0;
        memset(palabra, '\0', 80 + 1);
    }
    return (EXIT_SUCCESS);
}


