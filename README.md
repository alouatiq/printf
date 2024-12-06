# printf Project

## Overview
This project involves implementing our own version of the C library function `printf`. The `printf` function is used to send formatted output to the standard output stream. Our implementation will handle various conversion specifiers and modifiers to format strings, integers, and other data types.

## Stracture:
```
printf/
├── README.md           # Project documentation
├── main.h              # Header file with prototypes and macros (Core for all tasks)
├── _printf.c           # Main printf function implementation (Core for all tasks) - Mandatory
├── _putchar.c          # Writes a character to stdout (Support for all tasks) - Mandatory
├── _printchar.c        # Handler for character specifier (%c) (Task 0) - Mandatory
├── _printstring.c      # Handler for string specifier (%s) (Task 0) - Mandatory
├── _printint.c         # Handler for integer specifiers (%d, %i) (Task 1) - Mandatory
├── _printbinary.c      # Handler for binary specifier (%b) (Task 2) - Advanced
├── _printunsigned.c    # Handler for unsigned integer specifier (%u) (Task 3) - Advanced
├── _printhex.c         # Handler for hexadecimal specifiers (%x, %X) (Task 3) - Advanced
├── _printoctal.c       # Handler for octal specifier (%o) (Task 3) - Advanced
├── _printpointer.c     # Handler for pointer specifier (%p) (Task 6) - Advanced
├── _printcustom.c      # Handler for custom specifiers (%r, %R, %S) (Tasks 5, 13, 14) - Advanced
├── buffer.c            # Buffer management for optimizing write calls (Task 4) - Advanced
├── _strlen.c           # Utility function to calculate string length (Support for Tasks 0, 5, 13, 14) - Mandatory
├── _strcpy.c           # Utility function to copy strings (Support for custom specifiers) - Advanced
├── _itoa.c             # Utility function to convert integers to strings (Support for Tasks 1, 3) - Advanced
├── _rot13.c            # Utility function for ROT13 encoding (%R) (Task 14) - Advanced
├── _reverse.c          # Utility function to reverse a string (%r) (Task 13) - Advanced
├── test_main.c         # Main file for testing (Covers all mandatory and advanced tasks) - Mandatory
├── test_cases.c        # Additional test cases (Comprehensive task testing) - Advanced
├── betty-style.pl      # Betty style checker script - Support
├── betty-doc.pl        # Betty documentation checker script - Support
├── man_3_printf        # Manual file for the custom printf function - Support
├── .gitignore          # Files and directories to ignore in Git (Support for repository management)
```

## Team Members
- Hassan AL OUATIQ
- Adewole Gege

## Project Timeline
- **Start:** July 26, 2024, 5:00 AM
- **End:** August 1, 2024, 5:00 AM

## Requirements
- **Editors:** vi, vim, emacs
- **Compilation:** Ubuntu 20.04 LTS, using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Code Style:** Betty style guidelines
- **Prohibited:** Global variables, more than 5 functions per file
- **Mandatory Files:** A `README.md` file at the root of the project, all function prototypes in `main.h`, all header files include guarded

## Functionality
### Basic Printf Implementation
- **Prototype:** `int _printf(const char *format, ...);`
- **Conversion Specifiers:**
  - `c` - character
    - `s` - string
      - `%` - percent sign

### Additional Specifiers and Features
1. **d, i:** Handle integers.
2. **b:** Convert unsigned int to binary.
3. **u, o, x, X:** Handle unsigned int, octal, and hexadecimal (both lower and upper case).
4. **Buffer:** Use a local buffer of 1024 chars to minimize calls to `write`.
5. **S:** Print string with non-printable characters as `\x` followed by ASCII code in hexadecimal.
6. **p:** Handle pointer addresses.
7. **Flags:** Handle `+`, `space`, `#` for non-custom conversion specifiers.
8. **Length Modifiers:** Handle `l`, `h` for `d`, `i`, `u`, `o`, `x`, `X`.
9. **Field Width:** Implement field width handling.
10. **Precision:** Implement precision handling.
11. **0 Flag:** Handle the `0` flag character.
12. **- Flag:** Handle the `-` flag character.
13. **r:** Print reversed string.
14. **R:** Print ROT13 encoded string.
15. **Comprehensive Functionality:** Ensure all options work together seamlessly.

## Authorized Functions and Macros
- `write` (man 2 write)
- `malloc` (man 3 malloc)
- `free` (man 3 free)
- `va_start` (man 3 va_start)
- `va_end` (man 3 va_end)
- `va_copy` (man 3 va_copy)
- `va_arg` (man 3 va_arg)

## Compilation Instructions
Your code will be compiled this way:
```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```
