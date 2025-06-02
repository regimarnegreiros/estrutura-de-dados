#include <stdio.h>
#include <stdlib.h>

void prototipo(int, int p2, char p3);

typedef struct {
    char nome[250];
    int idade;
} Pessoa;

typedef struct no {
    int chave;
    Pessoa valor;
    struct no *prox;
} NoChaveValor;

// Lista encadeada
typedef struct lista {
    NoChaveValor *inicio;
    int size;
} ListaEnc;

// Implementar a lista enc.

// hash(25) -> 5
int hash10(int idade) {
    return idade % 10;
}

// <K, V>
typedef struct {
    ListaEnc *listas;
    int (*h)(int valor);
} HashTable;

HashTable *criarTabelaHash(int size, int (*h)(int)) {
    HashTable *ht = malloc(sizeof(HashTable));
    if(!ht) return NULL;
    ht->listas = calloc(size, sizeof(ListaEnc));
    if(!ht->listas) {
        free(ht);
        return NULL;
    }
    ht->h = h;
    return ht;
}

NoChaveValor *criarNo(int chave, Pessoa valor) {
    NoChaveValor *novo = malloc(sizeof(NoChaveValor));
    if(novo) {
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

// Chave é a idade
void inserir(Pessoa p, HashTable *ht) {
    if(!ht) return;
    // obter o valor de Hash
    int h = ht->h(p.idade);
    
    // inserir pessoa p na posição 
    ht->listas[h];
    // pode estar vazio
    // caso vazio:
    // Lista
    if(ht->listas[h].size == 0) { // lista vazia
        // - inserir no início
        ht->listas[h].inicio = criarNo(p.idade, p);
        ht->listas[h].size++;
    } else {
        // caso não vazio:
        // - verificar se o valor de chave já existe
        //      - em caso positivo: sobrescreve
        //      - senão: insere ordenado
        NoChaveValor *atual = ht->listas[h].inicio;
        NoChaveValor *anterior = NULL;

        while(atual != NULL) {
            if(atual->chave == p.idade) {
                // chave já existe, sobrescreve
                atual->valor = p;
                return;
            }
            anterior = atual;
            atual = atual->prox;
        }

        // chave não existe, insere no final
        NoChaveValor *novo = criarNo(p.idade, p);
        anterior->prox = novo;
        ht->listas[h].size++;
    }
}



int main() {
    HashTable *ht = criarTabelaHash(10, hash10);
    
    for (int i = 0; i < 10; i++) {
        ht->listas[i].inicio = NULL;
        ht->listas[i].size = 0;
    }

    Pessoa p1 = {"Jõao", 25};
    Pessoa p2 = {"Carlos", 32};
    Pessoa p3 = {"Josiscreuda", 27};
    Pessoa p4 = {"Daniel", 25};
    Pessoa p5 = {"Clara", 29};
    Pessoa p6 = {"Regimar", 19};

    inserir(p1, ht);
    inserir(p2, ht);
    inserir(p3, ht);
    inserir(p4, ht);
    inserir(p5, ht);
    inserir(p6, ht);

    for (int i = 0; i < 10; i++) {
        printf("Lista %d:\n", i);
        NoChaveValor *no = ht->listas[i].inicio;
        while (no != NULL) {
            printf("  Chave: %d, Nome: %s, Idade: %d\n", no->chave, no->valor.nome, no->valor.idade);
            no = no->prox;
        }
    }

    return 0;
}