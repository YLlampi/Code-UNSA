#include <bits/stdc++.h>
using namespace std;

int min(int x, int y){
	return (x < y) ? x : y;
}

void merge(vector<int>& A, vector<int>& temp, int from, int mid, int to){
	int k = from, i = from, j = mid + 1;

	while(i <= mid and j <= to){
		if(A[i] < A[j]){
			temp[k++] = A[i++];
		} else{
			temp[k++] = A[j++];
		}
	}

	while(i < A.size() and i <= mid){
		temp[k++] = A[i++];
	}

	for(int i = from; i <= to; i++){
		A[i] = temp[i];
	}
}

void mergeSort(vector<int>& A, vector<int>& temp, int low, int high){
	// dividir el array en bloques de size 'm'
	for(int m = 1; m <= high - low; m = 2*m){
		for(int i = low; i < high; i += 2*m){
			int from = i;
			int mid = i + m - 1;
			int to = min(i + 2*m - 1, high);

			merge(A, temp, from, mid, to);
		}
	}
}

void printArray(vector<int>& array){
	for(int i = 0; i < array.size(); i++){
		cout << array[i] << ' ';
	}
	cout << '\n';
}

int main(){
	int n = 10;
	vector<int> A(n), temp(n);

	for(int i = 0; i < n; i++){
		temp[i] = A[i] = rand() % 20;
	}

	cout << "Array Original: "  << '\n';
	printArray(A);

	mergeSort(A, temp, 0, n - 1);

	cout << "Array Ordenado: " << '\n';
	printArray(A);

	return 0;
}