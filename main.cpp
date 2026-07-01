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

#include <iostream>
#include <calculator.h>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
using namespace std;
vector<string> tokenize(const string& exp);
vector<string> infix_to_postfix(const vector<string>& exp);
double evaluate_postfix(const vector<string>& postfix);


int main() {
    string expression;
    char answer;
    do {
        cout << "Enter an expression: "<<endl;
         cin >> expression;

        vector<string> exp= infix_to_postfix(tokenize(expression));
        double result = evaluate_postfix(exp);
        cout << "result: "<<result << endl;

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> answer;

    }while (answer == 'Y' || answer == 'y');
}


int precedence(char op){

    if (op == '*' || op == '/') return 2;

    if (op == '+' || op == '-') return 1;

    return 0;
}

vector<string> infix_to_postfix(const vector<string>& exp){
    stack<string> op;
   vector<string> result;

    for (const string& c : exp){

        if (isdigit(c[0])||isdigit(c[1]) || c[0]=='.'){result.push_back(c);}

        else if (c[0] == '('){op.push(c);}

        else if (c[0] == ')'){
            while (!op.empty() && op.top()[0] != '('){
                result.push_back(op.top());
                op.pop();
            }
            if (!op.empty()) op.pop();
        }
        else if (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/'){

            while (!op.empty() &&op.top()[0] != '(' &&precedence(op.top()[0]) >= precedence(c[0]))
            {
                result.push_back(op.top());
                op.pop();
            }

            op.push(c);
        }
    }


    while (!op.empty())
    {
        result.push_back(op.top());
        op.pop();
    }

    return result;
}

double evaluate_postfix(const vector<string>& postfix) {
    calculator calculator;
    stack<double> outcome;
    double firstNum;
    double secNum;
    for(const string& c : postfix) {
        if(isdigit(c[0])||isdigit(c[1])||c[0]=='.'){ outcome.push(stod(c)); }
        else {
            switch(c[0]) {
                case '+':
                 firstNum = outcome.top(); outcome.pop();

                 secNum = outcome.top(); outcome.pop();

                 outcome.push( calculator.add(firstNum, secNum));

                    break;
                case '-':
                    firstNum = outcome.top(); outcome.pop();

                    secNum = outcome.top(); outcome.pop();

                    outcome.push( calculator.minus(secNum, firstNum));

                    break;
                case '*':
                    firstNum = outcome.top(); outcome.pop();

                    secNum = outcome.top(); outcome.pop();

                    outcome.push( calculator.multiply(firstNum, secNum));

                    break;
                case '/':
                    firstNum = outcome.top(); outcome.pop();

                    secNum = outcome.top(); outcome.pop();

                    outcome.push( calculator.divide(secNum, firstNum));

                    break;
                default:
                    throw invalid_argument("Unknown operator");


            }




        }




    }
    return outcome.top();


};
// ---------------------------tokenize---------------------
// ---------------------------tokenize---------------------

vector<string> tokenize(const string& exp) {
    vector<string> result;
    string token;
    for (int i = 0; i < exp.length(); i++) {
        char c=exp[i];
        if (isdigit(c)||c=='.') {
            token.push_back(c);
        }
        else if (c == '-' &&
        (i == 0 ||
         exp[i-1] == '+' ||
         exp[i-1] == '-' ||
         exp[i-1] == '*' ||
         exp[i-1] == '/' ||
         exp[i-1] == '('))
        {
            token.push_back(c);
        }
        else if ( c=='+' || c=='-'  || c=='*' || c=='/') {
            if (!token.empty()) {
                result.push_back(token);
                token.clear();
            }
            token.push_back(c);
            result.push_back(token);
            token.clear();
        }
        else if (c=='(') {
            token.push_back(c);
            result.push_back(token);
            token.clear();
        }
        else if ( c==')') {
            result.push_back(token);
            token.clear();
            token.push_back(c);
            result.push_back(token);
            token.clear();
        }
        else if (isspace(c)) {
            continue;
        }

    }
    if (!token.empty()) {
        result.push_back(token);
    }

    return result;


};