#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "hash.h"
#include "arquivo.h"
#include "grafico.h"
#define TAM 4096


int main() {
    Lista lista[TAM];
    int op, length;
    
    iniciarHash(lista);

    do {
        printf("\n\t0 - SAIR\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Contar Colisoes\n\t4 - ler o arquivo\n\t5 - Por a lista de palavra na tabela hash\n\t6 - Gerar o grafico\n");
        scanf("%d", &op);

        switch (op) {
            case 0: 
                for (int i = 0; i < TAM; i++) {
                    EsvaziarLista(&lista[i]);
                }
                break;
            case 1:
                Inserir(lista);
                break;
            case 2:
                imprimirHash(lista);
                break;
            case 3:
                ContarDiferente(lista);
                break;
            case 4:
                leituraArquivo();
                break;
            case 5:
                ColocarTabelaHash(lista);
                break;
            case 6:
                colorir(lista);
                break;
            default:
                printf("opcao invalida!\n");
        }
    } while (op != 0);

    for (int i = 0; i < TAM; i++) {
        EsvaziarLista(&lista[i]);
    }
    return 0;
}
