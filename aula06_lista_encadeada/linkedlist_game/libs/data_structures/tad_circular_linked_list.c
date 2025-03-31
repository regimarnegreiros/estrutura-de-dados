#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../../includes/terminal.h"
#include "../../includes/data_structures/tad_circular_linked_list.h"

#define PI 3.14159265

typedef struct no {
    char dado;
    struct no *prox;
} No;

struct circularLinkedList {
    No *inicio;
    int length;
};

CircularLinkedList *criar_lista() {
    CircularLinkedList *lista = malloc(sizeof(CircularLinkedList));
    if(lista) { // Se a alocação foi bem sucedida: lista != NULL
        lista->inicio = NULL;
        lista->length = 0;
    }
    return lista;
}

No *criar_no(int dado) {
    No *no = malloc(sizeof(No));
    if(no) {
        no->dado = dado;
        no->prox = NULL;
    }
    return no;
}



// Desenha um nó na tela em forma de círculo
void desenharNoEmFormaDeCirculo(int x, int y, char dado, int font_bg) {
    definir_propriedade_da_fonte(font_bg);
    for(int raio = 0, index = 0; raio < 3; raio++) {
      for(int i = 0; i < 90; i++) {
          float rad = i * PI / 180;
          // quarter circle
          int x1 = x + round(cos(rad) * raio);
          int y1 = y + round(sin(rad) * raio);
          printf("\033[%d;%dH ", y1, x1);

          // quarter circle
          x1 = x + round(cos(rad) * raio);
          y1 = y - round(sin(rad) * raio);
          printf("\033[%d;%dH ", y1, x1);

          // quarter circle
          x1 = x - round(cos(rad) * raio);
          y1 = y + round(sin(rad) * raio);
          printf("\033[%d;%dH ", y1, x1);

          // quarter circle
          x1 = x - round(cos(rad) * raio);
          y1 = y - round(sin(rad) * raio);
          printf("\033[%d;%dH ", y1, x1);
      }
    }
    printf("\033[%d;%dH%c", y, x, dado);
    resetar_fonte();
}


// Desenha uma lista circular na tela em forma de círculo
void desenharListaCircularEsquerda(int x, int y, float raio, CircularLinkedList *list, char gabarito[]) {
    No *no = list->inicio;
    for(int i = 0, j = 0; i < 360; i += 360.0/list->length, no = no->prox, j++) {
        float rad = i * PI / 180;
        int x1 = x + round(cos(rad) * raio);
        int y1 = y + round(sin(rad) * raio);
        desenharNoEmFormaDeCirculo(x1, y1, no->dado, gabarito[j] == no->dado ? BG_GREEN : BG_RED);
    }
    resetar_fonte();
}
// Desenha uma lista circular na tela em forma de círculo
void desenharListaCircularDireita(int x, int y, float raio, CircularLinkedList *list, char gabarito[]) {
    No *no = list->inicio;
    for(int i = 0, j = 0; i < 360; i += 360.0/list->length, no = no->prox, j++) {
        float rad = i * PI / 180;
        int x1 = x - round(cos(rad) * raio);
        int y1 = y - round(sin(rad) * raio);
        desenharNoEmFormaDeCirculo(x1, y1, no->dado, gabarito[j] == no->dado ? BG_GREEN : BG_RED);
    }
    resetar_fonte();
}

int lista_igual_vetor(CircularLinkedList *lista, char vetor[], int n) {
    No *aux = lista->inicio;
    int i = 0;
    if(aux) {
        do {
            if(aux->dado != vetor[i]) {
                return 0;
            }
            aux = aux->prox;
            i++;
        } while(aux != lista->inicio);
    }
    return 1;
}

void deletarListaCircular(CircularLinkedList *lista) {
    if(!lista) return;
    No *aux = lista->inicio;
    if(aux) {
        do {
            No *temp = aux;
            aux = aux->prox;
            free(temp);
        } while(aux != lista->inicio);
    }
    free(lista);
}

void listar(CircularLinkedList *lista) {
    if(!lista) return;
    No *aux = lista->inicio;
    if(aux) {
        do {
            printf("(%c)->", aux->dado);
            aux = aux->prox;
        } while(aux != lista->inicio);
    }
    printf("*inicio\n");
}

// ------------------------------------------------------------------------------
// implemente aqui
// ------------------------------------------------------------------------------
void rotacionarLista(CircularLinkedList *list) {
    No *b = list->inicio;
    No *final = list->inicio;

    while (final->prox != list->inicio) {
        final = final->prox;
    }

    list->inicio = final;
    list->inicio->prox = b;
}

void trocar(CircularLinkedList *leftList, CircularLinkedList *rightList) {
    char b = leftList->inicio->dado;
    leftList->inicio->dado = rightList->inicio->dado;
    rightList->inicio->dado = b;
}

void inserir_vetor_na_lista(CircularLinkedList *lista, char vetor[], int n) {
    No *inicio = lista->inicio;
    No *final = lista->inicio;

    if (lista->inicio == NULL) {
        lista->inicio = criar_no(vetor[0]);
        final = lista->inicio;
        lista->inicio->prox = lista->inicio;
        lista->length = 1;
    } else {
        while (final->prox != lista->inicio) {
            final = final->prox;
        }
    }

    for (int i = 1; i < n; i++) {
        No *novoNo = criar_no(vetor[i]);
        final->prox = novoNo;
        final = novoNo;
        lista->length++;
    }
    final->prox = lista->inicio;
}

