#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr;
    int a;
    while(cin>>a) arr.push_back(a);

    int dp[n+1];
    dp[0] = 0;
    
    for(int i = 1; i < n+1;i++){
        dp[i] = n + 1;
        for(auto j : arr){
            if(i - j >= 0){
                dp[i] = min(dp[i], dp[i-j] + 1);
            }
            
        }
    }

    cout << dp[n] << '\n';


    return 0;
}