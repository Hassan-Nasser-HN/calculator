//
// Created by 20111 on 27/06/2026.
//
// /*
// /*
/*
 * Version 3 - Architecture, Validation, and Code Quality Update  (AI)
 *
 * New Features:
 * - Refactored the project into dedicated classes:
 *   - Tokenizer
 *   - Parser
 *   - Evaluator
 *   - Calculator
 * - Improved code organization following the Single Responsibility Principle (SRP).
 * - Added better expression validation before evaluation.
 * - Improved unary minus handling in more valid scenarios.
 * - Added detection for invalid characters.
 * - Added validation for mismatched parentheses.
 * - Added validation for malformed mathematical expressions.
 * - Added protection against stack underflow during postfix evaluation.
 * - Improved floating-point number parsing and validation.
 * - Improved error reporting with descriptive messages.
 * - Enhanced readability by simplifying parsing and evaluation logic.
 * - Improved console user interface and menu navigation.
 * - Optimized the infix-to-postfix conversion algorithm.
 *
 * Supported Features:
 * - Multi-digit numbers.
 * - Floating-point numbers.
 * - Unary minus.
 * - Parentheses.
 * - Addition (+)
 * - Subtraction (-)
 * - Multiplication (*)
 * - Division (/)
 *
 * Current Limitations:
 * - Exponentiation (^) is not supported.
 * - Modulus (%) is not supported.
 * - Mathematical functions (sqrt, sin, cos, tan, log, etc.) are not implemented.
 * - Variables and constants are not supported.
 * - Expression history is not available.
 * - Error handling can still be enhanced using custom exception classes.
 *
 * Future Improvements:
 * - Apply the remaining SOLID principles throughout the project.
 * - Introduce an abstract Operation interface for arithmetic operations.
 * - Add support for exponentiation (^).
 * - Add modulus (%) operator.
 * - Support mathematical functions (sqrt, sin, cos, tan, log, pow).
 * - Implement expression history.
 * - Add memory functions (M+, M-, MR, MC).
 * - Create a graphical user interface using Qt.
 * - Add comprehensive unit tests.
 * - Improve documentation using Doxygen.
 */




#include<include/ConsoleUI.h>

int main() {
    ConsoleUI app;
    app.start();
}

