
#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
int legajo;
int nota;
}STR_NOTAS;

typedef struct{
int legajo;
int fecha;
int presente;
}STR_ASIST;

typedef struct nodoL{
 int legajo;
 int sumaNotas;
 int cantAsist;
 int cantClases;
 struct nodoL *ste;
}STR_LISTA; 

typedef struct {
    int legajo;
    int promedio;
    int cantAsis;
}STR_APROB;

FILE * openFile(char nameF[15], char openT[4]);
STR_LISTA *creaNodo(STR_LISTA **list,STR_NOTAS nota);
STR_LISTA *search(STR_LISTA *list, int legajo);
STR_LISTA *insertOrdenado(STR_LISTA **list, STR_NOTAS nota);
void insertSinDuplicados(STR_LISTA **list, STR_NOTAS nota);
void ProcesaFileNotas(FILE *fNotas,STR_LISTA **lista);
void insertAtEnd(STR_LISTA **asistencias,int legajoAct,int cantAsis, int cantClases);
void ProcesaFileAsistencias(FILE *fAsistencias,STR_LISTA **asistencias);
void GeneraFileAprobados(FILE *fAprobados,STR_LISTA *notas,STR_LISTA *asistencias);
void ImprimeFile (FILE * f);
void ImprimeFileNotas(FILE *fNotas);
void ImprimeFileAsistencias(FILE *fAsistencias);

#endif /* FUNCIONES_H */

