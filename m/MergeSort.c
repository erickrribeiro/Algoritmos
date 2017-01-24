#include<stdlib.h>
#include<stdio.h>
 
/* 
    Função responsável por realizar o merge entre dois subarray. 
    O primeiro subarray é arr[l..m] e o segundo subarray é arr[m+1..r]
*/
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    //Cria dois arrays temporários.
    int L[n1], R[n2];
 
    /* Copia os dados para os arrays L[] e R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge dos valores de L[i] e R[j] para o array arr[l..r]*/
    i = 0; // Posição inicial do array L[i]
    j = 0; // Posição inicial do array R[j]
    k = l; // Posição inicial do array arr[l..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* 
        Copia os elementos remanescentes de L[i], caso R[j] tenha terminado.
    */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* 
        Copia os elementos remanescentes de R[j], caso L[i] tenha terminado.
    */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* 
    Parte dividir e conquistar do MergeSort.
*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        //A divisão do array duas sub-metades
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 
/*
    Exibe os dados do array.
*/
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
