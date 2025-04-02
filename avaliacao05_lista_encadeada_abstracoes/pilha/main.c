#include <stdlib.h>
#include "Pilha.h"

int main() {
    Pilha *pilha = criar_pilha();
    
    empilha(pilha, 10);
    topo(pilha);

    empilha(pilha, 20);
    topo(pilha);

    empilha(pilha, 30);
    topo(pilha);

    desempilha(pilha);
    topo(pilha);

    desempilha(pilha);
    topo(pilha);

    desempilha(pilha);
    topo(pilha);

    desempilha(pilha);
    topo(pilha);

    deletar_pilha(pilha);

    return 0;
}

// gcc -o main main.c Pilha.c