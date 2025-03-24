#include <stdio.h>
#include <stdlib.h>


typedef struct no No;
typedef struct no {
    int dado;
    struct no *proximo;
} No;

No *criar_no(int dado) {
    No *no = malloc(sizeof(No));
    if (no) {
        no->dado = dado;
        no->proximo = NULL;
    }
    return no;
}

No *criar_lista_encadeada(int n) {
    if (n < 1) return NULL;
    
    No *fim = criar_no(0);
    No *inicio = fim;
    for (int i = 1; i < n; i++) {
        fim->proximo = criar_no(0);
        fim = fim->proximo;
    }

    return inicio;
}

void print_lista(No *inicio) {
    for (No *i = inicio; i != NULL; i = i->proximo) {
        printf("(%d)->", i->dado);
    }
    puts("NULL");
}

void inserir_inicio(No **inicio, int dado) {
    No *novo_no = criar_no(dado);
    if (!novo_no) return;
    novo_no->proximo = *inicio;
    (*inicio) = novo_no;
}

void inserir_fim(No *inicio, int dado) {
    No *i = inicio; 
    while (1) {
        if (i->proximo == NULL) {
            i->proximo = criar_no(dado);
            return;
        }
        i = i->proximo;
    }
}

int main() {
    No *lista1 = criar_lista_encadeada(4);
    print_lista(lista1);

    inserir_inicio(&lista1, 9);
    print_lista(lista1);
    
    inserir_fim(lista1, 8);
    print_lista(lista1);
    
    return 0;
}