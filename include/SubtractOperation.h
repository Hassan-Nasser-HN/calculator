//
// Created by 20111 on 8/18/2026.
//

#ifndef CALCULATOR_SUBTRACTOPERATION_H
#define CALCULATOR_SUBTRACTOPERATION_H
#include "operation.h"


class SubtractOperation: public virtual operation {

    public:
     double execute(double firstOperand, double secondOperand) const override;
};


#endif //CALCULATOR_SUBTRACTOPERATION_H