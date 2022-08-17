#include <bits/stdc++.h>
using namespace std;

int solve2(int i, int j, vector<vector<int>>& matriz, vector<vector<int>>& dp){
    if(j<0 or j>=matriz[0].size()) return 1e8;

    if(i==0) return dp[0][j] = matriz[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = INT_MAX;

    for(int k=0;k<matriz[0].size();k++){
        if(k==j) continue;
        ans = min(ans, matriz[i][j] + solve2(i-1, k, matriz, dp));
    }
    
    return dp[i][j] = ans;
    
}

int solve(vector<vector<int>>& arr) {
    
    int mini = INT_MAX;
    int n = arr.size();
    
    vector<vector<int>> dp(n, vector<int>(n,-1));
    
    for(int j=0;j<n;j++){
        
        mini = min(mini, solve2(n-1, j, arr, dp));
        
    }
    return mini;
}


int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};

    cout << solve(arr) << '\n';
}