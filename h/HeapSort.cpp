#include <iostream>
using namespace std;




/*
    Exibe os dados do array.
*/
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 

/*
    O Heapify é a função responsável por criar a estrutura Heap de acordo com as suas 
    características, esse em específico cria um heap maximo.
*/ 
void heapify(int arr[], int size, int root)
{
    int largest = root;  
    int l = 2*root + 1;  // seleciona o filho da esquerda.
    int r = 2*root + 2;  // seleciona o filho da direita.
 
    //Se o filho da esquerda for maior que a raiz, então define ele como maior.
    if (l < size && arr[l] > arr[largest])
        largest = l;
 
    //Se o filho da direita for maior que a raiz, então define ele como maior.
    if (r < size && arr[r] > arr[largest])
        largest = r;
 
    // Se o maior elemento não for a raiz, então executa o heapify para o resto do heap executando a correção.
    if (largest != root)
    {

        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}
 /*
    Algoritmo do Heap Sort
 */
void heapSort(int arr[], int n)
{
    /* Contrução do Heap, executando o heapify do fim até o meio do array*/
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    /* Um por um retira os elementos do heap.*/

    for (int i=n-1; i>=0; i--)
    {
        /*Troca o primeiro elemento (raiz) pelo último.*/
        swap(arr[0], arr[i]);
 
        /*Ajusta o array como um heap novamente.*/
        heapify(arr, i, 0);
    }
} 

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}
