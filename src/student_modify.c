#include "student_modify.h"
#include "input_helpers.h"
#include "print_helpers.h"
#include <stdio.h>

void modify_student_record() {
    int roll = get_valid_int("Enter Roll No to modify: ", 1, 99999);
    FILE* fp = fopen("data/DATABASE.DAT", "rb+");
    if (!fp) {
        printf("Error opening database file!\n");
        return;
    }
    Student s;
    int found = 0;
    long pos;
    while ((pos = ftell(fp)), fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == roll) {
            printf("Current details:\n");
            print_student(&s);
            printf("\n--- Enter New Details ---\n");
            s.roll_no = get_valid_int("Enter Roll No: ", 1, 99999);
            get_valid_string("First Name: ", s.first_name, sizeof(s.first_name));
            get_valid_string("Last Name: ", s.last_name, sizeof(s.last_name));
            printf("Gender (0=MALE, 1=FEMALE, 2=OTHER): ");
            int g;
            scanf("%d", &g);
            s.gender = (g >= 0 && g <= 2) ? (Gender)g : OTHER;
            get_valid_string("Course Name: ", s.course_name, sizeof(s.course_name));
            printf("Admission Date:\n");
            s.admission_date.day = get_valid_int("  Day: ", 1, 31);
            s.admission_date.month = get_valid_int("  Month: ", 1, 12);
            s.admission_date.year = get_valid_int("  Year: ", 2000, 2100);
            printf("Fee Status (0=PAID, 1=DUE): ");
            int f;
            scanf("%d", &f);
            s.fees = (f == 0) ? PAID : DUE;
            printf("Marks: ");
            scanf("%f", &s.marks);
            get_valid_string("Mobile No: ", s.mobile_no, sizeof(s.mobile_no));
            get_valid_string("Street: ", s.address.STREET, sizeof(s.address.STREET));
            get_valid_string("Landmark: ", s.address.IM, sizeof(s.address.IM));
            get_valid_string("City: ", s.address.CITY, sizeof(s.address.CITY));
            get_valid_string("PIN: ", s.address.PIN, sizeof(s.address.PIN));
            get_valid_string("Country: ", s.address.COUNTRY, sizeof(s.address.COUNTRY));
            fseek(fp, pos, SEEK_SET);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Student record modified successfully!\n");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("No student found with Roll No %d.\n", roll);
    }
} 