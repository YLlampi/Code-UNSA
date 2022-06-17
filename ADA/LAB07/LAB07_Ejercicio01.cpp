#include <bits/stdc++.h>
using namespace std;

/*
*
* Complejidad Algoritmica: O(2^n)
*
*/

int solve(vector<int>& arr, int n){
    if (n == 0) return 0;
 
    if (n < 0) return INT_MAX;
 
    int cant = INT_MAX;
 
    for (int i: arr){
        int res = solve(arr, n - i);
 
        if (res != INT_MAX) {
            cant = min(cant, res + 1);
        }
    }
 
    return cant;
}
 
int main(){
    vector<int> arr;
 
    int n; cin>>n;
    
    int a;
    while(cin>>a){
        arr.push_back(a);
    }
 
    int cant = solve(arr, n);
    if (cant != INT_MAX) cout << cant << '\n';
 
    return 0;
}