/**************************************************/
/* Ejemplo de YACC con todas las partes completas */
/* */
/* S -> x S ¦ A B c */
/* A -> a */
/* B -> b */
/**************************************************/
%{
#include <stdio.h>
#include <ctype.h>
#include <math.h>
%}
%token ID /* no utilizado */
%%
 S: 'x' S;
 S: A B 'c';
 A: 'a' ;
 B: 'b' ;
%%
yylex() /* analizador léxico */
{
 int c;
 do c=getchar(); while (c==' '|| c=='\t');

 if (c=='\n') return EOF; /* fin de archivo para yylex */
 if (isalpha(c))
 return c;
 yyerror("caracter ilegal");
}
