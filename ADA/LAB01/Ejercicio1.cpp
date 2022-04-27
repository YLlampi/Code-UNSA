#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 100;
	vector<int> A(n);
	for(int q = 0; q < n; q++){
		A[q] = 1 + rand() % 100;
	}
	
	int key, i;
	for(size_t j = 1; j < A.size(); j++){
		key = A[j];
		i = j - 1;
		while(i >= 0 and A[i] > key){
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
	
	for(auto i : A){
		cout << i << '\n';
	}

    return 0;
}