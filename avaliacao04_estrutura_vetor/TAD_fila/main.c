#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void print_fila(Fila *f) {
    if (f == NULL) return;

    printf("{");
    for (int i = 0; i < fila_tamanho(f) - 1; i++) {
        printf("%d, ", fila_dados(f)[i]);
    }
    
    if (fila_tamanho(f) <= 0) {
        puts("}");
        return;
    }

    printf("%d}\n", fila_dados(f)[fila_tamanho(f) - 1]);
}

int main() {
	Fila *f = criarFila(4);

	enfileira(f, 1);
	enfileira(f, 2);
	enfileira(f, 3);
	enfileira(f, 4);

	print_fila(f);
	desenfileira(f);
	print_fila(f);
	desenfileira(f);
	print_fila(f);
	desenfileira(f);
	print_fila(f);

	liberarFila(f);
	return 0;
}