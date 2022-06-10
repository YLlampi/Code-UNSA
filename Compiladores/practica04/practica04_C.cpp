#include <bits/stdc++.h>
using namespace std;

int preanalisis;
void parea(int);
void resto();
void term();
void error();

void exp(){
    if(preanalisis >= '0' and preanalisis <= '9'){
        term();
        resto();
    } else {
        error();
    }

}

void resto(){
    if(preanalisis == '+'){
        parea('+');
        term();
        cout << '+';
        resto();
    } else if(preanalisis == '-'){
        parea('-');
        term();
        cout << '-';
        resto();
    }
    else{ // cadena vacia
        ;
    }
}

void term(){
    if(preanalisis >= '0' and preanalisis <= '9'){
        cout << char(preanalisis);
        parea(char(preanalisis));
    } else {
        error();
    }
}

void error(){
    cout << "Error de sintaxis";
}

void parea(int t){
    if(preanalisis == t) preanalisis = getchar();
    else error();
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    preanalisis = getchar(); // lee un caracter
                             // de la entrada

    exp();


    return 0;
}