#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void show(vector<int> vet){
    for(int i=0;i<vet.size();i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &A){
    for(int i=0;i<A.size();i++){
        for(int j=A.size()-1;j>0;j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vet(n);
    for(int i=0; i< n;i++){
        cin >> vet[i];
    }

    show(vet);
    bubbleSort(vet);
    show(vet);
    return 0;
}
