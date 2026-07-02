//
// Created by 20111 on 27/06/2026.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class calculator {
private:

public:

    double evaluate_postfix(const vector<string>& postfix);
    double add(double firstNum, double secNum);
    double minus(double firstNum, double secNum);
    double multiply(double firstNum, double secNum);
    double divide(double firstNum, double secNum);
    /*
    double mod(double firstNum, double secNum);
    double power(double firstNum, int secNum);
    double root(double firstNum, int secNum);
    double sin(double firstNum);
    double cos(double firstNum);
    double tan(double firstNum);
    double cot(double firstNum);
    double sinh(double firstNum);
    double cosh(double firstNum);
    double tanh(double firstNum);
    double coth(double firstNum);
    */
};


#endif //CALCULATOR_CALCULATOR_H