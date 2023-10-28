#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int data1 = 10;
int data2 = 20;

void Init(Lista *list){
    list->Inicio = NULL;
    list->Tam = 0;
}

int InserirInicioLista(Lista *list, void* Data){
    No *Novo = (No*)malloc(sizeof(No));
    if(Novo == NULL) return -1;

    Novo->data = Data;
    Novo->Proximo = list->Inicio;
    list->Inicio = Novo;
    list->Tam++;
    return 1;
}

int InserirUltimoLista(Lista *list, void* Data){
    No *novo = (No*)malloc(sizeof(No));
    
    if(novo == NULL) return -1;
    
    novo->data = Data;
    novo->Proximo = NULL;
    
    if(Verificar(list)){
        list->Inicio = novo;
    }else{
        No *aux = list->Inicio;
        while(aux->Proximo != NULL)
            aux = aux->Proximo;
        aux->Proximo = novo;
    }
    list->Tam++;
    return 1;
}

void* RemoverInicioLista(Lista *list){
    if(Verificar(list)) return NULL;
    No *trash = list->Inicio; 
    list->Inicio = list->Inicio->Proximo; 
    void *Data = trash->data; 
    free(trash);
    list->Tam--;
    return Data;
}

void* RemoverFinalLista(Lista *list) {
    if (Verificar(list)) return NULL;
    if (list->Inicio->Proximo == NULL) { 
        void *Data = list->Inicio->data; 
        free(list->Inicio); 
        list->Inicio = NULL; 
        list->Tam = 0; 
        return Data; 
    }
    No *trash = list->Inicio;
    while (trash->Proximo->Proximo != NULL) {
        trash = trash->Proximo;
    }
    void *Data = trash->Proximo->data;
    free(trash->Proximo);
    trash->Proximo = NULL;
    list->Tam--;
    return Data;
}

void ShowLista(Lista *list){
    No *Aux = list->Inicio;
    while (Aux != NULL) {
        printf("%d \n", *(int*)Aux->data);
        Aux = Aux->Proximo;
    }
    printf("\n");
}

int Verificar(Lista *list){
    return (list->Tam == 0);
}
void* removeposicao(Lista *Lista, int posicao) {
	return NULL;
}

int indexOf(Lista *list,void *data,compare equal) {
    if (Verificar(list)) return -1;
    int tam=0;
    No *aux = list->Inicio->Proximo;
while (aux != list->Inicio && !equal(aux->data, data)) {

        aux=aux->Proximo;
        tam++;
    }
    return (aux==list->Inicio)?-1:tam;
}