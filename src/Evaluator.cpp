//
// Created by 20111 on 7/27/2026.
//

#include "../include/Evaluator.h"
#include <stack>
#include <stdexcept>

Evaluator::Evaluator(const OperatorRegistry& operatorRegistry) : operators(operatorRegistry) {}

bool Evaluator::isNumber(const string& token) {
    if (token.empty()) return false;
    return isdigit(token[0]) ||
           (token.size() > 1 && isdigit(token[1])) ||
           token[0] == '.';
}

double Evaluator::evaluatePostfix(const vector<string>& postfix) const{

    stack<double> values;

    for (const string& token : postfix) {
        if (isNumber(token)) {
            values.push(stod(token));
        } else {
            if (values.size() < 2) {
                throw runtime_error("Malformed expression: not enough operands for '" + token + "'");
            }
            double secondOperand = values.top(); values.pop();
            double firstOperand = values.top(); values.pop();
            values.push(operators.apply(token, firstOperand, secondOperand));
        }
    }
    if (values.size() != 1) {
        throw runtime_error("Malformed expression: leftover operands");
    }

    return values.top();
};
