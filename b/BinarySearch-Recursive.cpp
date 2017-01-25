#include <stdio.h>
/*
  Implementação do algoritmo de pesquisa binária recursiva.
*/
int binarySearch(int arr[], int l, int r, int key)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2; //Encontra o meio do vetor.
 
        /*Se o elemento está no meio, então retorna o indice.*/
        if (arr[mid] == key)  return mid;
 
        /*Se o elemento é menor que o meio, então precisamos somente do subarray a esquerda. */
        if (arr[mid] > key) return binarySearch(arr, l, mid-1, key);
 
        /*Se o elemento é maior que o meio, então precisamos somente do subarray a direita.*/
        return binarySearch(arr, mid+1, r, key);
   }
 
   /*Caso o elemento não seja encontrado, retorna -1.*/
   return -1;
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 4;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("O elemento não está presente no array.")
                 : printf("O elemento está presente no indice %d.", result);
   return 0;
}