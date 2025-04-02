#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct no {
    int dado;
    struct no *prox;  
};

struct lista {
    No *inicio;
    No *fim;
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

Lista *criar_lista() {
    Lista *lista = malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->length = 0;
    }
    return lista;
}

void listar(Lista *lista) {
    if (lista == NULL) return;
    No *no = lista->inicio;
    while (no != NULL) {
        printf("(%d)->", no->dado);
        no = no->prox;
    }
    printf("NULL\n");
}

void inserir_inicio(Lista *lista, int valor) {
    if (lista == NULL) return;
    No *no = criar_no(valor);
    if (!no) return;
    if (lista->inicio == NULL) {
        lista->inicio = no;
        lista->fim = no;
    } else {
        No *buffer = lista->inicio;
        lista->inicio = no;
        lista->inicio->prox = buffer;
    }
    lista->length++;
}

void inserir_fim(Lista *lista, int valor) {
    if (lista == NULL) return;
    No *no = criar_no(valor);
    if (!no) return;
    if (lista->inicio == NULL) {
        lista->inicio = no;
        lista->fim = no;
    } else {
        lista->fim->prox = no;
        lista->fim = lista->fim->prox;
    }
    lista->length++;
}

void deletar_inicio(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) return;
    if (lista->inicio->prox == NULL) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->length--;
        return;
    }
    No *buffer = lista->inicio;
    lista->inicio = lista->inicio->prox;
    free(buffer);
    lista->length--;
}

void deletar_fim(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) return;
    if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->length--;
        return;
    }
    No *i = lista->inicio;
    while (i->prox != lista->fim) {
        i = i->prox;
    }
    lista->fim = i;
    free(lista->fim->prox);
    lista->fim->prox = NULL;
    lista->length--;
}

void inserir_ordenado(Lista *lista, int valor) {
    if (lista == NULL) return;
    No *no = criar_no(valor);
    if (!no) return;

    if (lista->inicio == NULL) {
        lista->inicio = no;
        lista->fim = no;
        lista->length++;
        return;
    }

    if (valor < lista->inicio->dado) {
        inserir_inicio(lista, valor);
        lista->length++;
        return;
    }

    No *atual = lista->inicio;
    while (atual->prox != NULL && atual->prox->dado < valor) {
        atual = atual->prox;
    }

    no->prox = atual->prox;
    atual->prox = no;

    if (no->prox == NULL) {
        lista->fim = no;
    }

    lista->length++;
}

void deletar_lista(Lista *lista) {
    if (lista == NULL) return;
    No *atual = lista->inicio;
    No *buffer;

    while (atual != NULL) {
        buffer = atual;
        atual = atual->prox;
        free(buffer);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->length = 0;

    free(lista);
}
