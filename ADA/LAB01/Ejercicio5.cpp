#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    
	for(int k = 1, n=1000; k <= 100; k++, n+=1000){
		unsigned t0, t1;
		t0=clock();
		vector<int> A(n);
		for(int q = 0; q < n; q++){
			A[q] = 1 + rand() % (1000000-1);
		}
		
		for(int i = 0; i < A.size() - 1; i++){
			for(int j = A.size(); j > i; j--){
				if(A[j] < A[j-1]){
					swap(A[j], A[j-1]);
				}
			}
		}

		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		//cout << "Tiempo de Ejecucion para n = "<< n <<": " << time << '\n';
		cout << n << ' ' << time << '\n';
	}
	
    return 0;
}