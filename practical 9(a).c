/* PRACTICAL 9(a): Count characters, words, and lines using LEX */

%{
#include <stdio.h>
int chars = 0, words = 0, lines = 0;
%}

%%
\n      { lines++; chars++; }
[ \t]+  { chars += yyleng; }
[^ \t\n]+ { words++; chars += yyleng; }
%%

int main() {
    yylex();
    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}

int yywrap() {
    return 1;
}