//
// Created by 20111 on 8/18/2026.
//

#ifndef CALCULATOR_MULTIPLYOPERATION_H
#define CALCULATOR_MULTIPLYOPERATION_H
#include "operation.h"


class MultiplyOperation: public operation {
    public:
     double execute(double firstOperand, double secondOperand) const override;
};


#endif //CALCULATOR_MULTIPLYOPERATION_H