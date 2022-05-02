#include <bits/stdc++.h>
using namespace std;

void mezclar(int a[], int b[], int c[], int na, int nb){
	int i=0,j=0,k=0;
	while(i<na || j<nb){
		if(i<na && j<nb){
			if(a[i]<b[j]){
				c[k++]=a[i++];
			}
			else{
				c[k++]=b[j++];
			}
		}else if(i<na){
			c[k++]=a[i++];
		}else{
			c[k++]=b[j++];
		}
	}
}

void ordenMezcla(int s[], int dest[],int a, int b){
	int p,i;
	if(a>=b)
		return;
	p=(a+b)/2;  
	for(i=a;i<=b;i++){
		dest[i]=s[i];
	}
	ordenMezcla(dest,s,a,p);
	ordenMezcla(dest,s,p+1,b);
	mezclar(&s[a],&s[p+1],&dest[a],p-a+1,b-p);
}

void printArray(int A[], int size){ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

int main(){
	int arr[] = {6,3,8,5,7,1,4,6,3}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	int dest[arr_size];
	printArray(arr, arr_size); 
	
	ordenMezcla(arr,dest, 0, arr_size - 1); 

	printArray(dest, arr_size); 
	return 0;
}