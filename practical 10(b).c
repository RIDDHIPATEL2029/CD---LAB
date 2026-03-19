/* PRACTICAL 10(b): Print all HTML tags using LEX */

%{
#include <stdio.h>
%}

%%
\<[^>]*\>    { printf("%s\n", yytext); }
.|\n         { }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}