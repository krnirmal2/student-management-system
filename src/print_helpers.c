#include "print_helpers.h"
#include <stdio.h>

void print_student(const Student* s) {
    printf("\n--- Student Record ---\n");
    printf("Roll No: %d\n", s->roll_no);
    printf("Name: %s %s\n", s->first_name, s->last_name);
    printf("Gender: %s\n", s->gender == MALE ? "Male" : (s->gender == FEMALE ? "Female" : "Other"));
    printf("Course: %s\n", s->course_name);
    printf("Admission Date: %02d-%02d-%04d\n", s->admission_date.day, s->admission_date.month, s->admission_date.year);
    printf("Fee Status: %s\n", s->fees == PAID ? "Paid" : "Due");
    printf("Marks: %.2f\n", s->marks);
    printf("Mobile No: %s\n", s->mobile_no);
    printf("Address: %s, %s, %s, %s, %s\n", s->address.STREET, s->address.IM, s->address.CITY, s->address.PIN, s->address.COUNTRY);
} 