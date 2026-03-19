#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void keyw(char *p);

int i = 0, id = 0, kw = 0, num = 0, op = 0, sp = 0, ar = 0, count = 0, new_line = 0;
const char *keys[32] = {
    "auto","break","case","char","const","continue","default","do","double","else","enum","extern",
    "float","for","goto","if","int","long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while"
};

void keyw(char *p) {
    if (p[0] == '\0') {
        i = -1;
        return;
    }

    for (int k = 0; k < 32; k++) {
        if (strcmp(keys[k], p) == 0) {
            printf("%s is a keyword\n", p);
            kw++;
            count++;
            i = -1;
            return;
        }
    }

    if (isdigit((unsigned char)p[0])) {
        printf("%s is a number\n", p);
        num++;
        count++;
    } else {
        printf("%s is an identifier\n", p);
        id++;
        count++;
    }
    i = -1;
}

int main(void) {
    char ch;
    char str[256];
    char seps[] = " \t\n,;(){}[]#\"<>";
    char oper[] = "!%^&*-+=~|.<>/?";
    int j;
    FILE *f1;

    f1 = fopen("Laxcode.txt", "r");
    if (f1 == NULL) {
        printf("file not found\n");
        return 1;
    }

    i = 0;
    while ((ch = (char)fgetc(f1)) != EOF) {
        for (j = 0; j < (int)strlen(oper); j++) {
            if (ch == oper[j]) {
                printf("%c is an operator\n", ch);
                op++;
                count++;
                if (i > 0) {
                    str[i] = '\0';
                    keyw(str);
                    i = 0;
                }
                break;
            }
        }

        if (ch == '\n') {
            new_line++;
        }

        int isSep = 0;
        for (j = 0; j < (int)strlen(seps); j++) {
            if (ch == seps[j]) {
                isSep = 1;
                break;
            }
        }

        if (isSep) {
            if (i > 0) {
                str[i] = '\0';
                keyw(str);
                i = 0;
            }

            if (ch == '#') {
                // header include
                printf("%c", ch);
                while ((ch = (char)fgetc(f1)) != EOF && ch != '>') {
                    printf("%c", ch);
                }
                if (ch == '>') {
                    printf("%c", ch);
                    printf(" is a header file\n");
                    count++;
                }
                continue;
            }

            if (ch == '"') {
                // string literal argument
                printf("\"");
                while ((ch = (char)fgetc(f1)) != EOF && ch != '"') {
                    putchar(ch);
                }
                if (ch == '"') {
                    printf("\" is an argument\n");
                    ar++;
                    count++;
                }
                continue;
            }

            if (strchr(",;(){}[]", ch)) {
                printf("%c is a separator\n", ch);
                sp++;
                count++;
            }

            continue;
        }

        if (!isSep) {
            if (i < (int)sizeof(str) - 1) {
                str[i++] = ch;
            }
        }
    }

    if (i > 0) {
        str[i] = '\0';
        keyw(str);
    }

    fclose(f1);

    printf("\nKeywords: %d\nIdentifiers: %d\nOperators: %d\nNumbers: %d\nSeparator: %d\nArgument: %d\n", kw, id, op, num, sp, ar);
    printf("Total number of Tokens: %d\n", count);
    printf("Number Of lines: %d\n", new_line);

    return 0;
}