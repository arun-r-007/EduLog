# EduLog - Student Info Management System (C Project)

A simple **Student Information Management System** written in **C**, using only basic concepts like arrays and structures — no advanced data structures. This project is designed for beginners to understand how to create a console-based system with CRUD operations.

## Features

-  Add a new student  
-  Display all students  
-  Search student by Roll Number  
-  Update student details  
-  Delete student record  
-  Clean menu-driven interface  

## Technologies Used

- **Language:** C  
- **Compiler:** GCC / MinGW  
- **Platform:** Console (cross-platform: Linux, Windows)

## File Structure

```

Student-Info-Management-System/
├── student\_info.c       # Main source code
├── README.md            # Project documentation

````

## How to Compile & Run

### On Linux/macOS:
```bash
gcc student_info.c -o student_info
./student_info
````

### On Windows (MinGW):

```bash
gcc student_info.c -o student_info.exe
student_info.exe
```

>  Make sure GCC is installed. If not, install it via `sudo apt install build-essential` (Linux) or [MinGW](https://www.mingw-w64.org/) (Windows).

## Sample Output

```
==================================================
      STUDENT INFO MANAGEMENT SYSTEM
==================================================
1. Add Student
2. Display All Students
3. Search Student by Roll No
4. Update Student
5. Delete Student
6. Exit
--------------------------------------------------
Enter your choice:
```

## Demo Website

[live Website](https://arun-r-007.github.io/EduLog/)

---

## Website Screenshot

![website Screenshot](https://github.com/user-attachments/assets/d56cb82b-0434-4474-92e5-ecadc50c3327)

---

## Output Screenshot

![Demo Image](https://github.com/user-attachments/assets/83a5827a-a1a5-443e-9503-e61edf68c9de)

---

## Future Improvements

* [ ] Add file storage (text/binary)
* [ ] Add input validation
* [ ] Create GUI with C++ or web frontend
