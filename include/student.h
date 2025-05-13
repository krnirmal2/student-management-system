/**
 * @file student.h
 * @brief Student record management functions and data structures.
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "address.h"

// Gender enumeration
typedef enum { MALE, FEMALE, OTHER } Gender;
// Fee status enumeration
typedef enum { PAID, DUE } FeeStatus;
// Date structure
typedef struct {
    int day, month, year;
} Date;

// Student structure
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

void add_student_record();
void search_student_record();
void modify_student_record();
void delete_student_record();
void list_records();

#endif // STUDENT_H 