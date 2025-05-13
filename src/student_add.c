#include "student_add.h"
#include "input_helpers.h"
#include "print_helpers.h"
#include <stdio.h>

void add_student_record() {
    Student s;
    FILE* fp = fopen("data/DATABASE.DAT", "ab+");
    if (!fp) {
        printf("Error opening database file!\n");
        return;
    }
    printf("\n--- Add Student Record ---\n");
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
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student record added successfully!\n");
} 