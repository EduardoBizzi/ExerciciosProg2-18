//Quick sort
#include <iostream>
#define N 10
using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Seleciona o último elemento como pivô
    int i = low - 1;        // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(arr[i], arr[j]); // Troca os elementos
        }
    }
    swap(arr[i + 1], arr[high]); // Coloca o pivô na posição correta
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    printArray(arr, n);
    return 0;
}