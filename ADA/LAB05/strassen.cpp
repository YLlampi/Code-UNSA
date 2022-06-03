#include <bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int** generarMatriz(int rows, int cols){
    int** matriz = new int*[rows];

    for(int i = 0; i < rows; i++){
        matriz[i] = new int[cols];
    }
    return matriz;
}

void llenarMatriz(int **matriz, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matriz[i][j]=1+rand()%(99);
        }
    }
}

void imprimirMatriz(int **matriz, int rows, int cols){
    for(int i=0;i< rows;i++){
        for(int j=0;j< cols;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<'\n';
    }
}

int** add(int** M1, int** M2, int rows, int cols) {
    int** temp = generarMatriz(rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int** subtract(int** M1, int** M2, int rows, int cols) {
    int** temp = generarMatriz(rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}

int** square_matrix_multiply(int **A, int **B, int rows, int cols){
    int** C = generarMatriz(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            C[i][j] = 0;
            for(int k = 0; k < rows; k++){
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}


int** strassenMultiply(int** A, int** B, int rows){
    if(rows == 1){
        int** C = generarMatriz(1,1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int** C = generarMatriz(rows, rows);
    int k = rows/2;

    int** A11 = generarMatriz(k, k);
    int** A12 = generarMatriz(k, k);
    int** A21 = generarMatriz(k, k);
    int** A22 = generarMatriz(k, k);
    int** B11 = generarMatriz(k, k);
    int** B12 = generarMatriz(k, k);
    int** B21 = generarMatriz(k, k);
    int** B22 = generarMatriz(k, k);

    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k+j];
            A21[i][j] = A[k+i][j];
            A22[i][j] = A[k+i][k+j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k+j];
            B21[i][j] = B[k+i][j];
            B22[i][j] = B[k+i][k+j];
        }

    int** P1 = strassenMultiply(A11, subtract(B12, B22, k, k), k);
    int** P2 = strassenMultiply(add(A11, A12, k, k), B22, k);
    int** P3 = strassenMultiply(add(A21, A22, k, k), B11, k);
    int** P4 = strassenMultiply(A22, subtract(B21, B11, k, k), k);
    int** P5 = strassenMultiply(add(A11, A22, k, k), add(B11, B22, k, k), k);
    int** P6 = strassenMultiply(subtract(A12, A22, k, k), add(B21, B22, k, k), k);
    int** P7 = strassenMultiply(subtract(A11, A21, k, k), add(B11, B12, k, k), k);

    int** C11 = subtract(add(add(P5, P4, k, k), P6, k, k), P2, k, k);
    int** C12 = add(P1, P2, k, k);
    int** C21 = add(P3, P4, k, k);
    int** C22 = subtract(subtract(add(P5, P1, k, k), P3, k, k), P7, k, k);

    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[k+i][j] = C21[i][j];
            C[k+i][k+j] = C22[i][j];
        }
    return C;
}


int main(){
    srand(time(NULL));

    int n;
    cout << "Matrix size: "; cin>>n;
    int rows, cols;
    rows = cols = n;

    int** A = generarMatriz(rows, cols);
    int** B = generarMatriz(rows, cols);

    llenarMatriz(A, rows, cols);
    llenarMatriz(B, rows, cols);

    cout << "Matriz A" << '\n';
    imprimirMatriz(A, rows, cols);
    cout << '\n';

    cout << "Matriz B" << '\n';
    imprimirMatriz(B, rows, cols);
    cout << '\n';

    cout << "Multiplicacion normal" << '\n';
    int** C = square_matrix_multiply(A, B, rows, cols);
    imprimirMatriz(C, rows, cols);
    cout << '\n';

    cout << "Strassen Method" << '\n';
    int** D = strassenMultiply(A, B, rows);
    imprimirMatriz(D, rows, cols);

    return 0;
}
