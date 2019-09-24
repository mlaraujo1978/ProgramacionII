/*
*/

/* 
 * File:   funciones.h
 * Author: mlaraujo1978
 * Created on 20 de septiembre de 2019, 17:40
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#ifdef __cplusplus
extern "C" {
#endif
#define LONG_P 256
    
//typedef enum{ true=1,false=0} BOOL;    

   typedef struct{
   char pal[LONG_P+1];
   }STR_PAL;

    FILE * abrirArchivo1ModoRBMas ();
    
    FILE * abrirArchivo2ModoRBMas ();
    
    FILE* abrirArchivoModoWTMas ();
    
    FILE* abrirArchivoModoRTMas ();
  
    int cantRegistrosFile(FILE *file);
    
    int cantValPalindromo (const char *palabra);
    
    int longitudPal(const char *palabra);
    
    void copiaPalindromoArchivoTxt (FILE* fA, FILE* fB, FILE* fC);

    void imprimeArchivo1Bin(FILE* f);
    
    void imprimeArchivo2Bin(FILE* f);
    
    void imprimeArchivoTxt(FILE* f);

#ifdef __cplusplus
}
#endif

#endif /* FUNCIONES_H */

