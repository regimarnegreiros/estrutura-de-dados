#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
    int dado;
    No *esq;
    No *dir;
};

No *criar_no(int dado) {
    No *novo_no = malloc(sizeof(No));
    if(novo_no) {
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        novo_no->dado = dado;
    }
    return novo_no;
}

void inserir_ordenado(No *arvore, int dado) {
    if(!arvore) return;
    No *buffer = arvore;

    while(1) {
        if(dado < buffer->dado) {
            if(buffer->esq != NULL) {
                buffer = buffer->esq;
                continue;
            }
            buffer->esq = criar_no(dado);
            return;
        } else if (dado > buffer->dado) {
            if(buffer->dir != NULL) {
                buffer = buffer->dir;
                continue;
            }
            buffer->dir = criar_no(dado);
            return;
        } else {
            return;
        }
    }
}

int altura(No *arvore) {
    if(arvore == NULL) return -1;
    else {
        int altura_esq = altura(arvore->esq);
        int altura_dir = altura(arvore->dir);
        if (altura_esq > altura_dir)
            return 1 + altura_esq;
        else
            return 1 + altura_dir;
    }
}

int caminho(No *arvore, int dado) {
    if(arvore == NULL) return 0;

    if(arvore->dado == dado) {
        printf("(%d)", arvore->dado);
        return 1;
    }

    if(caminho(arvore->esq, dado)) {
        printf("<-(%d)", arvore->dado);
        return 1;
    }

    if(caminho(arvore->dir, dado)) {
        printf("<-(%d)", arvore->dado);
        return 1;
    }

    return 0;
}

int caminho_nl(No *arvore, int dado) {
    int retorno = caminho(arvore, dado);
    printf("\n");
    return retorno;
}

int total_nos(No *arvore) {
    if(arvore == NULL) return 0;
    return 1 + total_nos(arvore->dir) + total_nos(arvore->esq);
}

void exibir_pre_ordem(No *no) {
    if(no) {
        printf("(%d)", no->dado);
        exibir_pre_ordem(no->dir);
        exibir_pre_ordem(no->esq);
    }
}
void exibir_pre_ordem_nl(No *no) {
    exibir_pre_ordem(no);
    printf("\n");
}

void exibir_em_ordem(No *no) {
    if(no) {
        exibir_em_ordem(no->dir);
        printf("(%d)", no->dado);
        exibir_em_ordem(no->esq);
    }
}
void exibir_em_ordem_nl(No *no) {
    exibir_em_ordem(no);
    printf("\n");
}

void exibir_pos_ordem(No *no) {
    if(no) {
        exibir_pos_ordem(no->dir);
        printf("(%d)", no->dado);
        exibir_pos_ordem(no->esq);
    }
}
void exibir_pos_ordem_nl(No *no) {
    exibir_pos_ordem(no);
    printf("\n");
}


int main() {

    No *arvore = criar_no(7);
    inserir_ordenado(arvore, 2);
    inserir_ordenado(arvore, 3);
    inserir_ordenado(arvore, 5);
    inserir_ordenado(arvore, 4);
    inserir_ordenado(arvore, 8);
    inserir_ordenado(arvore, 1);
    printf("Altura da árvore: %d\n", altura(arvore));
    printf("Total de nós: %d\n", total_nos(arvore));

    exibir_pre_ordem_nl(arvore);
    exibir_em_ordem_nl(arvore);
    exibir_pos_ordem_nl(arvore);

    caminho_nl(arvore, 4);

    return 0;
}