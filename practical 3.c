// PRACTICAL 3: Username and Password Validation

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidPassword(char password[]) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (length < 8) return 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int isValidUsername(char username[]) {
    return strlen(username) >= 5;
}

int main() {
    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (isValidUsername(username) && isValidPassword(password)) {
        printf("Login successful\n");
    } else {
        printf("Validation failed\n");
    }

    return 0;
}