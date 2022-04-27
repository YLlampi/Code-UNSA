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
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		//cout << "Tiempo de Ejecucion para n = "<< n <<": " << time << '\n';
		cout << n << ' ' << time << '\n';
	}
	
    return 0;
}