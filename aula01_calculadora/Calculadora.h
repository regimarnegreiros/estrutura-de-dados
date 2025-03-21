#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct calculadora Calculadora;

Calculadora* criar();
void destruir(Calculadora * c);
void exibir(Calculadora * c);
void zerar(Calculadora * c);
void somar(Calculadora * c, float valor);
void subtrair(Calculadora * c, float valor);
void multiplicar(Calculadora * c, float valor);
void dividir(Calculadora * c, float valor);

#endif