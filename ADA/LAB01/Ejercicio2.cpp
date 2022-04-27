#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    
    int n = 100;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        A[i] = 1 + rand() % 100;
    }

    sort(A.begin(), A.end());

    int index;
	int elemBuscar = 10;
	
	int u = 0;
	int y = n-1;
	
    bool band = false;

	while(u <= y){
		index = (u+y)/2;
		if(elemBuscar == A[index]){
			band = true;
			break;
		}
		else if(elemBuscar > A[index]) u = index+1;
		else if(elemBuscar < A[index]) y = index-1;	
	}
	
    cout << band << '\n';

    return 0;
}