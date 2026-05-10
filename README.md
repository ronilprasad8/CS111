# C++ Coursework Assignments

This repository contains C++ programming assignments completed as part of the **Bachelor of Software Engineering** program at the **University of the South Pacific**. It showcases practical applications of fundamental and intermediate C++ concepts, including control structures, file handling, arrays, and memory management.

## 👤 Author Information
* **Name:** Ronil Prasad
* **Student ID:** S11231541
* **Tutorial Group:** Tuesday (11am - 1pm)

---

## 📂 Repository Structure

The repository is organized into folders for each specific assignment:

### 📁 [asgn1/](./asgn1/) - Tax Calculator
A terminal-based application designed to calculate total tax payable based on specific user demographics.
* **Functionality:** Calculates tax based on age, chargeable income, and residential status.
* **Key Concepts:** Input validation, conditional logic, and mathematical operations.
* **Main File:** `Assign1S11231541.cpp`

### 📁 [asgn2/](./asgn2/) - Student Marks Management System
A data processing program that handles student academic records. Developed in collaboration with **Shivan Siddharat Prasad (S11231502)**.
* **Functionality:** Reads student records from a text file, calculates total marks across subjects, and generates formatted reports.
* **Key Concepts:** File I/O (`<fstream>`), structures (`struct`), arrays, sorting algorithms, and string manipulation.
* **Main File:** `Assignment_02_S11231541_&_S11231502.cpp`
* **Data Files:** * `studentmarks.txt` (Input)
    * `studentData.txt` (Output Report)
    * `summary.txt` (Output Summary)

---

## 🚀 Getting Started

### Prerequisites
To compile and run these programs, you will need a C++ compiler installed:
* **Windows:** MinGW or Visual Studio
* **Linux/macOS:** GCC (`g++`) or Clang

### Compilation & Execution

1. **Navigate** to the specific assignment folder:
   ```bash
   cd asgn1
Compile the source file:

Bash
g++ Assign1S11231541.cpp -o tax_calculator
Run the executable:

Linux/macOS: ./tax_calculator

Windows: tax_calculator.exe

Note: For Assignment 2, ensure that studentmarks.txt is located in the same directory as the executable for the program to read the data correctly.

⚖️ License
This project is submitted for academic grading. All rights reserved. Do not copy or distribute these materials for plagiarism purposes in accordance with the University's academic integrity policy.
