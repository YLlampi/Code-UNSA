#include <bits/stdc++.h>
using namespace std;

#define MAXtamTablero 25
#define MAXnumMinas 99
#define MOVESIZE 526 // (25 * 25 - 99)

int tamTablero;
int numMinas;

bool isValid(int row, int col)
{
    return (row >= 0) && (row < tamTablero) &&
           (col >= 0) && (col < tamTablero);
}

bool isMine(int row, int col, char board[][MAXtamTablero])
{
    if (board[row][col] == '*')
        return (true);
    else
        return (false);
}

void makeMove(int *x, int *y)
{
    printf("Ingrese posicion, (x, y) -> ");
    
    scanf("%d %d", x, y);
    printf("\033[2J\033[1;1H");
    (*x)--;
    (*y)--;
    return;
}

void printBoard(char myBoard[][MAXtamTablero])
{
    int i, j;

    for (i = 0; i < tamTablero; i++)
    {
        for (j = 0; j < tamTablero; j++)
            printf("%c ", myBoard[i][j]);
        printf("\n");
    }
    return;
}

int countAdjacentMines(int row, int col, int mines[][2],
                       char realBoard[][MAXtamTablero])
{

    int i;
    int count = 0;

    if (isValid(row - 1, col) == true)
    {
        if (isMine(row - 1, col, realBoard) == true)
            count++;
    }

    if (isValid(row + 1, col) == true)
    {
        if (isMine(row + 1, col, realBoard) == true)
            count++;
    }

    if (isValid(row, col + 1) == true)
    {
        if (isMine(row, col + 1, realBoard) == true)
            count++;
    }

    if (isValid(row, col - 1) == true)
    {
        if (isMine(row, col - 1, realBoard) == true)
            count++;
    }

    if (isValid(row - 1, col + 1) == true)
    {
        if (isMine(row - 1, col + 1, realBoard) == true)
            count++;
    }

    if (isValid(row - 1, col - 1) == true)
    {
        if (isMine(row - 1, col - 1, realBoard) == true)
            count++;
    }

    if (isValid(row + 1, col + 1) == true)
    {
        if (isMine(row + 1, col + 1, realBoard) == true)
            count++;
    }

    if (isValid(row + 1, col - 1) == true)
    {
        if (isMine(row + 1, col - 1, realBoard) == true)
            count++;
    }

    return (count);
}

bool jugarBuscaminasUtil(char myBoard[][MAXtamTablero], char realBoard[][MAXtamTablero],
                         int mines[][2], int row, int col, int *movesLeft)
{
    if (myBoard[row][col] != '-')
        return (false);

    int i, j;
    if (realBoard[row][col] == '*')
    {
        myBoard[row][col] = '*';

        for (i = 0; i < numMinas; i++)
            myBoard[mines[i][0]][mines[i][1]] = '*';

        printBoard(myBoard);
        printf("\nPerdiste!\n");
        return (true);
    }

    else
    {
        int count = countAdjacentMines(row, col, mines, realBoard);
        (*movesLeft)--;

        myBoard[row][col] = count + '0';

        if (!count)
        {
            if (isValid(row - 1, col) == true)
            {
                if (isMine(row - 1, col, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row - 1, col, movesLeft);
            }

            if (isValid(row + 1, col) == true)
            {
                if (isMine(row + 1, col, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row + 1, col, movesLeft);
            }

            if (isValid(row, col + 1) == true)
            {
                if (isMine(row, col + 1, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row, col + 1, movesLeft);
            }

            if (isValid(row, col - 1) == true)
            {
                if (isMine(row, col - 1, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row, col - 1, movesLeft);
            }

            if (isValid(row - 1, col + 1) == true)
            {
                if (isMine(row - 1, col + 1, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row - 1, col + 1, movesLeft);
            }

            if (isValid(row - 1, col - 1) == true)
            {
                if (isMine(row - 1, col - 1, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row - 1, col - 1, movesLeft);
            }

            if (isValid(row + 1, col + 1) == true)
            {
                if (isMine(row + 1, col + 1, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
            }

            if (isValid(row + 1, col - 1) == true)
            {
                if (isMine(row + 1, col - 1, realBoard) == false)
                    jugarBuscaminasUtil(myBoard, realBoard, mines, row + 1, col - 1, movesLeft);
            }
        }

        return (false);
    }
}

void placeMines(int mines[][2], char realBoard[][MAXtamTablero])
{
    bool mark[MAXtamTablero * MAXtamTablero];

    memset(mark, false, sizeof(mark));

    for (int i = 0; i < numMinas;)
    {
        int random = rand() % (tamTablero * tamTablero);
        int x = random / tamTablero;
        int y = random % tamTablero;

        if (mark[random] == false)
        {
            mines[i][0] = x;
            mines[i][1] = y;

            realBoard[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }

    return;
}

void initialise(char realBoard[][MAXtamTablero], char myBoard[][MAXtamTablero])
{
    srand(time(NULL));

    for (int i = 0; i < tamTablero; i++)
    {
        for (int j = 0; j < tamTablero; j++)
        {
            myBoard[i][j] = realBoard[i][j] = '-';
        }
    }

    return;
}

void cheatMinesweeper(char realBoard[][MAXtamTablero])
{
    printf("The mines locations are-\n");
    printBoard(realBoard);
    return;
}

void replaceMine(int row, int col, char board[][MAXtamTablero])
{
    for (int i = 0; i < tamTablero; i++)
    {
        for (int j = 0; j < tamTablero; j++)
        {
            if (board[i][j] != '*')
            {
                board[i][j] = '*';
                board[row][col] = '-';
                return;
            }
        }
    }
    return;
}

void jugarBuscaminas()
{
    bool gameOver = false;

    char realBoard[MAXtamTablero][MAXtamTablero], myBoard[MAXtamTablero][MAXtamTablero];

    int movesLeft = tamTablero * tamTablero - numMinas, x, y;
    int mines[MAXnumMinas][2];

    initialise(realBoard, myBoard);

    placeMines(mines, realBoard);

    int currentMoveIndex = 0;
    while (gameOver == false)
    {
        printf("Estado actual del tablero: \n");
        printBoard(myBoard);
        makeMove(&x, &y);

        if (currentMoveIndex == 0)
        {
            if (isMine(x, y, realBoard) == true)
                replaceMine(x, y, realBoard);
        }

        currentMoveIndex++;

        gameOver = jugarBuscaminasUtil(myBoard, realBoard, mines, x, y, &movesLeft);

        if ((gameOver == false) && (movesLeft == 0))
        {
            printf("\nGanaste..!\n");
            gameOver = true;
        }
    }
    return;
}

int main()
{

    tamTablero = 16;
    numMinas = 40;

    jugarBuscaminas();

    return (0);
}
