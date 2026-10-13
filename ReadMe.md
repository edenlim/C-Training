# C Programming Cheat Sheet & Reference Guide

Welcome to C! This document provides a quick-start syntax reference followed by tables of the most commonly used standard library functions with practical examples.

---

## 1. Basic Syntax Reference

### 1.1 Minimal Program Structure
Every C program starts execution at the `main()` function:

```c
#include <stdio.h> // Preprocessor directive: include standard I/O library

int main(void) {
    // Single-line comment
    /* Multi-line
       comment */
    printf("Hello, World!\n");
    return 0; // 0 indicates successful execution
}
```

---

### 1.2 Data Types & Variables

| Type | Typical Size | Description | Example |
| :--- | :--- | :--- | :--- |
| `int` | 4 bytes | Whole numbers | `int age = 21;` |
| `float` | 4 bytes | Single-precision floating point | `float price = 19.99f;` |
| `double` | 8 bytes | Double-precision floating point | `double pi = 3.1415926535;` |
| `char` | 1 byte | Single character / ASCII code | `char grade = 'A';` |
| `void` | - | Absence of type | `void doSomething();` |
| `size_t` | 8 bytes (64-bit) | Unsigned integer for sizes/counts | `size_t len = 10;` |

---

### 1.3 Format Specifiers (for `printf` / `scanf`)

| Specifier | Used For | Example |
| :--- | :--- | :--- |
| `%d` or `%i` | Signed integer | `printf("%d", 42);` |
| `%u` | Unsigned integer | `printf("%u", 3000000000U);` |
| `%f` | Float | `printf("%.2f", 3.14159); // Output: 3.14` |
| `%lf` | Double (in `scanf`) / Float in `printf` | `scanf("%lf", &myDouble);` |
| `%c` | Single character | `printf("%c", 'Z');` |
| `%s` | String (null-terminated char array) | `printf("%s", "Hello");` |
| `%p` | Pointer address (hexadecimal) | `printf("%p", (void*)&x);` |
| `%zu` | `size_t` value | `printf("%zu", sizeof(int));` |

---

### 1.4 Control Flow

#### `if` / `else if` / `else`
```c
int score = 85;
if (score >= 90) {
    printf("Grade A\n");
} else if (score >= 80) {
    printf("Grade B\n");
} else {
    printf("Grade C or below\n");
}
```

#### `switch`
```c
char op = '+';
switch (op) {
    case '+':
        printf("Addition\n");
        break;
    case '-':
        printf("Subtraction\n");
        break;
    default:
        printf("Unknown operator\n");
        break;
}
```

#### Loops (`for`, `while`, `do-while`)
```c
// For loop
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}

// While loop
int count = 0;
while (count < 5) {
    printf("%d ", count);
    count++;
}

// Do-While loop (always runs at least once)
int num = 0;
do {
    printf("%d ", num);
    num++;
} while (num < 5);
```

---

### 1.5 Arrays & Strings

In C, strings are simply null-terminated (`\0`) character arrays.

```c
// Arrays
int numbers[5] = {10, 20, 30, 40, 50};
int first = numbers[0]; // 10

// Strings
char name[] = "Eden";            // Automatically adds '\0' at the end
char buffer[50];                 // Uninitialized char buffer
```

---

### 1.6 Pointers & Memory Basics

A pointer holds the memory address of another variable:
- `&` (Address-of operator): retrieves the memory address.
- `*` (Dereference operator): accesses the value stored at that address.

```c
int val = 42;
int *ptr = &val;   // ptr points to val's memory address

printf("Value: %d\n", *ptr);      // 42 (dereferenced)
printf("Address: %p\n", (void*)ptr); // e.g. 0x7ffee1234567

*ptr = 99;         // Modifies val directly
printf("Val now: %d\n", val);     // 99
```

---

### 1.7 Structs & Typedefs

```c
// Defining a struct with typedef for convenience
typedef struct {
    char name[32];
    int age;
    float gpa;
} Student;

Student s1 = {"Alice", 20, 3.85f};
printf("Name: %s, GPA: %.2f\n", s1.name, s1.gpa);

// Accessing through a pointer uses the arrow operator (->)
Student *sPtr = &s1;
printf("Age via pointer: %d\n", sPtr->age);
```

---

## 2. Common C Standard Library Functions

### 2.1 Standard Input / Output (`<stdio.h>`)

| Function                 | Description                                           | Example                                           |
| :----------------------- | :---------------------------------------------------- | :------------------------------------------------ |
| `printf(...)`            | Formatted output to stdout                            | `printf("Score: %d, Rate: %.2f%%\n", 100, 95.5);` |
| `scanf(...)`             | Formatted input from stdin                            | `int x; scanf("%d", &x);`                         |
| `fgets(buf, sz, stream)` | Reads a line safely from a stream (including stdin)   | `char str[64]; fgets(str, sizeof(str), stdin);`   |
| `puts(str)`              | Prints string with automatic trailing newline         | `puts("Operation complete.");`                    |
| `getchar()`              | Reads single character from stdin                     | `int ch = getchar();`                             |
| `putchar(ch)`            | Writes single character to stdout                     | `putchar('A');`                                   |
| `fopen(path, mode)`      | Opens file stream (`"r"`, `"w"`, `"a"`, `"rb"`, etc.) | `FILE *f = fopen("data.txt", "r");`               |
| `fclose(stream)`         | Closes an open file stream                            | `fclose(f);`                                      |
| `fprintf(stream, ...)`   | Formatted output to a specific file stream            | `fprintf(f, "Result: %d\n", 42);`                 |
| `fscanf(stream, ...)`    | Formatted input from a specific file stream           | `fscanf(f, "%d", &num);`                          |
| `fread(ptr, sz, n, f)`   | Reads binary data chunks from file                    | `fread(buffer, sizeof(int), 10, f);`              |
| `fwrite(ptr, sz, n, f)`  | Writes binary data chunks to file                     | `fwrite(buffer, sizeof(int), 10, f);`             |
| `perror(msg)`            | Prints custom message + system error description      | `perror("Error opening file");`                   |
| `snprintf(buf, sz, ...)` | Safe formatted write into string buffer               | `snprintf(buf, sizeof(buf), "ID: %d", id);`       |

---

### 2.2 String & Memory Operations (`<string.h>`)

| Function | Description | Example |
| :--- | :--- | :--- |
| `strlen(s)` | Returns the length of string (excluding `\0`) | `size_t len = strlen("Hello"); // 5` |
| `strcpy(dest, src)` | Copies string (unsafe if dest is too small) | `strcpy(dest, "Sample");` |
| `strncpy(dest, src, n)` | Copies up to `n` characters | `strncpy(dest, src, sizeof(dest) - 1);` |
| `strcat(dest, src)` | Concatenates `src` onto `dest` | `strcat(dest, " World");` |
| `strcmp(s1, s2)` | Compares two strings (`0` if equal, `<0` or `>0` if not) | `if (strcmp(a, b) == 0) { /* equal */ }` |
| `strncmp(s1, s2, n)` | Compares first `n` characters of two strings | `if (strncmp(a, "CMD_", 4) == 0) { ... }` |
| `strchr(s, ch)` | Finds first occurrence of character `ch` in string | `char *dot = strchr("file.txt", '.');` |
| `strstr(haystack, needle)` | Finds first occurrence of substring in string | `char *pos = strstr("full text", "text");` |
| `strtok(str, delim)` | Splits string into tokens by delimiters | `char *tok = strtok(line, ",");` |
| `memset(ptr, val, n)` | Fills `n` bytes of memory with constant byte value | `memset(arr, 0, sizeof(arr));` |
| `memcpy(dest, src, n)` | Copies `n` bytes from `src` to `dest` (non-overlapping) | `memcpy(destArr, srcArr, sizeof(int) * 5);` |
| `memmove(dest, src, n)` | Copies `n` bytes safely (handles overlapping memory) | `memmove(arr + 1, arr, sizeof(int) * 4);` |
| `memcmp(s1, s2, n)` | Compares `n` bytes of two memory blocks | `if (memcmp(a, b, sizeof(Data)) == 0) { ... }` |

---

### 2.3 Dynamic Memory Allocation (`<stdlib.h>`)

| Function | Description | Example |
| :--- | :--- | :--- |
| `malloc(bytes)` | Allocates uninitialized heap memory | `int *arr = malloc(10 * sizeof(int));` |
| `calloc(n, size)` | Allocates heap memory and zeros all bytes | `int *arr = calloc(10, sizeof(int));` |
| `realloc(ptr, new_size)` | Resizes previously allocated heap memory block | `arr = realloc(arr, 20 * sizeof(int));` |
| `free(ptr)` | Releases allocated heap memory back to system | `free(arr); arr = NULL;` |

---

### 2.4 Conversion & General Utilities (`<stdlib.h>`)

| Function | Description | Example |
| :--- | :--- | :--- |
| `atoi(str)` | Converts string to `int` | `int val = atoi("123");` |
| `atof(str)` | Converts string to `double` | `double d = atof("3.14");` |
| `strtol(str, end, base)` | Robust string-to-long conversion with error checking | `long val = strtol("1010", NULL, 2); // Base 2` |
| `abs(n)` | Returns absolute value of integer | `int positive = abs(-15); // 15` |
| `rand()` | Generates pseudo-random integer (`0` to `RAND_MAX`) | `int r = rand() % 100; // 0..99` |
| `srand(seed)` | Seeds pseudo-random number generator | `srand((unsigned int)time(NULL));` |
| `qsort(base, n, sz, cmp)` | In-place quicksort on any array type | `qsort(arr, n, sizeof(int), compareInts);` |
| `exit(status)` | Immediately terminates the program with status code | `exit(EXIT_FAILURE);` |

---

### 2.5 Character Classification & Conversion (`<ctype.h>`)

| Function | Description | Example |
| :--- | :--- | :--- |
| `isdigit(ch)` | Checks if character is a digit (`0`-`9`) | `if (isdigit('5')) { ... }` |
| `isalpha(ch)` | Checks if character is alphabetic (`a`-`z`, `A`-`Z`) | `if (isalpha('x')) { ... }` |
| `isalnum(ch)` | Checks if character is alphanumeric | `if (isalnum('A')) { ... }` |
| `isspace(ch)` | Checks if character is whitespace (space, tab, newline) | `if (isspace(' ')) { ... }` |
| `toupper(ch)` | Converts character to uppercase | `char upper = toupper('a'); // 'A'` |
| `tolower(ch)` | Converts character to lowercase | `char lower = tolower('G'); // 'g'` |

---

### 2.6 Mathematical Functions (`<math.h>`)

> **Note**: On Linux/GCC, link the math library with `-lm` during compilation (e.g., `gcc main.c -lm`).

| Function | Description | Example |
| :--- | :--- | :--- |
| `sqrt(x)` | Square root ($\sqrt{x}$) | `double root = sqrt(16.0); // 4.0` |
| `pow(base, exp)` | Power ($base^{exp}$) | `double result = pow(2.0, 8.0); // 256.0` |
| `ceil(x)` | Rounds up to nearest integer | `ceil(4.2); // 5.0` |
| `floor(x)` | Rounds down to nearest integer | `floor(4.8); // 4.0` |
| `round(x)` | Rounds to nearest integer | `round(4.5); // 5.0` |
| `fabs(x)` | Absolute value for floating point | `fabs(-3.14); // 3.14` |
| `sin(x)` / `cos(x)` | Trigonometric sine / cosine (in radians) | `double s = sin(3.14159 / 2); // ~1.0` |

---

### 2.7 Time & Clock (`<time.h>`)

| Function | Description | Example |
| :--- | :--- | :--- |
| `time(NULL)` | Returns current epoch time in seconds | `time_t now = time(NULL);` |
| `clock()` | CPU clock ticks consumed since program start | `clock_t start = clock();` |
| `difftime(t2, t1)` | Difference in seconds between two `time_t` values | `double diff = difftime(t2, t1);` |
| `strftime(...)` | Formats a broken-down time struct into a string | `strftime(buf, sizeof(buf), "%Y-%m-%d", tm);` |
