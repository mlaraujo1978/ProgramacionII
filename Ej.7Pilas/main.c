#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <string.h>

typedef struct nodo{
    char letra;
    struct nodo *ste;
}STR_NODO;

void create (STR_NODO **head){
*head=NULL;
}

void push(STR_NODO **head, char letra){    
    
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->letra=letra;
    
    printf("\n La letra ingresada es: %c\t", letra);
    
    nodo->ste= NULL;
    
    nodo->ste=*head;
    *head=nodo;
return;
}

bool isEmpty(STR_NODO *head){

    return head==NULL;
}

char pop (STR_NODO **head){
    
    char letra;
   
    letra=(*head)->letra;
        
    STR_NODO *aux=*head;
     
    *head=(*head)->ste;
     
    free(aux);
     
    return letra;
}


bool funcionInversa(STR_NODO **headA,STR_NODO **headT, int contT){

int  cont=0;  

while(!isEmpty(headA) && !isEmpty(headT)){
    if(pop(&headA)==pop(&headT)){
    cont++;
    }
}

if(cont==contT){
    return true;
}
else{
return false;
}
}

int main(int argc, char** argv) {
    
STR_NODO *headO;
create (&headO);

STR_NODO *headT;
create(&headT);

STR_NODO *headA;
create(&headA);
       
char l;
char cadena[81+1];
memset(cadena,'\0',81+1);
int contO=0;
int contT=0;

printf("Ingrese dos conjuntos de caracteres separados por punto:\t");fflush(stdin);
scanf("%s", cadena);

char *token=(char*)malloc(sizeof(char)*40+1);
token=strtok(cadena,".");
printf("\n El token es: %s\t", token);


while (*token){
    push(&headO, *token);
    token++; 
    contO++;
}
token=strtok(NULL,".");
printf("\n El token es: %s\t", token);

while (*token){
    push(&headT, *token);
    token++;   
    contT++;
}

if( contO==contT){
    
while(!isEmpty(headO)){
l=pop(&headO);
push(&headA, l);
}

int cont=0;

    while(!isEmpty(headA) && !isEmpty(headT)){
        if(pop(&headA)==pop(&headT)){
        cont++;
        }
    }

if(cont==contT){
    printf("\n Los conjuntos de caracteres ingresados, son inversos.");
}
else{
printf("\n Los conjuntos de caracteres ingresados, no son inversos.");
}
}

else{
printf("\n Los conjuntos de caracteres ingresados, no son inversos.");
}
 
return (EXIT_SUCCESS);
}

