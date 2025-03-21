#ifndef CAIXA_H
#define CAIXA_H

typedef struct caixa Caixa;

Caixa* criar_caixa(float comprimento, float largura, float altura);
void liberar_caixa(Caixa *c);
void exibir_caixa(Caixa *c);
void area_caixa(Caixa *c);
void volume_caixa(Caixa *c);

#endif