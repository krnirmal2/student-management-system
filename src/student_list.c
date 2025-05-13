#include "student_list.h"
#include "print_helpers.h"
#include <stdio.h>

void list_records() {
    FILE* fp = fopen("data/DATABASE.DAT", "rb");
    if (!fp) {
        printf("Error opening database file!\n");
        return;
    }
    Student s;
    int count = 0;
    printf("\n--- All Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        print_student(&s);
        count++;
    }
    fclose(fp);
    if (count == 0) {
        printf("No student records found.\n");
    } else {
 