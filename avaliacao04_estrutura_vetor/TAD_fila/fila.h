#ifndef FILA_H
#define FILA_H

// protótipo da estrutura
typedef struct fila Fila;

// protótipo das operações
Fila *criarFila(int limit);
void liberarFila(Fila *f);


int desenfileira(Fila *f);
void enfileira(Fila *f, unsigned int dado);

int fila_tamanho(Fila *f);
unsigned int *fila_dados(Fila *f);

#endif // FILA_H