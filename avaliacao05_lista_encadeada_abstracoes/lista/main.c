#include <stdlib.h>
#include "Lista.h"

int main() {
    Lista *lista = criar_lista();
    deletar_inicio(lista);
    listar(lista);
    deletar_fim(lista);
    listar(lista);
    inserir_fim(lista, 4);
    listar(lista);
    deletar_inicio(lista);
    inserir_inicio(lista, 4);
    deletar_fim(lista);
    listar(lista);
    inserir_inicio(lista, 3);
    listar(lista);
    inserir_inicio(lista, 2);
    listar(lista);
    inserir_inicio(lista, 1);
    listar(lista);
    inserir_fim(lista, 5);
    listar(lista);
    deletar_inicio(lista);
    listar(lista);
    deletar_fim(lista);
    listar(lista);

    Lista *lista2 = criar_lista();

    inserir_ordenado(lista2, 10);
    listar(lista2);

    inserir_ordenado(lista2, 5);
    listar(lista2);

    inserir_ordenado(lista2, 7);
    listar(lista2);

    inserir_ordenado(lista2, 15);
    listar(lista2);

    inserir_ordenado(lista2, 9);
    listar(lista2);

    inserir_ordenado(lista2, 20);
    listar(lista2);

    inserir_ordenado(lista2, 3);
    inserir_ordenado(lista2, 8);
    inserir_ordenado(lista2, 13);
    inserir_ordenado(lista2, 18);
    listar(lista2);

    deletar_lista(lista);
    deletar_lista(lista2);
    return 0;
}

// gcc -o main main.c Lista.c