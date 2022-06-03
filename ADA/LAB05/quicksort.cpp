#include <bits/stdc++.h>
using namespace std; 

unsigned t0, t1;
unsigned h0, h1;

void swap(int* a, int* b){ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

// Complejidad O(n)
bool verificar(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;

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

/* ------------------------------------------- */

void quicksort(int arr[], int a, int b);

void quicksort1(int arr[], int a, int part1, int b){ 
	if (a < b){ 
		int pi = partition(arr, a, part1);
        int pi2 = partition(arr, part1, b);

		quicksort(arr, a, pi - 1); 
		quicksort(arr, pi + 1, pi2 - 1);
        quicksort(arr, pi2 + 1, b); 
	} 
} 

void quicksort(int arr[], int a, int b){
    int part1 = (a + b)/2;
    //int part2 = 2*part1;

    quicksort1(arr, a, part1, b);
}



/* ------------------------------------------- */

/*
void quicksort1(int arr[], int a, int b){ 
	if (a < b){ 
		int pi = partition(arr, a, b); 
		quicksort(arr, a, pi - 1); 
		quicksort(arr, pi + 1, b); 
	} 
}
*/

void insertion_sort(int arr[], int a, int n){
    for(int i=a+1;i<n+1;i++){
        int val = arr[i];
        int j = i;
        while (j>a and arr[j-1]>val){
            arr[j]= arr[j-1];
            j-= 1;
        }
        arr[j]= val;
    }
}

void quicksort_optimizado(int arr[], int a, int b){
    while(a < b){
        if (a-b + 1 < 30){
            insertion_sort(arr, a, b);
            break;
        }
        else{
            int pivot = partition(arr, a, b) ;
 
            if(pivot-a < b-pivot){
                quicksort_optimizado(arr, a, pivot - 1);
                a = pivot + 1;
            }
            else{
                quicksort_optimizado(arr, pivot + 1, b);
                b = pivot-1;
            }
        }
    }
}

void imprimir(int arr[], int n) {
	for (int i = 0; i < n; i++) 
		cout << arr[i] << ' '; 
	cout <<'\n'; 
} 

int main() {
    srand(time(NULL));

    int n = 30;
    //cout << "Size Vector: "; cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = 1 + rand() % 99;
    }
    
    cout << "Arreglo Original:" << '\n';
    imprimir(arr, n);

    if(verificar(arr, n)){
        cout << "Arreglo Original Ordenado" << '\n';
    }
    else{
        t0 = clock();
        quicksort(arr,0, n-1);
        t1 = clock();

        h0 = clock();
        quicksort_optimizado(arr, 0, n-1);
        h1 = clock();

        
        cout << "Arreglo Ordenado:" << '\n';
        imprimir(arr, n);
    }
    
    double time0 = (double(t1-t0)/CLOCKS_PER_SEC);
    double time1 = (double(h1-h0)/CLOCKS_PER_SEC);
    
    cout << "Time Normal: " << time0 << '\n';
    cout << "Time Optimizado: " << time1 << '\n';

   return 0;
} 