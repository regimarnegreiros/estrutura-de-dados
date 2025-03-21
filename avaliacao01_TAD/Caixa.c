#include <stdio.h>
#include <stdlib.h>
#include "Caixa.h"

struct caixa {
    float comprimento, largura, altura;
};

Caixa * criar_caixa(float comprimento, float largura, float altura) {
    Caixa *c = malloc(sizeof(Caixa));
    if(c != NULL) {
        c->comprimento = comprimento;
        c->largura = largura;
        c->altura = altura;
    }
    return c;
}

void liberar_caixa(Caixa * c) {
    free(c);
}

void exibir_caixa(Caixa * c) {
    printf("Comprimento = %.2f \nLargura = %.2f \nAltura = %.2f \n",
        c->comprimento, c->largura, c->altura);
} 

void area_caixa(Caixa * c) {
    float area = c->comprimento * c->largura;
    printf("Área = %.2f\n", area);
}

void volume_caixa(Caixa * c) {
    float volume = c->comprimento * c->largura * c->altura;
    printf("Volume = %.2f\n", volume);
}