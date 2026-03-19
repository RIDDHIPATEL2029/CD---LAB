// PRACTICAL 5: Recursive Descent Parsing

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0, error = 0;

void E();
void Edash();
void T();
void Tdash();
void F();

void E() {
    T();
    Edash();
}

void Edash() {
    if (input[i] == '+') {
        i++;
        T();
        Edash();
    }
}

void T() {
    F();
    Tdash();
}

void Tdash() {
    if (input[i] == '*') {
        i++;
        F();
        Tdash();
    }
}

void F() {
    if (isalnum(input[i])) {
        i++;
    }
    else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1;
        }
    }
    else {
        error = 1;
    }
}

int main() {
    printf("Enter expression: ");
    scanf("%s", input);

    E();

    if (strlen(input) == i && error == 0)
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}