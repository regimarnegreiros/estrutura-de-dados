#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

struct no {
    int dado;
    struct no *prox;  
};

struct pilha {
    No *topo;
    unsigned int length;
};

No *criar_no(int dado) {
    No *no = malloc(sizeof(No));
    if (no) {
        no->dado = dado;
        no->prox = NULL;
    }
    return no;
}

Pilha *criar_pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    if (pilha) {
        pilha->topo = NULL;
        pilha->length = 0;
    }
}

void empilha(Pilha *pilha, int valor) {
    No *no = criar_no(valor);
    if (!no) return;
    if (pilha->topo == NULL) {
        pilha->topo = no;
    } else {
        no->prox = pilha->topo;
        pilha->topo = no;
    }
    pilha->length++;
}

void desempilha(Pilha *pilha) {
    if (pilha->topo == NULL) return;

    No *buffer = pilha->topo;
    pilha->topo = pilha->topo->prox;

    free(buffer);
    pilha->length--;
}

void topo(Pilha *pilha) {
    if (pilha->topo == NULL) return;
    printf("[%d]\n", pilha->topo->dado);
}

void deletar_pilha(Pilha *pilha) {
    No *atual = pilha->topo;
    No *buffer;

    while (atual != NULL) {
        buffer = atual;
        atual = atual->prox;
        free(buffer);
    }

    pilha->topo = NULL;
    pilha->length = 0;

    free(pilha);
}