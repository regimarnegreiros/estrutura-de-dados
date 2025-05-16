#include <stdio.h>

void merge(int ini, int meio, int tam, int v[tam]) {
    // tam = 8
    // ini = 0
    // meio = (tam + ini)/2
    // v[tam] [5][ ][ ][ ][3][7][ ][ ] (tam = 8)
    //         0  1  2  3  4  5  6  7
    //        ini        meio          tam
    //                    i             j
    //    w[k++] = v[i] < v[j] ? v[i++] : v[j++]
    // w[8]  [3][5][6]...
    //        0  1  2
    //        k
    // tam = 8
    // ini = 4
    // meio = (tam + ini)/2 = (8+4)/2 = 6
    // v[tam] [ ][ ][ ][ ][ ][ ][ ][ ] (tam = 8)
    //         0  1  2  3  4  5  6  7
    //                    ini  meio   tam
    int i = ini;
    int j = meio;
    int w[tam-ini];
    int k = 0;
    while(i < meio && j < tam) {
        // if(v[i] < v[j]) w[k++] = v[i++];
        // else w[k++] = v[j++];
        w[k++] = v[i] > v[j] ? v[i++] : v[j++];
    }
    while(i < meio) w[k++] = v[i++];
    while(j <  tam) w[k++] = v[j++];
    // w já está mesclado
    // for(k = 0, i = ini; k < tam-ini; k++, i++) 
    //    v[i] = w[k];
    k = 0; i = ini; // inicialização
    while(k < tam-ini) v[i++] = w[k++];
}

void exibir(int n, int v[n]) {
    for(int i = 0; i < n; i++) printf("[%d]",v[i]);
    printf("\n");
}

void mergesort(int ini, int tam, int vet[]) {
    if(tam - ini == 1) return; // critério de parada
    // passo recursivo
    int meio = (tam + ini)/2;
    mergesort(ini, meio, vet); // ini < meio
    mergesort(meio, tam, vet); // meio < tam
    merge(ini, meio, tam, vet);
}

int main() {
    int vet[8] = {2,4,5,7,1,2,3,6};
    exibir(8, vet);
    merge(0, (8+0)/2, 8, vet);
    exibir(8, vet);
    // mergesort
    int vet2[6] = {5,2,4,3,1,6};
    printf("mergesort: \n");
    exibir(6, vet2);
    mergesort(0, 6, vet2);
    exibir(6, vet2);
    return 0;
}