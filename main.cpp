//
// Created by 20111 on 27/06/2026.
//
// /*
// /*
// Version 2 - Tokenization and Expression Parsing Update(AI)
//
// New Features:
// - Added a tokenizer to split the input expression into tokens.
// - Supports multi-digit numbers (e.g., 12, 345, 1000).
// - Supports floating-point numbers (e.g., 3.14, 0.5).
// - Supports basic unary minus (negative numbers) in valid positions.
// - Ignores whitespace in the input expression.
// - Converts infix expressions to postfix notation using a cleaner precedence-based algorithm.
// - Evaluates postfix expressions correctly.
// - Supports the four basic arithmetic operations:
//   - Addition (+)
//   - Subtraction (-)
//   - Multiplication (*)
//   - Division (/)
// - Supports parentheses to control operator precedence.
// - Uses Object-Oriented Programming by separating arithmetic operations into a Calculator class.
// - Uses std::stack and std::vector from the C++ Standard Library.
// - Replaced character-by-character parsing with token-based parsing.
// - Renamed operation() to evaluate_postfix() for better readability.
//
// Current Limitations:
// - Unary minus is supported only in basic cases.
// - No validation for invalid mathematical expressions.
// - No protection against stack underflow when the expression is incorrect.
// - No handling for mismatched parentheses.
// - Invalid characters are not detected.
// - Multiple decimal points inside a number are not validated.
// - Division by zero handling depends on the Calculator class implementation.
// - Error handling can be improved using exceptions.
// - The project can be further refactored into dedicated Tokenizer, Parser, and Evaluator classes.
//
// Future Improvements:
// - Add full unary operator support.
// - Improve expression validation.
// - Add exception handling.
// - Detect invalid operators and malformed expressions.
// - Support mathematical functions (sqrt, sin, cos, pow, etc.).
// - Support exponentiation (^).
// - Add modulus (%) operator.
// - Improve the console user interface.
// - Add unit tests.
// - Refactor the project following SOLID principles.
// */

#include "include/calculator.h"
#include "include/validator.h"
#include "include/Tokenizer.h"
#include "include/parser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string expression;
    char answer;

    Tokenizer tokenizer;
    calculator calculator;
    parser parser;

    do {
        cout << "Enter an expression: "<<endl;
         getline(cin,expression);
         if (validator::validation_expression(expression)) {
             vector<string> exp= parser.infix_to_postfix(tokenizer.tokenize(expression));
             double result = calculator.evaluate_postfix(exp);
             cout << "result: "<<result << endl;
         }
         else{cout << "Invalid expression" << endl;}

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> answer;

    }while (answer == 'Y' || answer == 'y');
}





