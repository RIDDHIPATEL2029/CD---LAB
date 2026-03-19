// PRACTICAL 7: LALR Parsing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100

typedef struct {
    char action;
    int id;
} TableEntry;

TableEntry actionTable[4][3] = {
    {{'s', 2}, {' ', 0}, {' ', 0}},
    {{' ', 0}, {'s', 3}, {'a', 0}},
    {{'r', 2}, {'r', 2}, {'r', 2}},
    {{'s', 2}, {' ', 0}, {' ', 0}}
};

int stack[MAX_STACK];
int top = -1;

void push(int state) {
    stack[++top] = state;
}

int pop() {
    return stack[top--];
}

int main() {
    char input[] = "id+id$";
    int ip = 0;

    push(0);

    while (1) {
        int currentState = stack[top];
        char currentSymbol = input[ip];

        int col = (currentSymbol == 'i') ? 0 :
                  (currentSymbol == '+') ? 1 : 2;

        TableEntry entry = actionTable[currentState][col];

        if (entry.action == 's') {
            push(entry.id);
            ip += (currentSymbol == 'i') ? 2 : 1;
        }
        else if (entry.action == 'r') {
            pop();
        }
        else if (entry.action == 'a') {
            printf("Accepted\n");
            break;
        }
        else {
            printf("Error\n");
            break;
        }
    }

    return 0;
}