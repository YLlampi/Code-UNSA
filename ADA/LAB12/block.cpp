/*
#include <bits/stdc++.h>
using namespace std;


class Game{
private:
    int tamTablero;
    int numMinas;
    bool gameOver;

    vector<vector<char>> realBoard;
    vector<vector<char>> myBoard;

    int movesLeft;

    int x;
    int y;

    vector<vector<int>> mines;
public:
    Game(int tamTablero) : tamTablero{tamTablero}{
        this->numMinas = tamTablero*(tamTablero/3);

        realBoard.resize(this->tamTablero);
        myBoard.resize(this->tamTablero);
        for(int i = 0; i < this->tamTablero; ++i){
            this->realBoard[i].resize(this->tamTablero);
            this->myBoard[i].resize(this->tamTablero);
        }
        this->movesLeft = this->tamTablero*this->tamTablero - this->numMinas;

        mines.resize(this->numMinas);
        for(int i = 0; i < this->mines.size(); ++i){
            this->mines[i].resize(2);
        }
    }

    void inicializar(){
        for(int i = 0; i < this->tamTablero; ++i){
            for(int j = 0; j < this->tamTablero; ++j){
                this->myBoard[i][j] = this->realBoard[i][j] = 45; // 45 ASCII => - 
            }
        }
    }
    
    void colocarMinas(){
        vector<bool> mark((this->tamTablero+1)*(this->tamTablero+1), false);
        
        for(int i = 0; i < this->numMinas; ){
            int random = rand() % (this->tamTablero*this->tamTablero);
            int x = random / this->tamTablero;
            int y = random % this->tamTablero;

            if(!mark[random]){
                this->mines[i][0] = x;
                this->mines[i][1] = y;

                this->realBoard[this->mines[i][0]][this->mines[i][1]] = 42; // 42 ASCII => * | Minas
                mark[random] = true;
                i++;
            }
        }
    }

    void printTablero(){
        for(int i = 0; i < this->tamTablero; ++i){
            for(int j = 0; j < this->tamTablero; ++j){
                cout << this->myBoard[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void makeMove(){
        cout << "Ingresa posicion (x y): "; cin>>this->x>>this->y;
    }

    bool isMina(){
        if(this->realBoard[this->x][this->y] == 42) return true;
        else return false;
    }

    bool isMina(int row, int col){
        if(this->realBoard[row][col] == 42) return true;
        else return false;
    }

    void reemplazarMina(){
        for(int i = 0; i < this->tamTablero; ++i){
            for(int j = 0; j < this->tamTablero; ++j){
                if(this->realBoard[i][j] != 42){
                    this->realBoard[i][j] = 42;
                    this->realBoard[this->x][this->y] = 45;
                }
            }
        }
    }

    bool isValid(int row, int col){
        return (row >= 0) and (row < this->tamTablero) and
            (col >= 0) and (col < this->tamTablero);
    }

    int contMinasAdjacentes(){
        //int i;
        int count = 0;

        if(isValid(this->x-1, this->y)){
            if(isMina(this->x-1, this->y)) count++;
        }

        if(isValid(this->x+1, this->y)){
            if(isMina(this->x+1, this->y)) count++;
        }

        if(isValid(this->x, this->y+1)){
            if(isMina(this->x, this->y+1)) count++;
        }

        if(isValid(this->x, this->y-1)){
            if(isMina(this->x, this->y-1)) count++;
        }

        if(isValid(this->x-1, this->y+1)){
            if(isMina(this->x-1, this->y+1)) count++;
        }

        if(isValid(this->x-1, this->y-1)){
            if(isMina(this->x-1, this->y-1)) count++;
        }

        if(isValid(this->x+1, this->y+1)){
            if(isMina(this->x+1, this->y+1)) count++;
        }

        if(isValid(this->x+1, this->y-1)){
            if(isMina(this->x+1, this->y-1)) count++;
        }

        return count;
    }

    //myBoard, realBoard, mines, x, y, &movesLeft
    bool jugarBuscaminas(){
        if(this->myBoard[this->x][this->y] != 45) return false;

        if(this->realBoard[this->x][this->y] == 42){
            this->myBoard[this->x][this->y] = 42;
            for(int i = 0; i < this->numMinas; ++i){
                this->myBoard[this->mines[i][0]][this->mines[i][1]] = 42;
            }

            printTablero();
            cout << "PERDISTE" << '\n';
            return true;
        }
        else {
            int count = contMinasAdjacentes();
            this->movesLeft--;

            this->myBoard[this->x][this->y] = count + '0';

            if(!count){
                if (isValid (this->x-1, this->y) == true){
                    if(isMina(this->x-1, this->y) == false)
                    jugarBuscaminas(myBoard, realBoard, mines, row-1, col, movesLeft);
                }
            }
        }
    }

    void playGame(){
        this->gameOver = false;

        inicializar();

        colocarMinas();

        int currentMoveIndex = 0;
        while(!this->gameOver){
            cout << "Tablero Actual" << '\n';
            printTablero();
            makeMove();

            if(currentMoveIndex == 0){
                if(isMina()){
                    reemplazarMina();
                }
            }

            currentMoveIndex++;

            this->gameOver = jugarBuscaminas();
        }
    }
};

int main(){
    srand(time (NULL));
    int tamTablero;
    cout << "Tamaño del Tablero nxn: "; cin>>tamTablero;
    Game myGame(tamTablero);


    myGame.playGame();


    return 0;
}
*/