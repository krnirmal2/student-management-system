#include "student_delete.h"
#include "input_helpers.h"
#include <stdio.h>

void delete_student_record() {
    int roll = get_valid_int("Enter Roll No to delete: ", 1, 99999);
    FILE* fp = fopen("data/DATABASE.DAT", "rb");
    FILE* temp = fopen("data/TEMP.DAT", "wb");
    if (!fp || !temp) {
        printf("Error opening database file!\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == roll) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&s, sizeof(Student), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("data/DATABASE.DAT");
    rename("data/TEMP.DAT", "data/DATABASE.DAT");
    if (found) {
        printf("Student record deleted successfully!\n");
    } else {
        printf("No student found with Roll No %d.\n", roll);
    }
} 