#include <bits/stdc++.h>
using namespace std;

/*
Entrada txt
# # # # # # # # # # # # # # # # # # # # 
# # ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ # ~ # 
# # # # # # # # # # # # # # # # ~ ~ ~ ~
# # # # # # # # # # # # # # # # ~ ~ ~ ~
# # ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ # # #
~ ~ ~ # # # # # # # # # # # # # # # # #
~ ~ # # # # # # # # # # # # # # # # # #
# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ # # # #
# # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # #
*/

class Punto{
public:
    int x{};
    int y{};
    Punto(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool band = false;

void dfs(vector<vector<string>>& mapa, int i, int j, int m, int n, string op, int x, int y) {
    if(op == "#"){
        if (i < 0 || i >= m || j < 0 || j >= n || mapa[i][j] == "~") {
            return;
        }
    }
    if(op == "~"){
        if (i < 0 || i >= m || j < 0 || j >= n || mapa[i][j] == "#") {
            return;
        }
    }

    if(x == i and y == j and mapa[i][j] == op){
        band =  true;
        return;
        
    }
        
    dfs(mapa, i - 1, j, m, n, op, x, y);
    dfs(mapa, i + 1, j, m, n, op, x, y);
    dfs(mapa, i, j - 1, m, n, op, x, y);
    dfs(mapa, i, j + 1, m, n, op, x, y);    
}

string encontrar_camino(vector<vector<string>>& mapa, Punto a, Punto b){
    string mensaje = "";
    a.x--;
    a.y--;

    b.x--;
    b.y--;

    if(mapa[a.x][a.y] == "#"){
        dfs(mapa, a.x, a.y, 10, 20, "#", b.x, b.y);
        if(band){
            band = false;
            return "Por tierra";
        }
        
    }
    if(mapa[b.x][b.y] == "~") {
        dfs(mapa, a.x, a.y, 10, 20, "~", b.x, b.y);
        if(band){
            band = false;
            return "Por agua";
        }
    }
    return "No hay camino";
}

int main(){
    
    vector<vector<string>> mapa(10, vector<string>(20));
    
    int m = 10, n = 20;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>mapa[i][j];
        }
    }

    if(encontrar_camino(mapa, Punto(2, 3), Punto(8, 16)) == "Por agua") cout << "Correcto1" << '\n';
    else cout << "incorrecto1" << '\n';
    if(encontrar_camino(mapa, Punto(8, 1), Punto(7, 3)) == "Por tierra") cout << "Correcto2" << '\n';
    else cout << "incorrecto2" << '\n';
    if(encontrar_camino(mapa, Punto(1, 1), Punto(10, 20)) == "No hay camino") cout << "Correcto3" << '\n';
    else cout << "incorrecto3" << '\n';


    return 0;
}