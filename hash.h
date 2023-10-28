#include "Lista.h"
#include "stdbool.h"

typedef void (*printNo)(void *);


    typedef struct TabelaHash{
    Lista hashes[100];
    int tam;

}TabelaHash;

void initHash(TabelaHash *TabelhaHash);
bool Tabelavazia(TabelaHash *TabelaHash);
int hash(char *key);
int puthash(TabelaHash *TabelaHash, char *key, void *data, compare equal);
void* get (TabelaHash *TabelaHash, char *Key, compare equal);
void* removekey(TabelaHash *TabelaHash, char *key, compare equal);
void mostrarHash(TabelaHash *TabelaHash, printNo print);
bool ChaveValor(TabelaHash *TabelaHash, char *key, compare equal);
void show(const char *);

