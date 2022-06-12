#include <iostream>
#include <climits>
#include <chrono>

typedef int (*pf)(int[], int);

//Normal
int cut_rod(int p[], int n) {
	if (n < 1) {
		return 0;
	}

	int q = INT_MIN;
	for (int i = 0; i < n; i++) {
		q = std::max(q, p[i] + cut_rod(p, n - i - 1));
	}
	return q;
}

// TOP DOWN version
int memoized_cut_rod_aux(int p[], int n, int r[]){
    if(r[n] >= 0){
        return r[n];
    }
    int q = INT_MIN;
    if( n < 1){
        q = 0;
    }else{
        for (int i = 0; i < n; i++) {
		    q = std::max(q, p[i] + memoized_cut_rod_aux(p, n - i - 1, r));
	    }
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(int p[], int n){
    int r[n+1];
    for(int i=0; i<n+1; i++){
        r[i] = INT_MIN;
    }
    return memoized_cut_rod_aux(p,n,r);
}

//BOTTOM-UP
int Botton_up_cut_rod(int p[], int n){
    int r[n+1];
    r[0] = 0;
    for(int j=1; j<n+1; j++){
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
		    q = std::max(q, p[i-1] + r[j-i]);
	    }
	    r[j] = q;
    }
    return r[n];
}

//Elapse time
void elapse(pf func, int p[], int n){
    int resp = -1;
    auto start = std::chrono::high_resolution_clock::now();
    resp = func( p, n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    std::cout << resp << " for " << duration.count() << " ms" << std::endl;
}

int main() {
	// Example
	// int p[] = { 1,5,8,9,10,17,17,20,24,30 };
	// int n = 10;
	// std::cout << sizeof(p)/sizeof(*p) << std::endl;
    
    //Large
    int n = 20;
    int p[n];
    p[0] = 1;
    for(int i=1; i<n ; i++){
        p[i] = p[i-1] + (i%2)+1;
    }

    pf fun1[] = {cut_rod, memoized_cut_rod, Botton_up_cut_rod};
    for(int i=0;i<3;i++){
        elapse(fun1[i], p, n);
    }
	return 0;
}