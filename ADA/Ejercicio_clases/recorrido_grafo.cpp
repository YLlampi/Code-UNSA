#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vvpii vector<vector<pair<int,int>>>
#define vli vector<list<int>>


void print(vvi& matriz){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matriz[i][j] << '\t';
        }
        cout << '\n';
    }
}

void solve2(int x, int y, int matriz[5][5]){
    queue<pair<int,int>> cola;
    cola.push(make_pair(x,y));
    while(not cola.empty()){
        pair<int,int> temp = cola.front();
        cola.pop();
        int i = temp.first;
        int j = temp.second;
        
        
        if(matriz[i-1][j] == -1 and i-1 >= 0){
            matriz[i-1][j] = matriz[i][j] + 1;
            cola.push(make_pair(i-1,j));
        }
        if(matriz[i+1][j] == -1 and i+1 < 5){
            matriz[i+1][j] = matriz[i][j] + 1;
            cola.push(make_pair(i+1,j));
        }
        if(matriz[i][j-1] == -1 and j-1 >= 0){
            matriz[i][j-1] = matriz[i][j] + 1;
            cola.push(make_pair(i,j-1));
        }
        if(matriz[i][j+1] == -1 and j+1 < 5){
            matriz[i][j+1] = matriz[i][j] + 1;
            cola.push(make_pair(i,j+1));
        }
        //print(matriz);
    }
}


void solve(int ui, int uo, vvi& matriz){
    queue<pii> Q;
    Q.push(pii(ui,uo));
    while(not Q.empty()){
        pii df = Q.front();
        int i = df.first;
        int j = df.second;
        Q.pop();

        if(matriz[i+1][j] == -1 and (i+1 < matriz.size())){
            matriz[i+1][j] = matriz[i][j]+1;
            Q.push(pii(i+1,j));
        }
        if(matriz[i][j+1] == -1 and (j+1 < matriz.size())){
            matriz[i][j+1] = matriz[i][j]+1;
            Q.push(pii(i,j+1));
        }
        if(matriz[i-1][j] == -1 and (i-1 >= 0)){
            matriz[i-1][j] = matriz[i][j]+1;
            Q.push(pii(i-1,j));
        }
        if(matriz[i][j-1] == -1 and (j-1 >= 0)){
            matriz[i][j-1] = matriz[i][j]+1;
            Q.push(pii(i,j-1));
        }
        
    }
}

int main(){

    /*
    int matriz[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriz[i][j] = -1;
        }
    }
    */

    vvi matriz(5, vi(5, -1));

    int i = 1;
    int j = 2;
    matriz[i][j] = 0;
    //int n, m; cin>>n>>m;
    //vvi graph(n+1);

    print(matriz);

    solve(i,j, matriz);
    
    cout << "Solution" << '\n';
    print(matriz);

    //vvi graph(n+1, vi(n+1, 0));
    
    /*
    for(int i{0}; i < m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    

    /*
    for(int i = 0; i < m; i++){
        int a,b; cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;

    }
    */



   /*
    print(graph);

    cout << '\n';
    
    bfs(graph, 3);
    */
    return 0;
}

