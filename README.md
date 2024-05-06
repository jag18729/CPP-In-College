# Grade Calculator Project

This project contains the Grade Calculator program which is designed to calculate the grade percentage based on scores provided for projects, quizzes, homework, and midterms.

## Project Structure

```
.
├── LICENSE
├── README.md
├── grade_calculator      (Executable)
├── grade_calculator.c    (C source code - not used in this build)
├── grade_calculator.cpp  (C++ source code)
```

## Getting Started

Follow these instructions to compile and run the Grade Calculator on your local machine for development and testing.

### Prerequisites

Ensure you have a C++ compiler installed, such as GCC/G++. You can check if GCC is installed and install it if necessary with the following commands on a Debian-based system:

```bash
gcc --version
sudo apt update
sudo apt install build-essential
```

### Compilation

To compile the Grade Calculator:

1. Open a terminal.
2. Navigate to the directory containing `grade_calculator.cpp`.
3. Compile the program using the following command:

```bash
g++ -o grade_calculator grade_calculator.cpp
```

### Running

Execute the program by running:

```bash
./grade_calculator
```

Follow the on-screen prompts to enter grades for projects, quizzes, homework, and midterms. The program will calculate and display the total grade percentage.

## Features

- **Input Validation**: Ensures that all entered grades are within the valid range.
- **User Interaction**: Guides the user through inputting all necessary data and displays the calculated grade percentage.
- **Repeat Calculation**: Allows the user to calculate grades multiple times without restarting the program.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Note:** This README is focused on providing a concise guide for compiling and running the Grade Calculator program. Modify the paths and installation instructions as necessary to match your operating environment and system configuration.
