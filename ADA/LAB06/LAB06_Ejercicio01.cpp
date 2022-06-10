#include <bits/stdc++.h>
using namespace std; 

unsigned t0, t1;
unsigned h0, h1;
unsigned u0, u1;

void swap(int* a, int* b){ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition(int arr[], int a, int b) { 
	int pivot = arr[b];

	int i = a - 1;

	for (int j = a; j <= b - 1; j++) { 
		if (arr[j] < pivot) { 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[b]); 
	return (i + 1); 
} 

void quicksort(int arr[], int a, int b){ 
	if (a < b){ 
		int pi = partition(arr, a, b); 
		quicksort(arr, a, pi - 1); 
		quicksort(arr, pi + 1, b); 
	} 
}

void imprimir(int arr[], int n) {
	for (int i = 0; i < n; i++) 
		cout << arr[i] << ' '; 
	cout <<'\n'; 
} 

int main() {
    srand(time(NULL));

    const int n = 10;
    //cout << "Size Vector: "; cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = 1 + rand() % 99;
    }
    
    cout << "Arreglo Original:" << '\n';
    imprimir(arr, n);

    t0 = clock();
    quicksort(arr,0, n-1);
    t1 = clock();
    
    
    cout << "Arreglo Ordenado:" << '\n';
    imprimir(arr, n);
    
    
    double time0 = (double(t1-t0)/CLOCKS_PER_SEC);
    
    cout << "Time Normal: " << time0 << '\n';

    return 0;
} 