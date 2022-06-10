#include <bits/stdc++.h>
using namespace std;

int preanalisis;
void parea(int);
void A();
void B();
void error();

void S(){
    if (preanalisis == 'x'){
        parea('x');
        S();
    }
    else if (preanalisis == 'a'){
        A();
        B();
        parea('c');
    }
    else
        error();
}

void A(){
    if (preanalisis == 'a')
        parea('a');
    else
        error();
}

void B(){
    if (preanalisis == 'b')
        parea('b');
    else
        error();
}

void error(){
    printf("Error de sintaxis");
}

void parea(int t){
    if (preanalisis == t)
        preanalisis = getchar();
    else
        error();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    preanalisis = getchar(); // lee un carácter
    // de la entrada
    S();

    return 0;
}