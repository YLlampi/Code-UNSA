#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    
	int n = 10;
    vector<int> A(n);

	for(int i = 0; i < n; i++){
		A[i] = 1 + rand() % 10;
	}

	for(auto i : A){
		cout << i << ' ';
	}

	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(A[j] > A[j+1]){
				swap(A[j], A[j+1]);
			}
		}
	}
	*/

	for(int i = 0; i < A.size() - 1; i++){
		for(int j = A.size(); j > i; j--){
			if(A[j] < A[j-1]){
				swap(A[j], A[j-1]);
			}
		}
	}

	cout << '\n';

	for(auto i : A){
		cout << i << ' ';
	}
	

	

    return 0;
}