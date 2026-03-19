/* PRACTICAL 10(c): Add line numbers to file using LEX */

%{
#include <stdio.h>
int line = 1;
%}

%%
^      { printf("%d: ", line++); }
.*\n   { printf("%s", yytext); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}