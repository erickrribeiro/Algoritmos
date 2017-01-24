#include<stdio.h>
 
// Utilizando para fazer a troca de dois elementos.
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/*
Esta função pega o últiomo elemento como pivô, colocando os elementos em sua posição correta com base no pivô. Todos
os elementos a esquerda do pivô são menores que ele, assim como os a direita são maiores que o pivô.
*/

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // O pivô é o ultimo elemento.
    int i = (low - 1);  //Indice do menor elemento.
 
    for (int j = low; j <= high- 1; j++)
    {
    	//Verifica se o elemento atual é menor ou igual ao Pivô.
        if (arr[j] <= pivot)
        {
            i++;    // Incrementa o incide para o menor elemento.
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}
 
/*
Implementação do QuickSort
*/
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
 
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
	Função para exibir o array.
*/
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
