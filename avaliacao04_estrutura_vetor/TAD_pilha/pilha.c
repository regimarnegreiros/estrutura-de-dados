#include <stdlib.h>

#include "pilha.h"

struct pilha {
	unsigned int *dados;
	int length;
	int limit;
};

Pilha *criarPilha(int limit) {
	Pilha *p = malloc(sizeof(Pilha));
	if (p == NULL)
		return NULL;
	p->dados = malloc(sizeof(unsigned int) * limit);
	if (p->dados == NULL) { // Erro na inicialização da pilha
		free(p);
		return NULL;
	}
	p->length = 0;
	p->limit = limit;
	return p;
}

void liberarPilha(Pilha *p) {
	free(p->dados);
	free(p);
}

/**
 *  Retorna o elemento do topo da pilha.
 * Se a pilha estiver vazia retorna -1.
 */
int top(Pilha *p) {
	if (p->length == 0)
		return -1;

	return p->dados[p->length - 1];
}

/**
 *  Remove o elemento do topo da pilha e retorna para o usuário.
 * Se a pilha estiver vazia retorna -1.
 */ 
int pop(Pilha *p) {
	if (p->length == 0)
		return -1;

	int valor = p->dados[p->length - 1];
	p->length--;
	return valor;
}

/**
 *  Insere um novo elemento no topo da pilha. 
 * Caso a pilha estiver cheia (length == limit), não será permitido uma nova inserção.
 */
void push(Pilha *p, unsigned int dado) {
	if (p->length == p->limit)
		return;
	
	p->length++;
	p->dados[p->length - 1] = dado;
}