//
// Created by 20111 on 8/18/2026.
//

#ifndef CALCULATOR_DIVIDEOPERATION_H
#define CALCULATOR_DIVIDEOPERATION_H
#include "operation.h"


class DivideOperation:public operation{
    public:
   double execute(double firstOperand, double secondOperand) const override ;
};


#endif //CALCULATOR_DIVIDEOPERATION_H