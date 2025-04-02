#ifndef PILHA_H
#define PILHA_H

typedef struct no No;
typedef struct pilha Pilha;

Pilha *criar_pilha();
void topo(Pilha *pilha);
void empilha(Pilha *pilha, int valor);
void desempilha(Pilha *pilha);
void deletar_pilha(Pilha *pilha);

#endif