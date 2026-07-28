//
// Created by 20111 on 7/27/2026.
//

#include "../include/Evaluator.h"


Evaluator::Evaluator() {
    operatorMap["+"] = add;
    operatorMap["-"] = minus;
    operatorMap["*"] = multiply;
    operatorMap["/"] = divide;

}

double Evaluator::evaluate_postfix(const vector<string>& postfix) {

    stack<double> outcome;
    double firstNum;
    double secNum;
    for(const string& c : postfix) {
        if(isdigit(c[0])||isdigit(c[1])||c[0]=='.'){ outcome.push(stod(c)); }
        else {
            firstNum=outcome.top(); outcome.pop();
            secNum=outcome.top(); outcome.pop();
          outcome.push(operatorMap[c](secNum,firstNum));

        }
    }
    return outcome.top();
};
