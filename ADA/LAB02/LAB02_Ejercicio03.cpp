#include <bits/stdc++.h>
using namespace std;

void merge(int gArray[], int izq, int mid1, int mid2, int der, int arr[]){
	int i = izq, j = mid1, k = mid2, l = izq;

	while ((i < mid1) && (j < mid2) && (k < der)){
		if(gArray[i] < gArray[j]){
			if(gArray[i] < gArray[k]) arr[l++] = gArray[i++];
			else
				arr[l++] = gArray[k++];
		} else{
			if(gArray[j] < gArray[k]) arr[l++] = gArray[j++];
			else arr[l++] = gArray[k++];
		}
	}

	while ((i < mid1) && (j < mid2)){
		if(gArray[i] < gArray[j]) arr[l++] = gArray[i++];
		else arr[l++] = gArray[j++];
	}

	while ((j < mid2) && (k < der)){
		if(gArray[j] < gArray[k]) arr[l++] = gArray[j++];
		else arr[l++] = gArray[k++];
	}

	while ((i < mid1) && (k < der)){
		if(gArray[i] < gArray[k]) arr[l++] = gArray[i++];
		else arr[l++] = gArray[k++];
	}

	while (i < mid1)
		arr[l++] = gArray[i++];

	while (j < mid2)
		arr[l++] = gArray[j++];

	while (k < der)
		arr[l++] = gArray[k++];
}


void mergeSort3Recursivo(int gArray[], int izq, int der, int arr[]){
	if (der - izq < 2)
		return;

	int mid1 = izq + ((der - izq) / 3);
	int mid2 = izq + 2 * ((der - izq) / 3) + 1;

	mergeSort3Recursivo(arr, izq, mid1, gArray);
	mergeSort3Recursivo(arr, mid1, mid2, gArray);
	mergeSort3Recursivo(arr, mid2, der, gArray);

	merge(arr, izq, mid1, mid2, der, gArray);
}

void mergeSort3(int gArray[], int n){
	if (n == 0)
		return;

	int fArray[n];

	for (int i = 0; i < n; i++)
		fArray[i] = gArray[i];

	mergeSort3Recursivo(fArray, 0, n, gArray);

	for (int i = 0; i < n; i++)
		gArray[i] = fArray[i];
}

int main(){
	int arr[] = {1, 7, 3, 0, 5, 8, 12, 98, 45};
	int size = sizeof(arr)/sizeof(arr[0]);

	mergeSort3(arr, size);
	
	for (int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}

	
	return 0;
}