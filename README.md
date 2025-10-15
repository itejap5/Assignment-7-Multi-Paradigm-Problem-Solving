# Multi-Paradigm Problem Solving – Mean, Median, and Mode

This project implements a small program that calculates **mean**, **median**, and **mode** for a list of integers.  
The same problem is solved in **three different programming languages**, each representing a distinct programming paradigm:

- **C** – Procedural Programming  
- **OCaml** – Functional Programming  
- **Python** – Object-Oriented Programming  

---

## 🧩 Overview

### Problem
Given a list of integers, calculate:
- **Mean:** Average of all numbers.  
- **Median:** Middle value after sorting.  
- **Mode:** The most frequent number(s).

### Purpose
The goal is to understand how the same computational problem can be solved using three paradigms and to compare how each language approaches program structure, data handling, and logic design.

---

## ⚙️ Implementations

### 1️⃣ C (Procedural)
- Written as a single file (`main.c`).  
- Uses arrays, loops, and manual sorting (`qsort`).  
- Demonstrates clear procedural flow and manual memory handling.  
- Prints mean, median, and all modes with their frequency.  
- Automatically uses default data if no input is provided (for OneCompiler).

**Run on OneCompiler:**
```bash
gcc main.c -o stats
./stats
```
**Expected Output:**
```vbnet
[Auto mode: default data used]
Input count: 9
Mean: 3.67
Median: 4.00
Mode(s): 5 (freq = 3)
```

### 2️⃣ OCaml (Functional)
- Implemented in main.ml.
- Uses immutable lists and higher-order functions (map, fold_left).
- Avoids mutable state and loops; focuses on recursion and list transformations.
- Reads integers from a single input line or uses default values automatically.

**Run on OneCompiler:**
```bash
ocaml main.ml
```

### 3️⃣ Python (Object-Oriented)
- Defined as a StatisticsCalculator class in main.py.
- Each statistic (mean, median, mode) is a separate method.
- Uses Python’s built-in Counter for mode calculation.
- Demonstrates encapsulation and reusability of OOP design.

**Run on OneCompiler:**
```bash
python3 main.py
```

**Example Output:**
```mathematica
Input count: 9
Mean: 3.67
Median: 4.00
Mode(s): 5 (freq = 3)
```

## Key Differences
| Aspect    | C (Procedural)          | OCaml (Functional)        | Python (OOP)                   |
| --------- | ----------------------- | ------------------------- | ------------------------------ |
| Structure | Step-by-step with loops | Expressions and recursion | Classes and methods            |
| State     | Mutable arrays          | Immutable lists           | Encapsulated objects           |
| Memory    | Manual allocation       | Managed automatically     | Managed automatically          |
| Style     | Focus on control flow   | Focus on transformations  | Focus on abstraction and reuse |

## 📄 Report Summary

The accompanying one-page report compares the experience of implementing the same problem in three paradigms.
It reflects on the differences in coding style, memory handling, readability, and ease of debugging.

## 🙌 Author

- Teja Pavan Kumar Ponneboyina
- University of the Cumberlands
- Assignment 7 – Multi-Paradigm Problem Solving
- October 2025
