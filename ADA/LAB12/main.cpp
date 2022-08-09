#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vvpii vector<vector<pair<int,int>>>
#define vli vector<list<int>>

void print(vvi& graph) {

    for(int i = 1; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs(vvi& graph, int v){
    vector<bool> visited(graph.size()+1, false);
    queue <int> Q;
    Q.push(v);

    while (not Q.empty()){ //mientras nuestra lista tenga nodos
        int u = Q.front(); //seleccionamos el primer nodo de la lista
        Q.pop(); //y lo eliminamos

        if (not visited[u]){ //si no lo hemos visitado
            visited[u] = true;
            cout << u << ' ';
            for (int i = 0; i < graph[u].size(); ++i){
                int w = graph[u][i];

                Q.push(w); //ponemos a sus vecinos en la lista
            }
        }
    }
}

int main(){
    int n, m; cin>>n>>m;
    vvi graph(n+1);
    
    for(int i{0}; i < m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    print(graph);

    cout << '\n';
    
    bfs(graph, 3);




    return 0;
}