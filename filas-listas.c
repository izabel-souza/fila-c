#include "filas-listas.h"

TFila *inicializa(void){
    TFila *fila = malloc(sizeof(TFila));
    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int fila_vazia(TFila *f){
    if(f->inicio == NULL) return 1;
    else return 0;
}

void insere(TFila *f, int elem){
    TLista *novo = malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL;

    if(fila_vazia(f)) {
        f->inicio = novo;
    }
    else {
        f->fim->prox = novo;
    }

    f->fim = novo; 
}

/*
 * Remove elemento da fila e retorna info do elemento excluído
 */
int retira(TFila *f){
    if(!fila_vazia(f)) {
        TFila *aux = f->inicio;
        int aux2 = f->inicio->info;
        f->inicio = f->inicio->prox;

        if(f->inicio == NULL) f->fim = NULL;

        free(aux);
        return aux2;
    }
    else printf("Fila vazia"); exit(1);
}

void libera(TFila *f){
    TLista *r, *aux = f->inicio;
    while(aux != NULL) {
        r = aux;
        aux = aux->prox;

        free(r);
    }
    free(aux);
}

void altera_inicio(TFila *f, int elem){
    if(!fila_vazia(f)) {
        f->inicio->info = elem;
    }
    else return -1;
}

void imprime_fila(TFila *f){
    for(TLista *p = f->inicio; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

int main (void) {

    TFila *fila = inicializa();

    insere(fila, 5);
    insere(fila, 3);
    insere(fila, 2);

    printf("\nFila original:\n");
    imprime_fila(fila);

    int x = retira(fila);
    printf("\nelemento %d retirado da fila\n", x);
    printf("\nFila apos remocao:\n");
    imprime_fila(fila);

    altera_inicio(fila, 172423);
    printf("\nFila apos alteracao do inicio:\n");
    imprime_fila(fila);
    libera(fila);

    return 0;
}