#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Hash.h"

void leituraArquivo() {
    FILE *arquivo;
    arquivo = fopen("ListaDePalavras.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    int linha = 1;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        printf("Linha %d: %s", linha, buffer);
        linha++;
    }

    fclose(arquivo);
}

int calcularPesoASCII(const char *texto) {
    int comprimento = strlen(texto);
    int soma = 0;

    for (int i = 0; i < comprimento; i++) {
        if (texto[i] != '\n') {
            soma += texto[i] * (i + 1) * 10;
        }
    }
    return soma;
}

void ColocarTabelaHash(Lista list[]) {
    FILE *arquivo;
    arquivo = fopen("ListaDePalavras.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    int linha = 1;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        
        char *texto = (char *)malloc(strlen(buffer) + 1);

        if (texto == NULL) {
            printf("Erro ao alocar memória para o texto.\n");
            fclose(arquivo);
            return;
        }

        strcpy(texto, buffer);
    
        char *posicaoQuebra = strchr(texto, '\n');
    
        if (posicaoQuebra != NULL) {
            *posicaoQuebra = '\0';
        }
        
        inserirHash(list, texto);
        
        int soma = calcularPesoASCII(texto);
        int id = funcaoHash(&soma);
        
        printf("Linha %d: %s\n\n", linha, texto);

        linha++;
    }

    fclose(arquivo);
}












