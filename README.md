# printf Project

## Overview
This project involves implementing our own version of the C library function `printf`. The `printf` function is used to send formatted output to the standard output stream. Our implementation will handle various conversion specifiers and modifiers to format strings, integers, and other data types.

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
