#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Hash.h"
#include "arquivo.h"
#define TAM 31


int main() {
    Lista lista[TAM];
    int op, length;
    
    iniciarHash(lista);

    do {
        printf("\n\t0 - SAIR\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n\t4 - Contar Colisoes\n\t5 - ler o arquivo\n\t6 - Por a lista de palavra na tabela hash\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                Inserir(lista);
                break;
            case 2:
                buscarPalavras(lista);
                break;
            case 3:
                imprimirHash(lista);
                break;
            case 4:
                ContarDiferente(lista);
                break;
            case 5:
                leituraArquivo();
                break;
            case 6:
                ColocarTabelaHash(lista);
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
