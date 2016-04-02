#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> merge_sort(const std::vector<int> &data)
{
	if (data.size() <= 1) {
		return data;
	}

	int middle = data.size() / 2;
	vector<int> left(data.begin(), data.begin()+middle);
	vector<int> right(data.begin()+middle, data.end());

	left = merge_sort(left);
	right = merge_sort(right);

	vector<int> result(data.size());
	merge(left.begin(), left.end(), right.begin(), right.end(),result.begin());

	return result;
}

void show(vector<int> vet){
    for(int i=0;i<vet.size();i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    vector<int> vet(n);
    for(int i=0; i< n;i++){
        cin >> vet[i];
    }
    show(vet);
    vet = merge_sort(vet);
    show(vet);

}
