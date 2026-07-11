//
// Created by 20111 on 27/06/2026.
//

#include "../include/calculator.h"



double calculator::evaluate_postfix(const vector<string>& postfix) {

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

                    outcome.push(add(firstNum, secNum));

                    break;
                case '-':
                    firstNum = outcome.top(); outcome.pop();

                    secNum = outcome.top(); outcome.pop();

                    outcome.push( minus(secNum, firstNum));

                    break;
                case '*':
                    firstNum = outcome.top(); outcome.pop();

                    secNum = outcome.top(); outcome.pop();

                    outcome.push( multiply(firstNum, secNum));

                    break;
                case '/':
                    firstNum = outcome.top(); outcome.pop();

                    secNum = outcome.top(); outcome.pop();

                    outcome.push( divide(secNum, firstNum));

                    break;
                default:
                    throw invalid_argument("Unknown operator");


            }




        }




    }
    return outcome.top();
};


double calculator::add(double firstNum, double secNum) {return firstNum + secNum;}


double calculator::minus(double firstNum, double secNum) {return firstNum - secNum;}


double calculator::multiply(double firstNum, double secNum) {return firstNum * secNum;}


double calculator::divide(double firstNum, double secNum) {

    if (secNum == 0) throw invalid_argument("Division by zero");
    else return firstNum / secNum;

}


