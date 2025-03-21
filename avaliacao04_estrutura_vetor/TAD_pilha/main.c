#include <stdio.h>
#include "pilha.h"

int main() {
	Pilha *p = criarPilha(4);

	printf("Adicionados:\n");
	push(p, 1);
	printf("%d\n", top(p));
	push(p, 2);
	printf("%d\n", top(p));
	push(p, 3);
	printf("%d\n", top(p));
	push(p, 4);
	printf("%d\n", top(p));
	
	printf("Removidos:\n");
	printf("%d\n", top(p));
	pop(p);
	printf("%d\n", top(p));
	pop(p);
	printf("%d\n", top(p));
	pop(p);
	printf("%d\n", top(p));
	pop(p);
	printf("%d\n", top(p));
	pop(p);

	liberarPilha(p);
	return 0;
}