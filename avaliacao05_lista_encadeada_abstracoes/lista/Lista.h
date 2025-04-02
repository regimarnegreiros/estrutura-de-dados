#ifndef LISTA_H
#define LISTA_H

typedef struct no No;
typedef struct lista Lista;

Lista *criar_lista();
void listar(Lista *lista);
void inserir_inicio(Lista *lista, int valor);
void inserir_fim(Lista *lista, int valor);
void inserir_ordenado(Lista *lista, int valor);
void deletar_inicio(Lista *lista);
void deletar_fim(Lista *lista);
void deletar_lista(Lista *lista);

#endif