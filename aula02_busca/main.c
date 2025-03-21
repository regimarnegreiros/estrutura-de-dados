#include <stdio.h>
#include <stdlib.h>

// Retorna o número de ocorrências do valor buscado.
int numero_ocorrencias(int n, int vetor[n], int alvo) {
    int contagem = 0;
    for(int i = 0; i < n; i++) {
        if(vetor[i] == alvo) contagem++;
    }
    return contagem;
}

// Retorna o índice da última ocorrência do valor buscado.
int ultima_ocorrencia(int n, int vetor[n], int alvo) {
    for(int i = n - 1; i >= 0; i--) {
        if(vetor[i] == alvo) return i;
    }
    return -1;
}

// Imprime na tela o maior e o menor elemento de um vetor.
void maior_menor(int n, int vetor[n]) {
    if(n == 0) {
        fprintf(stderr, "Vetor vazio.\n");
        return;
    }
    int maior = vetor[0];
    int menor = vetor[0];
    for(int i = 1; i < n; i++) {
        if(maior < vetor[i]) maior = vetor[i];
        if(menor > vetor[i]) menor = vetor[i];
    }
    printf("Maior: %d Menor: %d\n", maior, menor);
}

int main() {
    return 0;
}