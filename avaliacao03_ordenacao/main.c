#include <stdio.h>

void print_arr(int n, int arr[n]) {
    printf("{");
    for(int i = 0; i < n-1; i++)
    printf("%d, ", arr[i]);
    printf("%d}\n", arr[n-1]);
}

void selection_sort_min_max(int n, int arr[n]) {
    int min, max, temp;
    int meio = n%2 == 0? n/2 : n/2 + 1;

    for(int i = 0; i < meio; i++) {
        min = i;
        max = i;

        for(int j = i; j < n-i; j++) {
            if(arr[min] > arr[j]) min = j;
            if(arr[max] < arr[j]) max = j;
        }

        if(min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

        if(max != n-i-1) {
            temp = arr[n-i-1];
            arr[n-i-1] = arr[max];
            arr[max] = temp;
        }

        print_arr(n, arr);
    }
}

void bubble_sort(int n, int arr[n]) {
    int temp = 0;
    int trocou = 0;

    int qt_comparacoes = 0;
    int qt_trocas = 0;
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            qt_comparacoes++;
            if(arr[j] > arr[j+1]) {
                trocou = 1;
                qt_trocas++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // print_arr(n, arr);
            }
        }
        if(!trocou) return;
        trocou = 0;
    }
    printf("Bubble sort\nComparações: %d Trocas: %d\n", qt_comparacoes, qt_trocas);
}

void selection_sort(int n, int arr[n]) {
    int min = 0;
    int temp = 0;

    int qt_comparacoes = 0;
    int qt_trocas = 0;
    
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            qt_comparacoes++;
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i) {
            qt_trocas++;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        // print_arr(n, arr);
    }

    printf("Selection sort\nComparações: %d Trocas: %d\n", qt_comparacoes, qt_trocas);
}

void insertion_sort(int n, int arr[n]) {
    int qt_comparacoes = 0;
    int qt_trocas = 0;
    
    for(int i = 0; i < n-1; i++) {
        int j = i+1;
        int temp = arr[j];

        while(j > 0 && arr[j-1] > temp) {
            qt_comparacoes++;
            arr[j] = arr[j-1];
            qt_trocas++;
            j--;
            // print_arr(n, arr);
        }
        arr[j] = temp;
        qt_trocas++;
    }

    printf("Inserction sort\nComparações: %d Trocas: %d\n", qt_comparacoes, qt_trocas);
}

int main() {
    int arr1[10] = {5, 3, 1, 9, 5, 7, 6, 2, 10, 4};
    selection_sort_min_max(10, arr1);
    puts("");
    
    int arr2[11] = {5, 3, 1, 9, 5, 7, 6, 2, 10, 4, 11};
    selection_sort_min_max(11, arr2);
    puts("");
    
    int arr3[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubble_sort(10, arr3);
    print_arr(10, arr3);
    puts("");
    
    int arr4[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selection_sort(10, arr4);
    print_arr(10, arr4);
    puts("");
    
    int arr5[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    insertion_sort(10, arr5);
    print_arr(10, arr5);
    puts("");

    /*
    Bubble sort
    Comparações: 45 Trocas: 45
    O vetor utilizado é o pior caso para o algoritmo, dessa forma ocorrendo o máximo de comparações e trocas. 

    Selection sort
    Comparações: 45 Trocas: 5
    Executa a mesma quantidade de comparações do algoritmo anterior, porém menos trocas desnecessárias, sendo assim mais eficiente.

    Inserction sort
    Comparações: 45 Trocas: 54
    Realiza a mesma quantidade de comparações que os algoritmos anteriores e realiza muitas trocas, já que ele precisa reordenar o vetor toda vez que faz uma "inserção", mesmo utilizando o algoritmo mais performático.
    */

    return 0;
}