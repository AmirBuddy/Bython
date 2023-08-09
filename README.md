# Bython lang

A very simple scripting language named "Bython" written in C++
This was a fun project to learn C++ basics

## Table of Contents

- [Project Overview](#project-overview)
- [Installation](#installation)
- [How to use](#how-to-use)

## Project Overview

You can write and run simple scripts with this language in the terminal which is very very limited.

## Installation

```shell
$ git clone https://github.com/AmirBuddy/Bython.git
$ cd Bython
$ g++ bython.cpp -o bython
```

## How to use

Bython commands list and their form of usage:

| **Command name** |         **Form of usage**        |                     **Description**                    |
|------------------|----------------------------------|--------------------------------------------------------|
|    Assignment    |           A = expression	        |      Save the value of expression in variable A        |
|       Input      |             voroodi()            |                      Take an input                     |
|       Print      |           khoorooji(List)        |              Prints out the values in list             |
|   If Statement   | agar condition : A = expression  |If condition was true, save the value of expression in A|

### Definition of Expression:

- Every constant number is an expression. For example, the numbers 2 and 5 themselves are expressions.
- Any expression in the form of A + B or A - B, where A and B can be variables or constants, is considered an expression. For example A + 5 or VAR - D are valid expressions in which A, D and VAR are variables.
- The remainings are not considered valid. For instance, values like A + B + C or A * B are not expressions.

### Definition of List:

- The expression A where A is a variable or a constant is a list.
- If A and B are two lists, the expression (A, B) is also a list.
- For example if A, B, and D are variables, the expressions (3, A, 7, A) or (1, D, B) are lists.

### Definition of Condition:

- The expression "A == B" where A and B are variables or constants is a condition.
- If the values of A and B are equal, the condition is true; otherwise, the condition is false.
- For example, the expression 3 == 3 is a condition that is true, and the statement A == 5 where the value of A is 6 at runtime is a condition that is false.

### Definition of Variable:

- Any string consisting of combinations of numbers 0 to 9 as well as lowercase and uppercase letters of the English alphabet, with a maximum length of 10 and not starting with a number, is considered a variable.
- For example, the expressions A, VAR2, and ABC123de are valid variables, whereas the expressions _3VAR, 3, 3VAR, and V ARIABLE123 are not valid variables.

## Input

The input consists of two sections. In the first section, program commands are provided in several lines, followed by a line containing the string "-----". After that, program inputs are given, each on a separate line.

The number of lines containing commands will not exceed 50.

It is guaranteed that the number of program inputs matches the number of Input commands, and each variable is assigned a value before being used.

All numbers provided in the commands will be positive integers, but it's possible that during the execution of commands, the value of a variable becomes negative.

## Output

For the output, for each Print command, print its output on a separate line. Then, on a separate line, output the count of variables that have been assigned values at least once.

It is guaranteed that there is at least one Print command in the program commands.

##

### Example 1:

Input:
```
A = 3
B = voroodi()
C = A + B
khoorooji(10)
khoorooji(C, 2)
-----
3
```
Output:
```
10
6 2
3
```

### Example 2:

Input:
```
A = voroodi()
agar A == 2 : A = A + 2
khoorooji(A)
-----
2
```
Output:
```
4
1
```

### Example 3:

Input:
```
agar 2 == 2 : A = 3
agar 3 == 4 : B = 1
khoorooji(A)
-----
```
Output:
```
3
1
```
