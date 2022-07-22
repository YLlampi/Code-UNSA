#include <bits/stdc++.h>
using namespace std;

/*
*
* Tiempo de ejecucion: O(n)
*
*/

void solve(vector<long long>& arr){
    int cont = 0;
    long long suma = arr[0];
    for(int j = 0; j < arr.size(); j++){
        if(suma <= arr[j]){
            cont++;
            suma += arr[j];
        }
    }
    cout << cont << '\n';
}

int main(){
    int a; cin>>a;
    while(a--){
        int b; cin>>b;
        vector<long long> arr(b,0);
        for(int i = 0; i < b; i++){
            cin>>arr[i];
        }
        solve(arr);
    }

    return 0;
}