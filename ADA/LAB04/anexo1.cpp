#include <bits/stdc++.h>
using namespace std;

/*

4 2
0 1 2 3 4 5 6 7 [8 9 10 11 12 13 14 15]

*/


void solve(int d, int a){
    long long tam = pow(2,d);
    vector<bool> tree(tam, false);

    int limit = pow(2,d-1);
    int index;

    while(a--){
        int i = 1;
        while(limit > i){
            if(tree[i] == 0){
                tree[i] = 1;
                i = i*2;
            }
            else{
                tree[i] = 0;
                i = i*2 + 1;
            }
            index = i;
        }
    }
    cout << index << '\n';
}


int main(){
    ios::sync_with_stdio(false);

    int n; cin>>n;
    int d, i; 
    while(n--){
        cin>>d>>i;
        solve(d,i);
    }
    int as;cin>>as;
    
    return 0;
}