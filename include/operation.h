//
// Created by 20111 on 8/18/2026.
//

#ifndef CALCULATOR_OPERATION_H
#define CALCULATOR_OPERATION_H


class operation {
public:
    virtual double execute(double firstOperand, double secondOperand) const = 0;
    virtual ~operation() = default;

};


#endif //CALCULATOR_OPERATION_H