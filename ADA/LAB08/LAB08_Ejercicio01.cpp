#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c){
    int minimo;
    int maximo;
    if(a < b){
        minimo = a;
        maximo = b;
    }
    else{
        minimo = b;
        maximo = a;
    }

    if(c % minimo == 0){
        cout << c/minimo << '\n';
        return;
    }

    int cont = 1;
    int sum = minimo;

    while(sum < c){
        sum += minimo;
        cont++;
    }
    if(sum != c){
        sum -= minimo;
        cont--;
        do{
            
        }while(sum < c);
    }
    else if(sum == c){
        cout << cont << '\n';
        return;
    }



}

int main(){
    int a,b,c;
    while(cin>>a>>b>>c){
        solve(a,b,c);
    }


    return 0;
}