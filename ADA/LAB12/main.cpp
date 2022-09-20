#include <bits/stdc++.h>
using namespace std;

//vector<vector<char>> table;
int n, t;
const int NUM_X = 5;
char table[NUM_X][NUM_X];

int numCeros = 0;

void ponerMinas(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            table[i][j] = '-';
        }
    }


    for(int i = 0; i < t; i++){
        int x = rand() % n;
        int y = rand() % n;
        table[x][y] = '*';
    }
}

void mostrarTablero(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
}

int contMinas(int x, int y){
    int cont = 0;
    if(x+1 < n and table[x+1][y] == '*') cont++;                // 1
    if(x+1 < n and y+1 < n and table[x+1][y+1] == '*') cont++;  // 2
    if(y+1 < n and table[x][y+1] == '*') cont++;                // 3
    if(x-1 >= 0 and y+1 < n and table[x-1][y+1] == '*') cont++; // 4
    if(x-1 >= 0 and table[x-1][y] == '*') cont++;               // 5
    if(x-1 >= 0 and y-1 >= 0 and table[x-1][y-1] == '*') cont++;// 6
    if(y-1 >= 0 and table[x][y-1] == '*') cont++;               // 7
    if(x+1 < n and y-1 >= 0 and table[x+1][y-1] == '*') cont++; // 8

    return cont;
}

void solve(int x, int y){
    if(x+1 < n and table[x+1][y] != '*' ){
        int aux = contMinas(x+1,y);
        if(aux == 0){
            table[x+1][y] = 0 + '0'; numCeros++;
            solve(x+1,y);
        }
        else {
            table[x+1][y] = aux + '0';
        }
    }
    if(x+1 < n and y+1 < n and table[x+1][y+1] != '*'){
        int aux = contMinas(x+1,y+1);
        if(aux == 0){
            table[x+1][y+1] = 0 + '0'; numCeros++;
            solve(x+1,y+1);
        }
        else {
            table[x+1][y+1] = aux + '0';
        }
    }
    if(y+1 < n and table[x][y+1] != '*'){
        int aux = contMinas(x,y+1);
        if(aux == 0){
            table[x][y+1] = 0 + '0'; numCeros++;
            solve(x,y+1);
        }
        else {
            table[x][y+1] = aux + '0';
        }
    }
    if(x-1 >= 0 and y+1 < n and table[x-1][y+1] != '*'){
        int aux = contMinas(x-1,y+1);
        if(aux == 0){
            table[x-1][y+1] = 0 + '0'; numCeros++;
            solve(x-1,y+1);
        }
        else {
            table[x-1][y+1] = aux + '0';
        }
    }
    if(x-1 >= 0 and table[x-1][y] != '*'){
        int aux = contMinas(x-1,y);
        if(aux == 0){
            table[x-1][y] = 0 + '0'; numCeros++;
            solve(x-1,y);
        }
        else {
            table[x-1][y] = aux + '0';
        }
    }
    if(x-1 >= 0 and y-1 >= 0 and table[x-1][y-1] != '*'){
        int aux = contMinas(x-1,y-1);
        if(aux == 0){
            table[x-1][y-1] = 0 + '0'; numCeros++;
            solve(x-1,y-1);
        }
        else {
            table[x-1][y-1] = aux + '0';
        }
    }
    if(y-1 >= 0 and table[x][y-1] != '*'){
        int aux = contMinas(x,y-1);
        if(aux == 0){
            table[x][y-1] = 0 + '0'; numCeros++;
            solve(x,y-1);
        }
        else {
            table[x][y-1] = aux + '0';
        }
    }
    if(x+1 < n and y-1 >= 0 and table[x+1][y-1] != '*'){
        int aux = contMinas(x+1,y-1);
        if(aux == 0){
            table[x+1][y-1] = 0 + '0'; numCeros++;
            solve(x+1,y-1);
        }
        else {
            table[x+1][y-1] = aux + '0';
        }
    }
}

int main(){
    srand(time(NULL));
    
    //cout << "Valor de n: "; cin>>n;
    //cout << "Valor de t: "; cin>>t;
    n = NUM_X;
    t = 15;
    //vector<vector<char>> temp(n, vector<char>(n,'-'));
    //table = temp;

    ponerMinas();

    int x,y;
    do{
        mostrarTablero();
        cout << "Valor x[0," << n-1 <<"]: ";cin>>x;
        cout << "Valor y[0," << n-1 <<"]: ";cin>>y;
        if(table[x][y] == '*'){
            cout << "Juego Terminado [LOSE]" << '\n';
            mostrarTablero();
            break;
        }
        else {
            table[x][y] = contMinas(x,y) + '0';  numCeros++;
            solve(x,y);
        }
    }while(true);

    return 0;
}