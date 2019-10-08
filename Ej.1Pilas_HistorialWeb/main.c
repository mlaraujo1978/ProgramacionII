/*
 * To change this license header, choose License Headers in Project Properties.
  * File:   main.c
 * Author: lourdes
 * Created on 7 de octubre de 2019, 19:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
 */
typedef struct nodo{
    char direWeb[40];
    struct nodo *ste;
}STR_NODO;

void create (STR_NODO **head){
*head=NULL;
}

void push(STR_NODO **head, char direWeb[40]){    
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
    strcpy(nodo->direWeb, direWeb);
    nodo->ste= NULL;
    
    nodo->ste=*head;
    *head=nodo;
return;
}

bool isEmpty(STR_NODO *head){

    return head==NULL;
}

char * pop (STR_NODO **head){
    
    char *direW= (char*)malloc(sizeof(char)*40);
   
     strcpy(direW,(*head)->direWeb);
     
     STR_NODO *aux=*head;
     
     *head=(*head)->ste;
     
     free(aux);
     
     return direW;
}


int main(int argc, char** argv) {
    
STR_NODO *head;
create (&head);
    
      
int cont=0;  
char direW[40];
memset(direW,'\0',40);
    
    while(*direW!='0'){
        
    
        printf("Ingrese una dire de web:");
        fflush(stdin);
        scanf("%s", direW);
        cont++;  
        printf("Contador %d\t", cont); 
        push(&head, direW);
  }

 while(head!=NULL){
   
  printf("Dire web:%s\n", pop(&head));
  }
return (EXIT_SUCCESS);
}

