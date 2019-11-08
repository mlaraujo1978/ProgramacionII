/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 8 de noviembre de 2019, 16:25
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nombre[20];
    char dni[15];
    char sexo[10];
    char edad[4];
}STR_PACIENTE;

typedef struct nodoC{
    STR_PACIENTE pacientes;
    struct nodoC *ste;

}STR_NODOC;

typedef struct{
    STR_NODOC *frente;
    STR_NODOC *fin;
    int cantPacientes;
}STR_Q;

bool isEmpty(STR_Q *q);

FILE * fileOpen(char nomFile[10], char tipoAp[4]);

void crearCola(STR_Q *q);

void addQ (STR_Q *q, STR_PACIENTE paciente);

void cargaPacientesCola(FILE *f, STR_Q *q);

STR_PACIENTE remove1 (STR_Q *q);

void cargaTurnosFileBin(FILE *f, STR_Q *q);

void imprimeFileBin (FILE *f);

#endif /* FUNCIONES_H */

