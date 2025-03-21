#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Calculadora.h"

struct calculadora{
    float memoria;
};

Calculadora * criar() {
    Calculadora *c = malloc(sizeof(Calculadora));
    if (c != NULL) {
        c->memoria = 0;
    }
    return c;
}

void destruir(Calculadora * c) {
    free(c);
}

void exibir(Calculadora * c) {
    printf("%f\n", c->memoria);
}

void zerar(Calculadora * c) {
    c->memoria = 0;
}

void somar(Calculadora * c, float valor) {
    c->memoria += valor;
}

void subtrair(Calculadora * c, float valor) {
    c->memoria -= valor;
}

void multiplicar(Calculadora * c, float valor) {
    c->memoria *= valor;
}

void dividir(Calculadora * c, float valor) {
    if (valor == 0) {
        fprintf(stderr, "Divisão por 0 não permitida.\n");
        return;
    }
    c->memoria /= valor;
}