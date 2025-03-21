#ifndef PILHA_H
#define PILHA_H

// Protótipo da estrutura
typedef struct pilha Pilha;

// Protótipo das operações
Pilha *criarPilha(int limit);
void liberarPilha(Pilha *p);


int top(Pilha *p);
int pop(Pilha *p);
void push(Pilha *p, unsigned int dado);

#endif // PILHA_H