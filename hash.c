#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include <string.h>

void initHash(TabelaHash *TabelaHash){
    for (int i=0;i<100;i++){

        Init(&(TabelaHash->hashes[i]));
        
    }
    TabelaHash->tam = 0;
}


bool Tabelavazia(TabelaHash *TabelaHash){
    return TabelaHash -> tam==0; 
}

int hash(char *key) {
    
    int somador = 0;

    for (int i = 0; key[i]!=0;i++){
        somador+=key[i]*(i+1);
    }
    int Hashvalue = somador%100;
        
        return Hashvalue;
}

int puthash(TabelaHash *TabelaHash, char *key, void *valor, compare equal){
    if(!ChaveValor(TabelaHash, key, equal)){

        int resultado = InserirInicioLista(&TabelaHash->hashes[hash(key)],valor);

        TabelaHash->tam+=resultado;

        return resultado;
    }
    return 0;
}

bool ChaveValor(TabelaHash *TabelaHash, char *key, compare equal){
    
    int HashValue =hash(key);
    int posicao = indexOf(&TabelaHash->hashes[HashValue],key , equal); {

        return(posicao!=1)?true:false;
    }

}

void* get(TabelaHash *TabelaHash,char *key, compare equal){
    
    int HashValue = hash(key);

No *aux = TabelaHash->hashes[HashValue].Inicio->Proximo;
    
while(aux!=TabelaHash->hashes[HashValue].Inicio && !equal (key,aux->data))

aux=aux->Proximo;

return aux->data;
}

void* removekey(TabelaHash *TabelaHash, char *key, compare equal){

int Hashvalue = hash(key);
int posicao = indexOf(&TabelaHash->hashes[Hashvalue],key, equal);

void* resultado =removeposicao(&TabelaHash->hashes[Hashvalue],posicao);
if (resultado !=NULL) TabelaHash->tam--;

return resultado;

}



void mostrarHash(TabelaHash *TabelaHash, printNo print) {
    printf("Aqui está o elemento do Hash %d\n\n", TabelaHash->tam);
    
    for (int i = 0; i < 100; i++) {
        printf("Hash %d e %d são:\n", i, TabelaHash->hashes[i].Tam);
        print(&TabelaHash->hashes[i]);
        printf("\n");
    }
}
