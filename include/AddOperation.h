//
// Created by 20111 on 8/18/2026.
//

#ifndef CALCULATOR_ADDOPERATION_H
#define CALCULATOR_ADDOPERATION_H
#include "operation.h"


class AddOperation:public operation{
public:
    double execute(double firstOperand, double secondOperand) const override;

};


#endif //CALCULATOR_ADDOPERATION_H