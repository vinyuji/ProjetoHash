#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Lista.h"
#include "hash.h"
#include "arquivo.h"
#define TAM 31

void iniciarHash(Lista list[]){
    int i;
    for(i = 0; i < TAM; i++)
        Init(&list[i]);
}

int funcaoHash(void* Data) {
    int* valor = Data;
    return *valor % TAM;
}

void inserirHash(Lista list[], void* Data) {
    int soma = calcularPesoASCII(Data);
    int id = funcaoHash(&soma);
    InserirInicioLista(&list[id], Data);
}

void ContarDiferente(Lista lista[]){
    int contar;
    for( int i=0 ; i < TAM ; i++){
        contar = lista[i].Tam;
        printf("Posicao %d: %d colisoes\n", i, contar);
    }
}

void* BuscarHash(Lista list[], void* Data) {
    int soma = calcularPesoASCII(Data);
    int id = funcaoHash(&soma);
    printf("\nindice gerado: %d", id);
    void* resultado = buscarLista(&list[id], Data);
    return resultado;
}

void imprimirHash(Lista list[]){
    for(int i = 0; i < TAM ; i++){
        printf("valor de i: %2d\t", i);
        ShowLista(&list[i]);
    }
        
}

void Inserir(Lista list[]) {
    char valor[50];
    printf("\tQual palavra deseja inserir?\n");
    scanf("%s", valor);
    char *valorPtr = malloc(strlen(valor) + 1);
    strcpy(valorPtr, valor);
    inserirHash(list, valorPtr);
}

void buscarPalavras(Lista list[]) {
    char valor[50];
    printf("\tQual palavra deseja buscar?\n");
    scanf("%s", valor);
    char *valorPtr = malloc(strlen(valor) + 1);
    strcpy(valorPtr, valor); 
    char *retorno = (char *)BuscarHash(list, valorPtr);
    if (retorno != NULL) {
        printf("\tValor encontrado: %s\n", retorno);
    } else {
        printf("\tValor não encontrado!\n");
    }
}