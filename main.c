#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){

    Lista list;

    printf("Lista iniciada\n");
    Init(&list);
    int valor = 10;

    printf("\nValor inserido no comeco\n");
    InserirInicioLista( &list, &valor);
    ShowLista(&list);
    
    int outroValor = 20;
    printf("Valor inserido no final\n");
    InserirUltimoLista(&list, &outroValor);
    ShowLista(&list);
    
    printf("\nLista\n");
    ShowLista(&list); 
    printf("Valor removido do final\n");
    RemoverFinalLista(&list);
    
    printf("\nNova Lista\n");
    ShowLista(&list); 
    
    outroValor = 20;
    printf("Valor inserido no final\n");
    InserirUltimoLista(&list, &outroValor);
    
    printf("\nNova Lista\n");
    ShowLista(&list); 
    
    printf("Valor removido do inicio\n");
    RemoverInicioLista(&list);
    
    printf("\nNova Lista\n");
    ShowLista(&list);
    
    

    return 0;
}