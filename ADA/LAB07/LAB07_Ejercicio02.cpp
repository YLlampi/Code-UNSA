#include <bits/stdc++.h>
using namespace std;
 
/*
*
* Complejidad Algoritmica: O(n*m)
* n: cantidad de kilos distintos de arroz
* m: peso objetivo
*
*/

int main(){
    vector<int> arr;
 
    int n; cin>>n;
    
    int a;
    while(cin>>a){
        arr.push_back(a);
    }

    int dp[n+1];
    dp[0] = 0;
 
    for (int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
        int solve = INT_MAX;
 
        for (int j: arr){
            if (i - j >= 0) {
                solve = dp[i - j];
            }
            if (solve != INT_MAX) {
                dp[i] = min(dp[i], solve + 1);
            }
        }
    }
 
    if (dp[n] != INT_MAX) cout << dp[n] << '\n';
 
    return 0;
}