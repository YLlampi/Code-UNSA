/*
%token H O L A
%{
#define H 257
#define O 258
#define L 259
#define A 260
int yylex() {
 char carac=getchar();
 switch(carac) {
case 'H':
case 'h':
 return H;
case 'O':
case 'o':
 return O;
case 'L':
case 'l':
 return L;
case 'A':
case 'a':
 return A;
 }
 return -1;
}
int yyerror() {
 printf("La expresión de la entrada NO forma parte del lenguaje reconocido\n");
 return 0;
}
%}
%%
hola: H letra_o L A {printf("La expresión introducida es parte del lenguaje reconocido\n");}
letra_o: O |
 letra_o O ;
%%
int main() {
 yyparse();
 return 0;
} 

*/

%{
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int yylex();
int yyerror();
%}

%token H O L A

%% 

hola:    H letra_o L A  {printf("La expresión introducida es parte del lenguaje reconocido\n");};
letra_o: O | letra_o O ;  

%%

int yylex() 
{
    char carac = getchar();
    switch(carac) {
    case 'H':
    case 'h': return H;
    case 'O':
    case 'o': return O;
    case 'L':
    case 'l': return L;
    case 'A':
    case 'a': return A;
    }
    return -1;
}
int yyerror() {
    printf("La expresión de la entrada NO forma parte del lenguaje reconocido\n");
    return 0;
}


int main() {
    yyparse();
    return 0;
}
