#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    
    vector<vector<int>> graph(n+1);

    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        cout << i << "-> ";
        for(auto j : graph[i]){
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}