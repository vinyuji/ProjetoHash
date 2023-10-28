#include "stdbool.h"

typedef struct No {
    void *data;
    struct No *Proximo;
}No;



typedef struct Lista{
    No *Inicio;
    int Tam;
}Lista;

typedef bool (*compare)(void*,void*);


void Init(Lista *list);
int InserirInicioLista(Lista *list, void* data);
int InserirUltimoLista(Lista *list, void* data);
void* RemoverInicioLista(Lista *list);
void* RemoverFinalLista(Lista *list);
void* removeposicao(Lista *Lista, int posicao);
void ShowLista(Lista *list);
int Verificar(Lista *list);
int indexOf(Lista *list, void *data, compare equal);


