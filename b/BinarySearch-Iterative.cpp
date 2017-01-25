#include <stdio.h>
 
/*
  Implementação do algoritmo de pesquisa binária iterativo.
*/
int binarySearch(int arr[], int l, int r, int key)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    /*Verifica se o elemento está no meio*/
    if (arr[m] == key) 
        return m;  
 
    /*Se key é maior que o meio, então ignora o subarray a esquerda.*/
    if (arr[m] < key) 
        l = m + 1; 
 
    /*Se key é menor que o meio, então ignora o subarray e direita.*/
    else
         r = m - 1; 
  }
 
  /*Caso o elemento não seja encontrado, retorna -1.*/
  return -1; 
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("O elemento não está presente no array.")
                 : printf("O elemento está presente no indice %d", result);
   return 0;
}