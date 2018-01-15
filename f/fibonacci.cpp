#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

#define T double
using namespace std;

vector<T> MEMO(101, -1);

T fibonacciDinamic(T n){
	if( n < 3 ){
		return 1;
	}

	if(MEMO[n] == -1){
		MEMO[n] = fibonacciDinamic(n - 2) + fibonacciDinamic(n - 1);
		return MEMO[n];
	}else{
		return MEMO[n];
	}
}

T fibonacciRecursive(T n){
	if( n < 3 ){
		return 1;
	}
	return fibonacciRecursive(n - 2) + fibonacciRecursive(n - 1);
}

T fibonacciIteratice(T n){
	T ant = 1, ant2 = 0;
	for(T i=1; i < n+1; i+=1){
		ant2 = ant + ant2;
		ant  = ant2 - ant; 
	}
	return ant2;
}

int main(){
	T test[] = {10, 20, 30, 50, 100};
	size_t kSize = 5;
	
	cout << "Versão iteratica!!" << endl;
	for (size_t i = 0;i < kSize; i+= 1){
		clock_t begin = clock();
		cout << "\nn:" << test[i] << " - fib(n): " << fibonacciIteratice(test[i]);
        
        clock_t end = clock();
        
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cout << fixed << "\nTempo gasto: " << time_spent << " em segundos.\n";
	}

	cout << "\n\nVersão dinamica!!" << endl;
	for (size_t i = 0;i < kSize; i+= 1){
		
		clock_t begin = clock();
		cout << "\nn:" << test[i] << " - fib(n): " << fibonacciDinamic(test[i]);
      
        clock_t end = clock();
        
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << "\nTempo gasto: " << time_spent << " em segundos.\n";
	}

	cout << "\n\nVersão recursiva!!" << endl;
	for (size_t i = 0;i < kSize; i+= 1){
		
		clock_t begin = clock();
		cout << "\nn:" << test[i] << " - fib(n): " << fibonacciRecursive(test[i]);
      
        clock_t end = clock();
        
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << fixed << "\nTempo gasto: " << time_spent << " em segundos.\n";
	}

	return 0;
}