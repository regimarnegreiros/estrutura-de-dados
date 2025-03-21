#include <stdio.h>

void print_arr(int n, int arr[n]) {
    printf("{");
    for(int i = 0; i < n-1; i++)
    printf("%d, ", arr[i]);
    printf("%d}\n", arr[n-1]);
}

void bubble_sort(int n, int arr[n]) {
    int temp = 0;
    int trocou = 0;

    for(int j = 0; j < n; j++){
        for(int i = n-1; i > j; i--){
            if(arr[i] < arr[i-1]) {
                trocou = 1;
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                print_arr(n, arr);
            }
        }
        if(!trocou) {
            printf("Terminou de organizar antes de percorrer tudo.\n");
            return;
        }
        trocou = 0;
    }
}

void selection_sort(int n, int arr[n]) {
    int indice_maior = 0;
    int temp = 0;

    for(int i = n-1; i >= 0; i--) {
        indice_maior = i;
        for(int j = i-1; j >= 0; j--) {
            if(arr[j] > arr[indice_maior])
                indice_maior = j;
        }
        if(indice_maior != i) {
            temp = arr[i];
            arr[i] = arr[indice_maior];
            arr[indice_maior] = temp;
        }
        print_arr(n, arr);
    }
}

int main() {
    int arr1[10] = {5, 3, 1, 9, 5, 7, 6, 2, 10, 4};
    bubble_sort(10, arr1);
    
    puts("");
    int arr2[10] = {1, 3, 2, 4, 5, 7, 6, 10, 9, 8};
    bubble_sort(10, arr2);
    
    puts("");
    int arr3[10] = {5, 3, 1, 9, 5, 7, 6, 2, 10, 4};
    selection_sort(10, arr3);

    puts("");
    int arr4[10] = {1, 3, 2, 4, 5, 7, 6, 10, 9, 8};
    selection_sort(10, arr4);

    return 0;
}