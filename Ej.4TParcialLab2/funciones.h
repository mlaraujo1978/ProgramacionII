/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: mlaraujo1978
 *
 * Created on 25 de septiembre de 2019, 18:35
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    char tipo[6+1];
    char tam[7+1];
    int cantidad;
}ObjetoDron;

void loadVecObj( ObjetoDron vec[], int n);

FILE * openFileWB();

FILE * openFileRB();

void initializeFile(FILE *f);

void processFileObjs(ObjetoDron *vec, int n, FILE * f);

void printFile(FILE* f);

#ifdef __cplusplus
}
#endif

#endif /* FUNCIONES_H */

