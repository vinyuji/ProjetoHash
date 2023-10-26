#include <stdlib.h>
#include <Stdio.h>
#include "hash.h"
#include <string.h>


void initHash(TabelaHash *TabelaHash){
    for (int i=0;i<100;i++){

        init(&(TabelaHash->hashes[i]));
        
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
    int Hashvalue = somador%MAX;
        
        return Hashvalue;
}

int puthash(TabelaHash *TabelaHash, char *key, void *valor, compare equal){
    if(!ChaveValor(TabelaHash, key equal)){

        int res = enqueue(&TabelaHash->hashes[hash(key)],valor);

        TabelaHash->tam+=res;

        return res;
    }
    return 0;
}

bool ChaveValor(TabelaHash *TabelaHash, char *key, compare equal){
    
    int HashValue =hash(key);
    int posicao = indexOF(&TabelaHash->hases[HashValue],key, comapre equal) {

        return(posicao!=1)?true:false;
    }

}

void* get(TabelaHash *TabelaHash,char *key, compare equal){
    
    int HashValue = hash(key);

Node *aux = TabelaHash->hashes[HashValue].first->next;
    
while(aux!=TabelaHash->hashes[HashValue].first && !equal (key,aux->valor))

aux=aux->next;

return aux->valor 
}

void* removekey(TabelaHash *TabelaHash, char *key, compare equal){

int Hashvalue = hash(key);
int posicao = indexOF(&TabelaHash->hashes[Hashvalue],key, posicao);

void* resultado =removePosicao(&TabelaHash->hashes[Hashvalue],posicao);
if (resultado !=NULL) TabelaHash->tam--;

return resultado;

}

void mostrarHash(TabelaHash *TabelaHash, printNode print){
    
        printf("Aqui esta o elemento do Hash %d /n/n ",TabelaHash->tam);
for (int i=0,i<100,i++){
       
     printf("hash %d e %d sao :", i,TabelaHash->hashes[i].tam);
        
 show(&TabelaHash->hashes[i].print);
    
     printf("/n");

    }
}