#include <stdlib.h>

#include "fila.h"

struct fila {
	unsigned int *dados;
	int length;
	int limit;
};

Fila *criarFila(int limit) {
	Fila *f = malloc(sizeof(Fila));
	if (f == NULL)
		return NULL;
	f->dados = malloc(sizeof(unsigned int) * limit);
	if (f->dados == NULL) { // Erro na inicialização da fila
		free(f);
		return NULL;
	}
	f->length = 0;
	f->limit = limit;
	return f;
}

void liberarFila(Fila *f) {
	free(f->dados);
	free(f);
}

/**
 * Insere um novo elemento no fim da fila. 
 * Caso a fila estiver cheia (length == limit), não será permitido uma nova inserção.
 */
void enfileira(Fila *f, unsigned int dado) {
	if (f->length == f->limit)
		return;
	
	f->length++;
	f->dados[f->length - 1] = dado;
}

/**
 * Remove o primeiro elemento da fila.
 * Se a fila estiver vazia (length == 0), retorna -1.
 */
int desenfileira(Fila *f) {
	if (f->length == 0)
		return -1;

	int valor = f->dados[0];
	for (int i = 0; i < f->length - 1; i++) {
		f->dados[i] = f->dados[i+1];
		f->length--;
	}
	
	return valor;
}

// Retorna o tamanho da fila.
int fila_tamanho(Fila *f) {
    return f->length;
}

// Retorna o vetor da fila.
unsigned int *fila_dados(Fila *f) {
    return f->dados;
}
