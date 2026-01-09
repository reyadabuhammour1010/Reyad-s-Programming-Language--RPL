[rpl_readme (1).md](https://github.com/user-attachments/files/24511299/rpl_readme.1.md)
# Reyad's Programming Language (RPL) - Beta

Welcome to **Reyad's Programming Language (RPL)**!  
This is a small, experimental programming language created for learning and experimentation purposes. It is currently in **Beta**, which means some features may be incomplete, and users may encounter errors or unexpected behavior.  

---

## Features

RPL is a simple language designed to teach basic programming concepts. It currently supports:

- **Variable Declaration**
  ```rpl
  Int x = 10
  Int y = 5
  ```
  Declare integer variables. Variable names must follow basic naming rules.

- **Printing Values**
  ```rpl
  Print x
  Print Op x + y
  ```
  Print values of variables or perform simple arithmetic operations directly in the print statement.

- **Loops**
  ```rpl
  Loop 1 to 5
  ```
  Print numbers in a simple range. Loops currently cannot include other statements inside them.

- **Basic Syntax**
  - Every code must end with `End`.
  - Statements are separated by spaces.
  - Operations supported: `+`, `-`, `*`, `/`.

---

## Example

```rpl
Int x = 8
Int y = 4
Print x
Print Op x + 8
Print Op 7 - y
Print Op x + y
Int z = 4
Print z
Loop 1 to 5
End
```

Expected output:
```
8
16
3
12
4
1
2
3
4
5
```

---

## Important Notes

- This project is **Beta**. Errors or unexpected behavior may occur.
- Loops are simple and cannot currently include other statements.
- Operations are limited to integers and basic arithmetic.
- Variable naming follows standard rules: cannot start with numbers, cannot use keywords like `End`, `Int`, `Loop`, `Print`, `Op`, and cannot include special characters.

---

## How to Use

1. Clone this repository.
2. Compile the C++ files using a C++ compiler (supports C++17 or later).
3. Run the executable.
4. Enter your code following the RPL syntax.

---

Thank you for trying **RPL**!  
