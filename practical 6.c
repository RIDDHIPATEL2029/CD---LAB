// PRACTICAL 6: Operator Precedence Parsing

#include <stdio.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int get_precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    if (c == 'i') return 4;
    return 0;
}

int main() {
    char input[20];
    int i = 0;

    printf("Enter input (end with $): ");
    scanf("%s", input);

    push('$');

    while (i < strlen(input)) {
        char stack_top = stack[top];
        char current_input = input[i];

        if (stack_top == '$' && current_input == '$') {
            printf("Accepted\n");
            break;
        }

        if (get_precedence(stack_top) <= get_precedence(current_input)) {
            push(current_input);
            i++;
        } else {
            pop();
        }

        if (top < 0) {
            printf("Error\n");
            break;
        }
    }

    return 0;
}