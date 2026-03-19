/* PRACTICAL 10: Combined LEX Program */

%{
#include <stdio.h>
int line = 1;
%}

%%
[0-9]+            { printf("Number: %s\n", yytext); }
\<[^>]*\>         { printf("HTML Tag: %s\n", yytext); }
^                 { printf("%d: ", line++); }
.*\n              { printf("%s", yytext); }
.                 { }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}