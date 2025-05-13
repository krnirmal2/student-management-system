#include "input_helpers.h"
#include <stdio.h>

int get_valid_int(const char* prompt, int min, int max) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        if (value < min || value > max) {
            printf("Value must be between %d and %d.\n", min, max);
            continue;
        }
        break;
    }
    return value;
}

void get_valid_string(const char* prompt, char* dest, int max_len) {
    printf("%s", prompt);
    scanf("%s", dest);
    dest[max_len-1] = '\0';
} 