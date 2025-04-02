#ifndef FILA_H
#define FILA_H

typedef struct no No;
typedef struct fila Fila;

Fila *criar_fila();
void print_fila(Fila *fila);
void enfileira(Fila *pilha, int valor);
int desenfileira(Fila *pilha);
void deletar_fila(Fila *fila);

#endif