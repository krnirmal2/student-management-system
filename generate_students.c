#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { MALE, FEMALE, OTHER } Gender;
typedef enum { PAID, DUE } FeeStatus;
typedef struct { int day, month, year; } Date;
typedef struct {
    char STREET[25];
    char IM[25];
    char CITY[15];
    char COUNTRY[15];
    char PIN[10];
} Address;
typedef struct {
    int roll_no;
    char first_name[20];
    char last_name[20];
    Gender gender;
    char course_name[20];
    Date admission_date;
    FeeStatus fees;
    float marks;
    char mobile_no[15];
    Address address;
} Student;

int main() {
    FILE *fp = fopen("data/DATABASE.DAT", "wb");
    if (!fp) {
        printf("Could not open data/DATABASE.DAT for writing.\n");
        return 1;
    }
    for (int i = 1; i <= 10000; ++i) {
        Student s;
        s.roll_no = i;
        snprintf(s.first_name, sizeof(s.first_name), "First%d", i);
        snprintf(s.last_name, sizeof(s.last_name), "Last%d", i);
        s.gender = (Gender)(i % 3);
        snprintf(s.course_name, sizeof(s.course_name), "Course%d", (i % 5) + 1);
        s.admission_date.day = (i % 28) + 1;
        s.admission_date.month = (i % 12) + 1;
        s.admission_date.year = 2020 + (i % 4);
        s.fees = (FeeStatus)(i % 2);
        s.marks = (float)(50 + (i % 51)); // 50 to 100
        snprintf(s.mobile_no, sizeof(s.mobile_no), "900000%04d", i % 10000);
        snprintf(s.address.STREET, sizeof(s.address.STREET), "Street%d", i);
        snprintf(s.address.IM, sizeof(s.address.IM), "Landmark%d", i);
        snprintf(s.address.CITY, sizeof(s.address.CITY), "City%d", (i % 100) + 1);
        snprintf(s.address.COUNTRY, sizeof(s.address.COUNTRY), "Country");
        snprintf(s.address.PIN, sizeof(s.address.PIN), "%05d", 10000 + (i % 90000));
        fwrite(&s, sizeof(Student), 1, fp);
    }
    fclose(fp);
    printf("Generated 10,000 student records in data/DATABASE.DAT\n");
    return 0;
} 