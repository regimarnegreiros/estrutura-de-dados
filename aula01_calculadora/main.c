#include "Calculadora.h"

int main() {
    Calculadora *c;
    c = criar();

    exibir(c);
    somar(c, 10);
    exibir(c);
    dividir(c, 0);
    exibir(c);
    somar(c, 7);
    exibir(c);

    zerar(c);

    destruir(c);

    return 0;
}