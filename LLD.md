# Low-Level Design (LLD)

## Project Details & Data Structures

### Data Model
- **Gender** and **FeeStatus** are enums for type safety.
- **Date** struct for admission date.
- **Student** struct encapsulates all student data, including address.

```c
typedef enum { MALE, FEMALE, OTHER } Gender;
typedef enum { PAID, DUE } FeeStatus;
typedef struct { int day, month, year; } Date;
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
```

---

## Module Responsibilities

### Authentication (auth.c/auth.h)
- `login_window()`, `password_input()`
- Handles user login and password validation.

### Student Management (student.c/student.h)
- `add_student_record()`: Add a new student with input validation.
- `search_student_record()`: Search by roll number, print details if found.
- `modify_student_record()`: Update a student's details, with validation.
- `delete_student_record()`: Remove a student by roll number.
- `list_records()`: List all students, formatted output.
- **Helpers**: Input validation, print student, etc.

### UI (ui.c/ui.h)
- Handles menu display and user prompts (text-based for portability).

### File Operations (file_ops.c/file_ops.h)
- `backup_database()`: Copy database to backup file.
- `progress()`: Show progress bar (optional, for UI feedback).
- `exit_system()`: Clean exit.

### Address (address.c/address.h)
- Address struct and (future) address-related helpers.

### Mouse (mouse.c/mouse.h)
- (Reserved for future graphical UI or mouse support.)

---

## Input Validation & Error Handling
- All user input is validated (range checks, string length, etc.).
- File operations check for errors and provide user feedback.
- All destructive actions (modify/delete) require confirmation.

---

## User Flow
1. User logs in.
2. Main menu is displayed.
3. User selects an operation (add, search, modify, delete, list, backup, exit).
4. Each operation provides clear prompts, validates input, and gives feedback.
5. The system loops until the user chooses to exit.

---

## Extensibility
- Add new search/filter/report/export features in student.c and update the menu.
- UI can be upgraded to graphical or web-based by replacing ui.c/ui.h.
- Data storage can be migrated to a database by updating file_ops.c.

---

*For a summary, see the High-Level Design (HLD) document.* 