#include <stdio.h>
#include "Lista.h"
#include "hash.h"
#include "arquivo.h"

#define WIDTH 64
#define HEIGHT 64

// Função para criar um arquivo PPM
void createPPM(int matrix[WIDTH][HEIGHT]) {
    FILE* ppmFile = fopen("GraficoVI.ppm", "w");
    if (ppmFile == NULL) {
        printf("Erro ao abrir o arquivo PPM\n");
        return;
    }

    // Escreva o cabeçalho do arquivo PPM
    fprintf(ppmFile, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    // Escreva as cores dos pixels com base no número de colisões
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int collisions = matrix[x][y];
            int r = collisions % 256;
            int g = (collisions / 256) % 256;
            int b = (collisions / 256 / 256) % 256;
            fprintf(ppmFile, "%d %d %d ", r, g, b);
        }
        fprintf(ppmFile, "\n");
    }

    fclose(ppmFile);
}

void verificaMatrix(int matrix[WIDTH][HEIGHT]){
    for(int i = 0;  i < HEIGHT ; i++){
        for (int x = 0; x < WIDTH; x++){
            printf("%d", matrix[x][i]);
        }
    }
}

void colorir(Lista list[]) {
    int matrix[WIDTH][HEIGHT]; 
    int posicao = 0;

    int maxColisoes = 0; 

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (list[i].Tam > maxColisoes) {
            maxColisoes = list[i].Tam;
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int colisoes = list[posicao].Tam;
            printf("\nColisoes[%d][%d]: %d\n", x, y, colisoes);

            int densidade = (list[posicao].Tam * 255) / maxColisoes;
            printf("valor de densidade: %d\n", densidade);
            matrix[x][y] = densidade;
            posicao++;
        }
    }
    printf("\nmatrix\n");
    verificaMatrix(matrix);
    createPPM(matrix);
}


