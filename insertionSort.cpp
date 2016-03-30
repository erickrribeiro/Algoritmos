#include<iostream>
#include<vector>
using namespace std;
void show(vector<int> vet){
    for(int i=0;i<vet.size();i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}
void insertionSort(vector<int> &vet){
    int i;
    for(int j=1;j<vet.size();j++){
        int chave = vet[j];
        i= j-1;
        while(i>=0 && vet[i] > chave){
            vet[i+1] = vet[i];
            i-= 1;
        }
        vet[i+1] = chave;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> vetor(n, 0);
    for(int i=0; i< n;i++){
        cin >> vetor[i];
    }
    show(vetor);
    insertionSort(vetor);
    show(vetor);
}
