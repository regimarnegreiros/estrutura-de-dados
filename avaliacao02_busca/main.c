#include <stdio.h>
#include <stdlib.h>

// Substitui a última ocorrencia do alvo selecionado.
void substitui_valor(int n, int vetor[n], int alvo, int novo_valor) {
    for(int i = n - 1; i >= 0; i--) {
        if(vetor[i] == alvo) {
            vetor[i] = novo_valor;
            return;
        }
    }
}

// Algoritimo de busca binária que mostra o número de diviões.
int busca_binaria(int tamanho, int vetor[], int valor) {
    int inicio = 0, fim = tamanho - 1, meio, numero_divisoes = 0;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            printf("Número de divisões: %d\n", numero_divisoes);
            return meio;
        } else if (vetor[meio] < valor) {
            numero_divisoes++;
            inicio = meio + 1;
        } else {
            numero_divisoes++;
            fim = meio - 1;
        }
    }
    
    printf("Número de divisões: %d\n", numero_divisoes);
    return -1; // Elemento não encontrado
}

// Retorna o índice do valor buscado de forma otimizada em O(n/2).
int busca_sequencial_otimizada(int n, int vetor[n], int alvo) {
    int meio = n / 2;

    for(int i = 0; i < meio; i++) {
        if(vetor[i] ==  alvo) return i;
        meio++;
        if((meio) >= n) break;
        if(vetor[meio] == alvo) return meio;
    }
    return -1;
}

// Retorna o elemento mais próximo do alvo em um vetor ordenado de forma crescente. Se houver dois elementos igualmente próximos será retornado o menor entre eles.
int busca_binaria_proximo(int n, int vetor[n], int alvo) {
    int inicio = 0; int fim = n-1; int meio;

    do {
        meio = (inicio + fim) / 2;

        if(alvo > vetor[meio]) {
            inicio = meio + 1;
            continue;
        }
        if(alvo < vetor[meio]) {
            fim = meio - 1;
            continue;
        }

        return vetor[meio];
    } while(inicio <= meio && fim >= meio);

    meio = (inicio + fim) / 2;

    int distancia_meio = abs(vetor[meio] - alvo);
    int distancia_frente = abs(vetor[fim] - alvo);
    int distancia_tras = abs(vetor[inicio] - alvo);

    if (distancia_meio <= distancia_frente && distancia_meio <= distancia_tras)
        return vetor[meio];
    else if (distancia_frente <= distancia_tras)
        return vetor[fim];
    else
        return vetor[inicio];
}

int main() {
    printf("=== Testando substitui_valor ===\n");

    int vetor1[] = {1, 2, 3, 4, 5};
    substitui_valor(5, vetor1, 3, 99);
    printf("Teste 1 (última ocorrência do 3 substituída por 99): %d\n", vetor1[2]);

    int vetor2[] = {1, 2, 3, 3, 3};
    substitui_valor(5, vetor2, 3, 99);
    printf("Teste 2 (última ocorrência do 3 substituída por 99): %d\n", vetor2[4]);

    int vetor3[] = {1, 2, 4, 5, 6};
    substitui_valor(5, vetor3, 3, 99);
    printf("Teste 3 (valor 3 não presente, vetor inalterado): %d, %d, %d, %d, %d\n", 
        vetor3[0], vetor3[1], vetor3[2], vetor3[3], vetor3[4]);

    printf("\n=== Testando busca_binaria ===\n");

    int vetor4[] = {1, 2, 3, 4, 5};
    printf("Teste 1 (buscando 3): %d\n\n", busca_binaria(5, vetor4, 3));

    int vetor5[] = {10, 20, 30, 40, 50};
    printf("Teste 2 (buscando 10): %d\n\n", busca_binaria(5, vetor5, 10));

    int vetor6[] = {10, 20, 30, 40, 50};
    printf("Teste 3 (buscando 50): %d\n\n", busca_binaria(5, vetor6, 50));

    int vetor7[] = {10, 20, 30, 40, 50};
    printf("Teste 4 (buscando valor ausente 25): %d\n", busca_binaria(5, vetor7, 25));

    printf("\n=== Testando busca_sequencial_otimizada ===\n");

    int vetor8[] = {1, 2, 3, 4, 5};
    printf("Teste 1 (buscando 3): %d\n", busca_sequencial_otimizada(5, vetor8, 3));

    int vetor9[] = {10, 20, 30, 40, 50};
    printf("Teste 2 (buscando 40): %d\n", busca_sequencial_otimizada(5, vetor9, 40));

    int vetor10[] = {10, 20, 30, 40, 50};
    printf("Teste 3 (buscando 60, inexistente): %d\n", busca_sequencial_otimizada(5, vetor10, 60));

    printf("\n=== Testando busca_binaria_proximo ===\n");
    int vetor_tamanho_1[] = {10};
    printf("Teste 1: Vetor de tamanho 1, alvo 10:\n");
    printf("Resultado: %d\n", busca_binaria_proximo(1, vetor_tamanho_1, 10));
    
    int vetor_repetidos[] = {1, 1, 1, 1, 1};
    printf("\nTeste 2: Vetor com elementos repetidos, alvo 1:\n");
    printf("Resultado: %d\n", busca_binaria_proximo(5, vetor_repetidos, 1));
    
    int vetor_repetidos_ausente[] = {1, 1, 1, 1, 1};                        
    printf("\nTeste 3: Vetor com elementos repetidos, alvo 2:\n");
    printf("Resultado: %d\n", busca_binaria_proximo(5, vetor_repetidos, 2));  
    
    int vetor_maior_que_todos[] = {1, 2, 3, 4, 5};          
    printf("\nTeste 4: Valor maior que todos os elementos, alvo 10:\n");
    printf("Resultado: %d\n", busca_binaria_proximo(5, vetor_maior_que_todos, 10));
    
    int vetor_menor_que_todos[] = {1, 2, 3, 4, 5};
    printf("\nTeste 5: Valor menor que todos os elementos, alvo 0:\n");
    printf("Resultado: %d\n", busca_binaria_proximo(5, vetor_menor_que_todos, 0));
    
    int vetor_impar[] = {1, 2, 3, 4, 5, 6, 7};
    printf("\nTeste 6: Vetor de tamanho ímpar, alvo 4:\n");
    printf("Resultado: %d\n", busca_binaria_proximo(7, vetor_impar, 4));

    int vetor_exemplo_1[] = {2, 5, 6, 7, 8, 8, 9};
    printf("\nTeste 7: Exemplo 1 da atividade alvo 4: \n");
    printf("Resultado: %d\n", busca_binaria_proximo(7, vetor_exemplo_1, 4));

    int vetor_exemplo_2[] = {2, 3, 5, 6, 7, 8, 8, 9}; 
    printf("\nTeste 8: Exemplo 2 da atividade alvo 4: \n");
    printf("Resultado: %d\n", busca_binaria_proximo(8, vetor_exemplo_2, 4));

    return 0;
}