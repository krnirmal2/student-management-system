#include "student_search.h"
#include "input_helpers.h"
#include "print_helpers.h"
#include <stdio.h>

void search_student_record() {
    int roll = get_valid_int("Enter Roll No to search: ", 1, 99999);
    FILE* fp = fopen("data/DATABASE.DAT", "rb");
    if (!fp) {
        printf("Error opening database file!\n");
        return;
    }
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == roll) {
            print_student(&s);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("No student found with Roll No %d.\n", roll);
    }
} 