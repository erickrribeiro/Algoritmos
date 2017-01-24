// C program for implementation of selection sort
#include <stdio.h>
 
/*
Função de Troca.
*/ 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_element;
 
    // Um por um é movimentado o limite do array não ordenado.
    for (i = 0; i < n-1; i++)
    {
        // Encontra o menor elemento. 
        min_element = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_element])
                min_element = j;
 
        // Troca o menor elemento para primeiro elemento.
        swap(&arr[min_element], &arr[i]);
    }
}

/*
Função para exibir o array
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}