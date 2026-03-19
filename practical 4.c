// PRACTICAL 4: Predictive Parsing LL(1)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

int main() {
    char table[2][3][5] = {
        {"iA", "err", "err"},
        {"err", "+iA", "e"}
    };

    char input[20];
    printf("Enter the string (end with $): ");
    scanf("%s", input);

    push('$');
    push('E');

    int i = 0;

    while (stack[top] != '$') {
        char current_top = stack[top];
        char current_input = input[i];

        int row = (current_top == 'E') ? 0 : (current_top == 'A' ? 1 : -1);
        int col = (current_input == 'i') ? 0 :
                  (current_input == '+') ? 1 :
                  (current_input == '$') ? 2 : -1;

        if (current_top == current_input) {
            pop();
            i++;
        }
        else if (row != -1 && col != -1 && strcmp(table[row][col], "err") != 0) {
            pop();
            char *prod = table[row][col];

            if (prod[0] != 'e') {
                for (int j = strlen(prod) - 1; j >= 0; j--) {
                    push(prod[j]);
                }
            }
        }
        else {
            printf("String Rejected\n");
            return 1;
        }
    }

    if (stack[top] == '$' && input[i] == '$')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}