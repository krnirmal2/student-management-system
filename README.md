# Student Management System (Modular C Project)

## Overview
This is a modularized C project for managing student records with a graphical interface. The system supports adding, searching, modifying, deleting, listing, and backing up student data. The codebase is organized for maintainability and extensibility.

## Folder Structure
```
student-management-system/
│
├── include/                # Header files (.h)
│   ├── student.h
│   ├── address.h
│   ├── ui.h
│   ├── auth.h
│   ├── file_ops.h
│   └── mouse.h
│
├── src/                    # Source files (.c)
│   ├── main.c
│   ├── student.c
│   ├── address.c
│   ├── ui.c
│   ├── auth.c
│   ├── file_ops.c
│   └── mouse.c
│
├── data/                   # Data files
│   ├── DATABASE.DAT
│   └── BACKUP.DAT
│
├── docs/                   # Documentation
│   ├── HLD.md
│   └── LLD.md
│
├── Makefile                # For building the project
└── README.md               # Project overview
```

## Build Instructions
1. Make sure you have a C compiler (e.g., GCC) installed.
2. Use the provided `Makefile` to build the project:
   ```sh
   make
   ```
3. Run the executable:
   ```sh
   ./student_mgmt
   ```

## Modules
- **student**: Student record operations
- **address**: Address structure
- **ui**: User interface and graphics
- **auth**: Authentication (login/password)
- **file_ops**: File and backup operations
- **mouse**: Mouse handling

## Documentation
- See `docs/HLD.md` for High-Level Design
- See `docs/LLD.md` for Low-Level Design 