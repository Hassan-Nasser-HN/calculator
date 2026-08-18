//
// Created by 20111 on 8/18/2026.
//

#include "../include/DivideOperation.h"
#include <stdexcept>
using namespace std;

double DivideOperation::execute(double firstOperand, double secondOperand) const {
    if (secondOperand == 0) {
        throw invalid_argument("Division by zero");
    }
    return firstOperand / secondOperand;
}

