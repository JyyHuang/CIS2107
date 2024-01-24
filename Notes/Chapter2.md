## Chapter 2

### C

Multics

C programming
Steps
1. Edit
    - accomplished with editor program
2. Preprocess
 - give command to compile the program
 - The C preprocessor obeys special commands call preprocessor directives, which indicate that certain manipulations are to be performed on the program before compilation
 3. Compiling
  - Translates the C program into machine language code(AKA object code)
  - it is in executable machine code formate
  - Object code contains a sequence of machine understandable instructions to which the CPU understands and executes
  - Syntax errors
4. Linking
 - C programs typically contain references to functions defined elsewhere, such as in the standard libraries or in the private libraries of groups of programmers working on a particular project.
 - A linker links the object code with the code for the missing functions to produce an executable image(with no missing pieces).
 - In Linux, the command to compile and link is called gcc
5. Loader
 - Before a program can be executed, the program must first be placed in memory.
 - The loader takes the executable image from disk and transfers it to memory.
6. Execution
 - Under the control of the its CPU, the computer executes the program on instruction at a time