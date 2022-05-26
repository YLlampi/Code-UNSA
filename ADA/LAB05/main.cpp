#include <bits/stdc++.h>
using namespace std;

int** generarMatriz(int rows, int cols){
    int** matriz = new int*[rows];

    for(int i = 0; i < rows; i++){
        matriz[i] = new int[cols];
    }
    return matriz;
}

void llenarMatriz(int **matriz, int rows, int cols){
    srand(time(NULL));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matriz[i][j]=rand()%99+1;
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
            for(int k = 1; k < rows; k++){
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

int** strassen(int** A, int** B, int rows, int cols){
    if(rows == 1){
        int** C = generarMatriz(rows, cols);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int** C = generarMatriz(rows, cols);
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
}

int main() {
    int n;
    cout << "Matrix size: "; cin>>n;
    int rows, cols;
    rows = cols = n;

    int** A = generarMatriz(rows, cols);
    int** B = generarMatriz(rows, cols);

    llenarMatriz(A, rows, cols);
    llenarMatriz(B, rows, cols);

    imprimirMatriz(A, rows, cols);
    cout << '\n';
    imprimirMatriz(B, rows, cols);
    cout << '\n';

    int** C = square_matrix_multiply(A, B, rows, cols);
    imprimirMatriz(C, rows, cols);

    return 0;
}
