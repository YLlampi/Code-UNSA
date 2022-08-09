#include <bits/stdc++.h>
using namespace std;

class Game{
    private:
        int n; // Tamaño de la matriz
        vector <vector <char>> table; // tablero

        vector <bool> visited;
        vector <vector <int>> graph;

    public:
        Game(int n) : n{n}{
            vector <vector <char>> tableTemp(n, vector<char>(n, 45)); // 45 ASCII => -
            this->table.assign(tableTemp.begin(), tableTemp.end());
            generarTablero();
        }

        void mainController(){
            int a,b;
            bool band = true;
            do{
                cout << "Posicion [X][Y]: "; cin>>a>>b;
                a--;
                b--;
                if(this->table[a][b] != 42){
                    
                }
                else {
                    cout << "Game Over" << '\n';
                    band = false;
                }
            }while(band);

        }

        void generarTablero() {
            for(int i = 0; i < n; i++){
                int numAleatorioI = 0 + rand() % (n);
                int numAleatorioJ = 0 + rand() % (n);
                this->table[numAleatorioI][numAleatorioJ] = 42; // 42 ASCII => * | Minas
            }
        }

        // trabajar con tablero, matriz

        void bfs(int v){
            queue <int> Q;
            Q.push(v);

            while (not Q.empty()){ //mientras nuestra lista tenga nodos
                int u = Q.front(); //seleccionamos el primer nodo de la lista
                Q.pop(); //y lo eliminamos

                if (not visited[u]){ //si no lo hemos visitado
                    visited[u] = true;

                    for (int i = 0; i < graph[u].size(); ++i){
                        int w = graph[u][i];

                        Q.push(w); //ponemos a sus vecinos en la lista
                    }
                }
            }
        }

        void generateScript(){
            cout << '\n';
            cout << '+';
            for(int i = 0; i < n*2 -1; i++){
                cout << '-';
            }
            cout << '+';
            cout << '\n';
        }

        void printTable() {
            generateScript();
            for(int i = 0; i < n; i++){
                cout << '|';
                for(int j = 0; j < n; j++){
                    cout << this->table[i][j] << '|';
                }
                generateScript();
            }
        }

};

int main(){
    srand(time(nullptr));

    int n;
    cout << "Size of Table: "; cin>>n;

    Game myGame(n);

    myGame.printTable();

    //myGame.mainController();

    return 0;
}