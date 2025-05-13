#include "auth.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ATTEMPTS 3
#define PASSWORD "admin123"

// Display the login window
void login_window() {
    printf("====================================\n");
    printf("      STUDENT MANAGEMENT SYSTEM     \n");
    printf("====================================\n");
}

// Handle password input and validation
void password_input() {
    char input[32];
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        scanf("%31s", input);
        if (strcmp(input, PASSWORD) == 0) {
            printf("Access granted.\n");
            return;
        } else {
            printf("Incorrect password. ");
            attempts++;
            if (attempts < MAX_ATTEMPTS)
                printf("Try again.\n");
        }
    }
    printf("Too many failed attempts. Exiting.\n");
    exit(1);
} 