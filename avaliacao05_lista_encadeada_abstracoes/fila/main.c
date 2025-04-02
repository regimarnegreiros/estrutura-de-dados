#include <stdlib.h>
#include "Fila.h"

int main() {
    Fila *fila = criar_fila();
    
    enfileira(fila, 10);
    enfileira(fila, 20);
    enfileira(fila, 30);
    
    print_fila(fila);
    
    desenfileira(fila);

    print_fila(fila);
    desenfileira(fila);
    
    print_fila(fila);
    
    enfileira(fila, 40);
    
    print_fila(fila);
    
    desenfileira(fila);
    desenfileira(fila);
    
    print_fila(fila);

    deletar_fila(fila);
    
    return 0;
}

// gcc -o main main.c Fila.c