#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR_CMD "cls"
#else
#define CLEAR_CMD "clear"
#endif

// Draw the main screen layout
void draw_screen() {
    printf("\n------------------------------------\n");
    printf("      Student Management System      \n");
    printf("------------------------------------\n");
}

// Draw the add student window
void add_window() {
    printf("\n--- Add Student Window ---\n");
}

// Display student data on the screen
void display_data() {
    printf("\n--- Student Data ---\n");
}

void clear_screen() {
    system(CLEAR_CMD);
}

void pause_screen() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // clear buffer
    getchar();
}

void print_success(const char* msg) {
    printf("\033[1;32m[SUCCESS]\033[0m %s\n", msg); // Green text
}

void print_error(const char* msg) {
    printf("\033[1;31m[ERROR]\033[0m %s\n", msg); // Red text
} 