#include <stdio.h>
#include <stdlib.h>

typedef struct vetor {
    int *dados;
    int tamanho;
    int limite;
} Vetor;

Vetor *criar_vetor(int limite) {
    if(limite < 1) return NULL;
    
    Vetor *v = malloc(sizeof(Vetor));
    if(v == NULL) return v;

    v->tamanho = 0;
    v->limite = limite;
    v->dados = calloc(limite, sizeof(int));
    if(v->dados == NULL) {
        free(v);
        v = NULL;
    }

    return v;
}

int is_null(Vetor *v) {
    if(v == NULL) {
        fprintf(stderr, "Vetor nulo.\n");
        return 1;
    }
    return 0;
}

void liberar_vetor(Vetor **v) {
    free((*v)->dados);
    free(*v);
    *v = NULL;
}

void print_vetor(Vetor *v) {
    if(is_null(v)) return;

    printf("{");
    for(int i = 0; i < v->tamanho-1; i++)
        printf("%d, ", v->dados[i]);
    
    if(v->tamanho <= 0) {
        puts("}");
        return;
    }

    printf("%d}\n", v->dados[v->tamanho-1]);
}

void acrescentar(Vetor *v, int n) {
    if(is_null(v)) return;
    if(v->tamanho >= v->limite) return;
    
    v->dados[v->tamanho] = n;
    v->tamanho++;
}

void deletar(Vetor *v, int n) {
    if(is_null(v)) return;
    for(int i = 0; i < v->tamanho-1; i++) {
        if(v->dados[i] == n) {
            for(int j = i; j < v->tamanho-1; j++) {
                v->dados[j] = v->dados[j+1];
            }
            v->tamanho--;
            break;
        }
    }
}

int main() {
    Vetor *v = criar_vetor(10);
    acrescentar(v, 1);
    acrescentar(v, 2);
    acrescentar(v, 3);
    acrescentar(v, 4);
    acrescentar(v, 5);
    acrescentar(v, 6);
    acrescentar(v, 7);
    print_vetor(v);
    
    deletar(v, 3);
    print_vetor(v);
    
    liberar_vetor(&v);

    return 0;
}