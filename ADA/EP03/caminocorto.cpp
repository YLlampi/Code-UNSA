#include <bits/stdc++.h>
using namespace std;


/*
Entrada txt
6 10
1 6 3
2 1 5
2 4 4
2 5 7
3 2 6
4 3 -4
5 4 1
5 6 12
6 2 -1
6 4 2

*/

int Prim (vector<vector<int>>& G, vector<vector<int>>& W, int n){
    vector <bool> vis(n, false); 
    priority_queue <pair<int,int>> Q; 
    Q.push({-0,0}); 
    int answer = 0; 

    while (not Q.empty()){
        pair<int,int> arc = Q.top();
        Q.pop(); 

        int v = arc.second; 
        int p = -arc.first; 

        if (not vis[v]){ 
            vis[v] = true;
            answer += p;

            for (int i = 0; i < G[v].size(); ++i){ 
                int u = G[v][i];
                int w = W[v][i];

                Q.push({-w, u}); 
            }
        }   
    }

    return answer;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector <vector <int> > G(n);
    vector <vector <int> > W(n);

    for (int i = 0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;

        G[x].push_back(y);
        W[x].push_back(w);
    }


    for(int i = 0; i < n; i++){
        cout << "Del vertice " << i+1 << "Hacia los demas, PESO = " << Prim(G, W, i) << endl;
    }

    return 0;
}