//
// Created by 20111 on 27/06/2026.
//
/*
Version 1 - Initial Release(AI)
Features:
- Converts infix expressions to postfix notation using a stack.
- Evaluates postfix expressions correctly.
- Supports the four basic arithmetic operations:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
- Supports parentheses to control operator precedence.
- Uses Object-Oriented Programming by separating arithmetic operations into a Calculator class.
- Interactive console interface with the option to perform multiple calculations.
- Uses the C++ Standard Library stack for expression parsing and evaluation.

Limitations:
- Supports only single-digit numbers (e.g., 1, 5, 9).
- Does not support decimal (floating-point) numbers.
- Does not support negative numbers.
- Does not ignore spaces in the input expression.
- No validation for invalid mathematical expressions.
- No protection against stack underflow when the expression is incorrect.
- No handling for mismatched parentheses.
- Division by zero handling depends on the Calculator class implementation.
- Operator precedence logic contains repeated conditions that could be simplified.
- The code can be refactored into smaller helper functions to improve readability and maintainability.

Future Improvements:
- Add support for multi-digit numbers.
- Add support for floating-point values.
- Improve input validation and error handling.
- Simplify the infix-to-postfix conversion algorithm.
- Add support for unary minus (negative numbers).
- Improve the user interface.
- Add unit tests.
- Separate parsing and evaluation into dedicated classes following SOLID principles.

*/

#include <iostream>
#include <calculator.h>
#include <string>
#include <stack>
using namespace std;

string infix_to_postfix(string exp);
double operation(string exp);


int main() {
    string expression;
    char answer;
    do {
        cout << "Enter an expression: "<<endl;
        cin >> expression;

        string exp= infix_to_postfix(expression);
        double result = operation(exp);
        cout << "result: "<<result << endl;

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> answer;

    }while (answer == 'Y' || answer == 'y');
}

string infix_to_postfix(string exp) {
     stack<char> op;
     string result;
    for(int i = 0; i < exp.length(); i++){
        char c = exp[i];
        //-------------------1-------------------
        if(isdigit(c)){ result.push_back(c); }
        //-------------------2--------------------
        else if(c=='+' || c=='-' || c=='*' || c=='/'){
            //----------------------2.1------------------------
            if(op.empty() || op.top()=='(') {op.push(c); }
             //----------------------2.2-------------------------
           else if((op.top()=='+' || op.top()=='-') && (c=='*' || c=='/')) {op.push(c);}
            //----------------------2.3---------------------------
            else if((op.top()=='*' || op.top()=='/') && (c=='+' || c=='-')){
                while(!op.empty() && (op.top()=='*' || op.top()=='/') && op.top()!='(') {
                    result.push_back(op.top());
                    op.pop();
                }
                op.push(c);
            }
            //-------------------------2.4-----------------------------
            else if((op.top()=='*' || op.top()=='/') && (c=='*' || c=='/')){
                while(!op.empty() && (op.top()=='*' || op.top()=='/') && op.top()!='(') {
                    result.push_back(op.top());
                    op.pop();
                }
                op.push(c);
            }
            //---------------------2.5----------------------------------
            else if((op.top()=='+' || op.top()=='-') && (c=='+' || c=='-')){

                while(!op.empty() && (op.top()=='+' || op.top()=='-') && op.top()!='('){
                    result.push_back(op.top());
                    op.pop();
                }
                op.push(c);
            }
            //------------------------end---------------------------------
        }
        // ------------------3--------------------
        else if(c=='('){ op.push(c);}
       //--------------------4----------------------
        else if(c==')'){
            while(!op.empty() && op.top()!='('){
               result.push_back(op.top());

                op.pop();

            }
            if(!op.empty()){

                op.pop();
            }
        }
    }

    //------------5-----------------
    while (!op.empty()) {
        result.push_back(op.top());
        op.pop();
    }

    cout << endl;

  return result;
};
double operation(string exp) {
    calculator calculator;
    stack<double> outcome;
    double result;
    double firstNum;
    double secNum;
    for(int i = 0; i < exp.length(); i++) {
        if(isdigit(exp[i])){ outcome.push(exp[i]-'0'); }
        else {
            switch(exp[i]) {
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


            }




        }




    }
    return outcome.top();




};