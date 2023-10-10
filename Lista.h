typedef struct No {
    void *Data;
    struct No *Proximo;
}No;

typedef struct Lista{
    No *Inicio;
    int Tam;
}Lista;

void Init(Lista *list);
int InserirInicioLista(Lista *list, void* Data);
int InserirUltimoLista(Lista *list, void* Data);
void* RemoverInicioLista(Lista *list);
void* RemoverFinalLista(Lista *list);
void ShowLista(Lista *list);
void* Verificar(Lista *list);


