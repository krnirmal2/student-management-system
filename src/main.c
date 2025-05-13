#include "ui.h"
#include "auth.h"
#include "student_add.h"
#include "student_search.h"
#include "student_modify.h"
#include "student_delete.h"
#include "student_list.h"
#include "file_ops.h"
#include "mouse.h"
#include <stdio.h>

void show_menu() {
    printf("\n==== Student Management System ===="
           "\n1. Add Student"
           "\n2. Search Student by Roll No"
           "\n3. Modify Student"
           "\n4. Delete Student"
           "\n5. List All Students"
           "\n6. Backup Database"
           "\n7. Exit"
           "\nSelect an option: ");
}

int main() {
    int choice;
    printf("Welcome to the Student Management System!\n");
    login_window();
    password_input();

    do {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        switch (choice) {
            case 1: add_student_record(); break;
            case 2: search_student_record(); break;
            case 3: modify_student_record(); break;
            case 4: delete_student_record(); break;
            case 5: list_records(); break;
            case 6: backup_database(); break;
            case 7: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (choice != 7);

    return 0;
} 