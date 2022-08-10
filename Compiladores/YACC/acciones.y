%{
 #include <stdio.h>
 int u,v;
%}
%%
 X: A { printf("valor de A=$1 %c , $$=%c\n", $1,$$); } ;
 A: B
 C { u=$1; /* valor de B */
 v=$2; /* valor de C */
 $$='3'; /* asigna valor a tercer componente $3 */
 }
 D /* su valor es $4 */
 { printf("u=%c v=%c $3=%c $4=%c\n",u,v,$3,$4) ; } ;
 B: {$$='b'; } ;
 C: {$$='c'; };
 D: {$$='d'; };
%%
main()
{ yyparse();
}
yyerror(char *m)
{ printf("%s\n",m); }
yylex()
{ int c;
 while (1)
 { c=getchar();
 if (c==EOF) return c;
 }
}