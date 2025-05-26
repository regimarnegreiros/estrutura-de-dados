#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
    No *esq;
    No *dir;
    int dado;
};

int maior(int n1, int n2) {
    return (n1 > n2) ? 
        n1 : n2;
    // if(n1 > n2) return n1;
    // else return n2;
}

int altura(No *arv) {
    if(arv == NULL) return -1; // critério de parada
    return maior(altura(arv->esq),altura(arv->dir)) + 1;
}

int fb(No *arv) {
    if(arv == NULL) return -1;
    return altura(arv->esq) - altura(arv->dir);
}

No *criar_no(int dado) {
    No *novo = malloc(sizeof(No));
    if(novo) {
        novo->dir = NULL;
        novo->esq = NULL;
        novo->dado = dado;
    }
    return novo;
}

No *rot_esq(No *arv) {
    No *dir = arv->dir;
    arv->dir = dir->esq;
    dir->esq = arv;
    return dir;
}

No *rot_dir(No *arv) {
    No *esq = arv->esq;
    arv->esq = esq->dir;
    esq->dir = arv;
    return esq;
}

void exibir_pre_ordem(No *arv) {
    if(arv) {
        printf("(%d)", arv->dado);
        exibir_pre_ordem(arv->esq);
        exibir_pre_ordem(arv->dir);
    }
}

No *balancear(No *arv) {
    // 1. utilizar pos-ordem
    // 2. calcular fb do nó
    // 3. aplicar algoritmo de rotação adequada
    if (arv) {
        arv->esq = balancear(arv->esq);
        arv->dir = balancear(arv->dir);
        // printf("(%d)", arv->dado);
        int fb_arv = fb(arv);
        if (fb_arv > 1) {
            if (arv->esq->esq) {
                arv = rot_dir(arv);
            } else {
                arv->esq = rot_esq(arv->esq);
                arv = rot_dir(arv);
            }
        } else if (fb_arv < -1) {
            if (arv->dir->dir) {
                arv = rot_esq(arv);
            } else {
                arv->dir = rot_dir(arv->dir);
                arv = rot_esq(arv);
            }
        }
        return arv;
    }
}


int main() {
    No *raiz = criar_no(5);
    raiz->esq = criar_no(3);
        raiz->esq->dir = criar_no(4);
    raiz->dir = criar_no(9);
        raiz->dir->esq = criar_no(7);
            raiz->dir->esq->esq = criar_no(6);
            raiz->dir->esq->dir = criar_no(8);
    // raiz->dir->dir = NULL;

    exibir_pre_ordem(raiz); puts("");
    raiz = balancear(raiz);
    exibir_pre_ordem(raiz); puts("");
    
    return 0;
}