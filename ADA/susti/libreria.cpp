#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> paginas(n);
    vector<int> precios(n);

    for(int i = 0; i < n; i++){
        cin>>precios[i];
    }


    for(int i = 0; i < n; i++){
        cin>>paginas[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];

            if(j >= precios[i-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-precios[i-1]] + paginas[i-1]);
            }
        }
    }

    cout << dp[n][x] << '\n';

    return 0;
}