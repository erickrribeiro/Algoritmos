#include<iostream>
using namespace std;
 
/*
    Retorna o maior elemento em uma array.
*/

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

/*
    Função reponsável por imprimir o array na tela.
*/
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

 
/*
    Função de ordenação por contagem para um determinado digito.
*/
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
 
    //Cria um vetor de contagem de 0-9 com a ocorrencia de cada digito.
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    //Atualiza o vetor de contagem, agora em cada nova posição é adicionado o valor anterior.
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /*
    Com base no vetor de contagem, é ajustado o vetor final. A ordenação dos digitos é feita em
    ordem crescente
    */

    for (i = n - 1; i >= 0; i--)
    {
        int atCount = (arr[i]/exp) %10;
        int atOutPut = count[ atCount ] - 1;

        output[atOutPut] = arr[i];
        count[ atCount]--;
    }

    ///Copia os valores do vetor pelos digitos para o vetor original de entrada.
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
/*
    Algoritmo Radix Sort
*/
void radixsort(int arr[], int n)
{
    //Encontra a maior elemento, importante para definir quantidade de dígitos base.
    int m = getMax(arr, n);
 
    //Efetua a ordenação por contagem para cada digito de um número.
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
  
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66,9999};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
