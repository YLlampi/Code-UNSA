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

/*
* Ejercicio 2
*
* Verificar si el arreglo ya se encuentra ordenado
* Complejidad O(n)
*
*/
bool verificarSort(int arr[], int n){
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

/*
* Ejercicio 3
*
* divide el arreglo en 3 partes
* izquierda: elementos menores que el pivote
* centro: elementos iguales que el pivote
* derecha: elementos mayores que el pivote
*
*/
void partition(int arr[], int a, int b, int& i, int& j){
    i = a - 1, j = b;
    int p = a - 1, q = b;
    int v = arr[b];
 
    while(true){
        while (arr[++i] < v);

        while (v < arr[--j])
            if (j == a) break;
 
        if (i >= j) break;

        swap(arr[i], arr[j]);
 
        if (arr[i] == v) {
            p++;
            swap(arr[p], arr[i]);
        }
 
        if(arr[j] == v){
            q--;
            swap(arr[j], arr[q]);
        }
    }
 
    swap(arr[i], arr[b]);
 
    j = i - 1;
    for (int k = a; k < p; k++, j--)
        swap(arr[k], arr[j]);
 
    i = i + 1;
    for (int k = b - 1; k > q; k--, i++)
        swap(arr[i], arr[k]);
}



void quicksort(int arr[], int a, int b){ 
	/*
	if (a < b){ 
		int pi = partition(arr, a, b); 
		quicksort(arr, a, pi - 1); 
		quicksort(arr, pi + 1, b); 
	}
	*/

	if(b <= a) return;
	int i, j;
	partition(arr, a, b, i, j);
	quicksort(arr, a, j);
    quicksort(arr, i, b);


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
    
	if(verificarSort(arr, n)){
		cout << "El arreglo ya se encuentra ordenado" << '\n';
	} else{
		t0 = clock();
		quicksort(arr,0, n-1);
		t1 = clock();
	}
	
    cout << "Arreglo Ordenado:" << '\n';
    imprimir(arr, n);
    
    
    double time0 = (double(t1-t0)/CLOCKS_PER_SEC);
    
    cout << "Time Normal: " << time0 << '\n';

    return 0;
} 