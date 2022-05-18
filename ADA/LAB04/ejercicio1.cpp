#include <bits/stdc++.h>
using namespace std;


int maximo(vector<int>& arr, int inicio, int final){
    if(inicio == final) return arr[inicio];

    int medio = (inicio + final) / 2;

    int max_izq = maximo(arr, inicio, medio);
    int max_der = maximo(arr, medio + 1, final);

    if(max_izq > max_der) return max_izq;
    else return max_der;
}

int main(){
    srand(time(NULL));
    int n; cin>>n;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        arr[i] = 1 + rand() % 20;
    }

    for(auto i : arr){
        cout << i << ' ';
    }
    cout << '\n';
    cout << maximo(arr, 0, arr.size() - 1) << '\n';

    return 0;
}