#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct no {
    int dado;
    struct no *prox;
};

struct fila {
    No *inicio;
    No *fim;
    unsigned int length;
};

No *criar_no(int dado) {
    No *no = malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return NULL;
    }
    no->dado = dado;
    no->prox = NULL;
    return no;
}

Fila *criar_fila() {
    Fila *fila = malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->length = 0;
    return fila;
}

void print_fila(Fila *fila) {
    if (fila == NULL) {
        printf("Fila não inicializada.\n");
        return;
    }
    
    No *no = fila->inicio;
    while (no != NULL) {
        printf("(%d)->", no->dado);
        no = no->prox;
    }
    printf("NULL\n");
}

void enfileira(Fila *fila, int valor) {
    if (fila == NULL) {
        printf("Fila não inicializada.\n");
        return;
    }
    
    No *no = criar_no(valor);
    if (no == NULL) {
        return;
    }
    
    if (fila->inicio == NULL) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->prox = no;
        fila->fim = no;
    }
    fila->length++;
}

int desenfileira(Fila *fila) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("Fila vazia.\n");
        return -1;
    }

    int valor;
    if (fila->inicio->prox == NULL) {
        valor = fila->inicio->dado;
        free(fila->inicio);
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->length--;
        return valor;
    }

    No *buffer = fila->inicio;
    valor = fila->inicio->dado;
    fila->inicio = fila->inicio->prox;
    free(buffer);
    fila->length--;
    return valor;
}

void deletar_fila(Fila *fila) {
    if (fila == NULL) {
        printf("Fila não inicializada.\n");
        return;
    }

    No *atual = fila->inicio;
    No *buffer;

    while (atual != NULL) {
        buffer = atual;
        atual = atual->prox;
        free(buffer);
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->length = 0;

    free(fila);
}
