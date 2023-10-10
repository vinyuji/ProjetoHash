#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void Init(Lista *list){
    list->Inicio = NULL;
    list->tam = 0;
}

int InserirInicioLista(Lista *list, void* Data){
    No *Novo = (No*)malloc(sizeof(No));
    if(Novo == NULL) return -1;

    Novo->Data = Data;
    Novo->Proximo = list->Inicio;
    list->Inicio = Novo;
    list->tam++;
    return 1;
}

int InserirUltimoLista(Lista *list, void* Data){
    No *novo = (No*)malloc(sizeof(No));
    
    if(novo == NULL) return -1;
    
    novo->Data = Data;
    novo->Proximo = NULL;
    
    if(Verifica(list)){
        list->Inicio = novo;
    }else{
        No *aux = list->Inicio;
        while(aux->Proximo != NULL)
            aux = aux->Proximo;
        aux->Proximo = novo;
    }
    list->tam++;
    return 1;
}

void* RemoverInicioLista(Lista *list){
    if(Verifica(list)) return NULL;
    No *trash = list->Inicio; 
    list->Inicio = list->Inicio->Proximo; 
    void *Data = trash->Data; 
    free(trash);
    list->tam--;
    return Data;
}

void* RemoverFinalLista(Lista *list) {
    if (Verifica(list)) return NULL;
    if (list->Inicio->Proximo == NULL) { 
        void *Data = list->Inicio->Data; 
        free(list->Inicio); 
        list->Inicio = NULL; 
        list->tam = 0; 
        return Data; 
    }
    No *trash = list->Inicio;
    while (trash->Proximo->Proximo != NULL) {
        trash = trash->Proximo;
    }
    void *Data = trash->Proximo->Data;
    free(trash->Proximo);
    trash->Proximo = NULL;
    list->tam--;
    return Data;
}

void ShowLista(Lista *list){
    No *Aux = list->Inicio;
    while(Aux != NULL){
        printf("%d ", Aux->Data);
    }
    printf("\n");
}

int Verifica(Lista *list){
    return (list->tam == 0);
}
