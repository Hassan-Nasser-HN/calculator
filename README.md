# 🧮 C++ Calculator — OOP & SOLID Project

A console-based calculator application developed in **C++** using Object-Oriented Programming principles and designed with **SOLID principles** and clean, modular architecture.

The application can evaluate mathematical expressions containing arithmetic operators, parentheses, decimal numbers, and unary minus. It also provides persistent calculation history using a file-based repository.

---

## 📌 Project Overview

This project was built to demonstrate how a traditional calculator can be transformed into a **well-structured and extensible Object-Oriented application**.

Instead of putting all calculator logic inside one class, the system is divided into several independent components, where each component has a specific responsibility.

The main calculation flow is:

```text
User Input
    ↓
ConsoleUI
    ↓
Calculator
    ↓
Validator
    ↓
Tokenizer
    ↓
Parser
    ↓
Evaluator
    ↓
Result
    ↓
HistoryRepository
```

This separation makes the application easier to:

* Understand
* Maintain
* Test
* Extend
* Modify without affecting unrelated components

---

# ✨ Features

The calculator currently supports:

* ➕ Addition
* ➖ Subtraction
* ✖️ Multiplication
* ➗ Division
* 🔢 Decimal numbers
* ➖ Unary minus
* `( )` Parentheses
* Operator precedence
* Expression validation
* Infix-to-postfix conversion
* Postfix expression evaluation
* Calculation history
* File-based history storage
* Exception handling
* Invalid input handling
* Division-by-zero protection

### Example Expressions

```text
2 + 3
10 - 4
5 * 6
20 / 4
2 + 3 * 4
(2 + 3) * 4
-5 + 3
2 * -4
10.5 / 2
```

---

# 🏗️ Architecture

The project follows a layered architecture.

```text
                         ┌─────────────────┐
                         │    ConsoleUI    │
                         └────────┬────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │    Calculator   │
                         └────────┬────────┘
                                  │
             ┌────────────────────┼────────────────────┐
             │                    │                    │
             ▼                    ▼                    ▼
       ┌───────────┐       ┌───────────┐       ┌───────────┐
       │ Validator │       │ Tokenizer │       │   Parser  │
       └───────────┘       └───────────┘       └───────────┘
                                                        │
                                                        ▼
                                                ┌─────────────┐
                                                │  Evaluator  │
                                                └──────┬──────┘
                                                       │
                                                       ▼
                                             ┌──────────────────┐
                                             │ OperatorRegistry │
                                             └────────┬─────────┘
                                                      │
                           ┌──────────────────────────┼──────────────────────────┐
                           │                          │                          │
                           ▼                          ▼                          ▼
                    AddOperation            SubtractOperation         MultiplyOperation
                           │
                           └──────────────────────────┐
                                                      ▼
                                               DivideOperation
```

The history system is separated from the calculation logic:

```text
Calculator
     │
     ▼
HistoryRepository
     │
     ▼
FileHistoryRepository
     │
     ▼
history.txt
```

---

# 🔄 Calculation Flow

When the user enters an expression, it passes through several stages.

## 1. Validation

The `validator` checks whether the expression is valid.

It checks:

* Empty expressions
* Invalid characters
* Balanced parentheses
* Invalid operator combinations
* Consecutive decimal points
* Empty parentheses

Example:

```text
10 / 0
```

The expression itself can be syntactically valid, while the division-by-zero error is handled later by the operation implementation.

---

## 2. Tokenization

The `Tokenizer` converts the expression into individual tokens.

Example:

```text
2 + 3 * 4
```

becomes:

```text
["2", "+", "3", "*", "4"]
```

It also handles unary minus.

Example:

```text
2 * -5
```

becomes:

```text
["2", "*", "-5"]
```

---

## 3. Parsing

The `parser` converts the infix expression into postfix notation using the **Shunting Yard algorithm**.

Example:

```text
2 + 3 * 4
```

becomes:

```text
2 3 4 * +
```

This allows the evaluator to process operator precedence correctly.

---

## 4. Evaluation

The `Evaluator` evaluates the postfix expression using a stack.

For:

```text
2 3 4 * +
```

The evaluation is:

```text
3 * 4 = 12
2 + 12 = 14
```

Final result:

```text
14
```

---

## 5. History

After a successful calculation, the result is recorded through:

```text
HistoryRepository
```

The current implementation uses:

```text
FileHistoryRepository
```

which stores the history inside:

```text
history.txt
```

Example:

```text
2+3 = 5
(4-2)*3 = 6
10/2 = 5
```

---

# 📂 Project Structure

```text
Calculator/
│
├── include/
│   │
│   ├── operation.h
│   │
│   ├── AddOperation.h
│   ├── SubtractOperation.h
│   ├── MultiplyOperation.h
│   ├── DivideOperation.h
│   │
│   ├── OperatorRegistry.h
│   │
│   ├── Calculator.h
│   ├── ConsoleUI.h
│   │
│   ├── Tokenizer.h
│   ├── parser.h
│   ├── validator.h
│   ├── Evaluator.h
│   │
│   ├── HistoryRepository.h
│   └── FileHistoryRepository.h
│
├── src/
│   │
│   ├── AddOperation.cpp
│   ├── SubtractOperation.cpp
│   ├── MultiplyOperation.cpp
│   ├── DivideOperation.cpp
│   │
│   ├── OperatorRegistry.cpp
│   │
│   ├── Calculator.cpp
│   ├── ConsoleUI.cpp
│   │
│   ├── Tokenizer.cpp
│   ├── parser.cpp
│   ├── validator.cpp
│   ├── Evaluator.cpp
│   │
│   └── FileHistoryRepository.cpp
│
├── main.cpp
├── CMakeLists.txt
├── history.txt
└── README.md
```

---

# 🧩 Main Components

## ConsoleUI

Responsible for interaction with the user.

Responsibilities:

* Display the main menu
* Receive user input
* Start calculations
* Display results
* Display calculation history
* Handle user-level errors

---

## Calculator

The `Calculator` acts as the main coordinator.

It does not implement every calculation detail itself.

Instead, it coordinates:

```text
Validator
    ↓
Tokenizer
    ↓
Parser
    ↓
Evaluator
    ↓
HistoryRepository
```

This keeps the class focused on coordinating the calculation process.

---

## Validator

Responsible for checking whether the expression is syntactically valid before processing it.

```text
Expression
    ↓
Validator
    ├── Empty?
    ├── Valid characters?
    ├── Balanced parentheses?
    └── Valid operators?
```

---

## Tokenizer

Responsible for converting the input string into tokens.

Example:

```text
(10 + 5) * -2
```

becomes:

```text
(
10
+
5
)
*
-2
```

---

## Parser

Responsible for converting infix notation into postfix notation.

It uses the **Shunting Yard algorithm** to handle:

* Operator precedence
* Parentheses
* Operator ordering

---

## Evaluator

Responsible for calculating the final result from the postfix expression.

It uses:

```text
std::stack<double>
```

to process operands and operations.

---

## OperatorRegistry

`OperatorRegistry` is the central place for managing operators.

Each registered operator contains:

```text
Operator Symbol
       +
       ↓
Precedence
       +
       ↓
Operation Implementation
```

Current operators:

| Symbol | Precedence | Class               |
| ------ | ---------: | ------------------- |
| `+`    |          1 | `AddOperation`      |
| `-`    |          1 | `SubtractOperation` |
| `*`    |          2 | `MultiplyOperation` |
| `/`    |          2 | `DivideOperation`   |

---

# 🔌 Operation Abstraction

The project uses an abstract base class:

```cpp
class operation {
public:
    virtual double execute(
        double firstOperand,
        double secondOperand
    ) const = 0;

    virtual ~operation() = default;
};
```

Each operation implements this interface.

```text
              operation
                   │
        ┌──────────┼──────────┐
        │          │          │
        ▼          ▼          ▼
      Add      Subtract   Multiply
                              │
                              ▼
                           Divide
```

For example:

```cpp
class AddOperation : public operation {
public:
    double execute(
        double firstOperand,
        double secondOperand
    ) const override;
};
```

---

# 🗃️ History System

The history system uses an abstraction called:

```text
HistoryRepository
```

It defines:

```cpp
record()
printAll()
clear()
```

The current implementation is:

```text
HistoryRepository
        ▲
        │
FileHistoryRepository
```

This means the calculator does not directly depend on a file.

In the future, other implementations could be added:

```text
HistoryRepository
       ▲
       │
 ┌─────┼──────────────┐
 │     │              │
 ▼     ▼              ▼
File  Database     Memory
```

The `Calculator` would not need to change.

---

# 🧠 OOP Concepts Used

## Encapsulation

Each class hides its internal implementation and exposes only the required public methods.

Example:

```cpp
class Evaluator {
private:
    const OperatorRegistry& operators;

public:
    double evaluatePostfix(
        const vector<string>& postfix
    ) const;
};
```

---

## Abstraction

Abstract classes are used to define common interfaces.

Examples:

```text
operation
HistoryRepository
```

---

## Inheritance

Concrete classes inherit from abstract classes.

```text
operation
   ↑
   ├── AddOperation
   ├── SubtractOperation
   ├── MultiplyOperation
   └── DivideOperation
```

And:

```text
HistoryRepository
       ↑
       │
FileHistoryRepository
```

---

## Polymorphism

The calculator can work with different implementations through base-class references.

For example:

```cpp
HistoryRepository& history;
```

The calculator does not need to know whether the repository is a file,
database, or another implementation.

---

## Composition

The `Calculator` is composed of several independent components:

```text
Calculator
    ├── Validator
    ├── Tokenizer
    ├── Parser
    ├── Evaluator
    └── HistoryRepository
```

---

# 🧱 SOLID Principles

## S — Single Responsibility Principle

Each class has one main responsibility.

| Class                   | Responsibility           |
| ----------------------- | ------------------------ |
| `ConsoleUI`             | User interaction         |
| `Calculator`            | Coordinate calculation   |
| `validator`             | Validate expressions     |
| `Tokenizer`             | Generate tokens          |
| `parser`                | Convert infix to postfix |
| `Evaluator`             | Evaluate postfix         |
| `OperatorRegistry`      | Manage operators         |
| `FileHistoryRepository` | Store history            |

---

## O — Open/Closed Principle

The operator system can be extended with new operations.

For example, adding:

```text
PowerOperation
```

does not require changing the existing operation classes.

```cpp
class PowerOperation : public operation {
public:
    double execute(
        double base,
        double exponent
    ) const override;
};
```

Then register it:

```cpp
registerOperation(
    "^",
    3,
    make_shared<PowerOperation>()
);
```

---

## L — Liskov Substitution Principle

Any concrete `operation` can be used through the `operation` abstraction.

```text
operation
   ▲
   │
AddOperation
```

The same interface works for:

```text
AddOperation
SubtractOperation
MultiplyOperation
DivideOperation
```

---

## I — Interface Segregation Principle

The project uses focused interfaces rather than one large interface.

For example:

```text
HistoryRepository
```

contains only history-related operations.

---

## D — Dependency Inversion Principle

High-level classes depend on abstractions instead of concrete implementations.

For example:

```cpp
HistoryRepository& history;
```

instead of:

```cpp
FileHistoryRepository history;
```

This makes the calculator independent from the storage mechanism.

---

# 🎯 Design Patterns

## Strategy Pattern

Each mathematical operation is implemented as a separate strategy.

```text
          operation
              ▲
              │
      ┌───────┼────────┐
      │       │        │
      ▼       ▼        ▼
     Add    Multiply   Divide
```

The `OperatorRegistry` selects the appropriate operation.

---

## Repository Pattern

The history system separates storage logic from the calculator.

```text
Calculator
     │
     ▼
HistoryRepository
     │
     ▼
FileHistoryRepository
```

This allows the storage implementation to be replaced later.

---

# ➕ Adding a New Operator

Adding a new operator follows three main steps.

## Step 1 — Create the Header

Example:

```cpp
class PowerOperation : public operation {
public:
    double execute(
        double base,
        double exponent
    ) const override;
};
```

## Step 2 — Implement the Operation

```cpp
double PowerOperation::execute(
    double base,
    double exponent
) const {
    return pow(base, exponent);
}
```

## Step 3 — Register the Operator

Inside `OperatorRegistry`:

```cpp
registerOperation(
    "^",
    3,
    make_shared<PowerOperation>()
);
```

The rest of the calculator architecture remains unchanged.

---

# 🛡️ Error Handling

The application uses C++ exceptions to handle runtime errors.

### Division by Zero

```text
Enter an expression: 10/0

Error: Division by zero
```

### Invalid Expression

```text
Enter an expression: 5++2

Error: Invalid expression.
```

The application catches exceptions in the user interface so that an error
does not terminate the entire application.

---

# 🖥️ Example Run

```text
=====================================
          Math Application
=====================================
1. Basic Calculator
2. Show History
0. Exit
=====================================
Enter your choice: 1

========== Basic Calculator ==========
Enter an expression: (4-2)*3

Result: 6

Do you want to perform another calculation? (Y/N): Y

========== Basic Calculator ==========
Enter an expression: 10/0

Error: Division by zero

Do you want to perform another calculation? (Y/N): N
```

---

# ⚙️ Requirements

* C++14 or later
* CMake 4.1 or compatible version
* C++ compiler such as:

    * GCC
    * MinGW
    * Clang
    * MSVC

---

# 🔨 Build & Run

## Using g++

From the project root:

```bash
g++ -std=c++14 -Wall -Wextra main.cpp src/*.cpp -o calculator
```

Run:

```bash
./calculator
```

On Windows:

```bash
calculator.exe
```

---

## Using CMake

Create a build directory:

```bash
mkdir build
cd build
```

Generate build files:

```bash
cmake ..
```

Build:

```bash
cmake --build .
```

Run:

```bash
./calculator
```

On Windows:

```bash
calculator.exe
```

---

# 📊 Example History

After several calculations, `history.txt` may contain:

```text
2+3 = 5
(4-2)*3 = 6
10/2 = 5
5.5+2.5 = 8
```

---

# 🚀 Future Improvements

Possible future extensions include:

* Power operator `^`
* Modulo operator `%`
* Square root
* Trigonometric functions
* More advanced mathematical functions
* GUI using Qt
* Unit testing
* Database-based history
* Command-line arguments
* Better syntax error messages
* Expression AST
* More advanced tokenizer
* Support for variables

The architecture is designed so that new features can be added without
rewriting the entire calculator.

---

# 📚 Learning Objectives

This project demonstrates practical use of:

* C++ OOP
* Classes and objects
* Encapsulation
* Abstraction
* Inheritance
* Polymorphism
* Composition
* Interfaces
* Smart pointers
* Exception handling
* STL containers
* `std::stack`
* `std::vector`
* `std::unordered_map`
* `std::unordered_set`
* File I/O
* Dependency Injection
* SOLID principles
* Strategy Pattern
* Repository Pattern
* Shunting Yard algorithm
* Infix-to-postfix conversion

---

# 👨‍💻 Project Goal

The main goal of this project is not only to build a working calculator,
but to demonstrate how **clean Object-Oriented design and SOLID principles**
can be applied to a real C++ application.

The architecture focuses on:

```text
Clean Code
    +
Separation of Responsibilities
    +
Abstraction
    +
Polymorphism
    +
Extensibility
    +
Maintainability
```



