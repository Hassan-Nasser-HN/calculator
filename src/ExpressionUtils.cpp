//
// Created by 20111 on 7/28/2026.
//

#include "../include/ExpressionUtils.h"


ExpressionUtils::ExpressionUtils() {
    operators["+"] = 1;
    operators["-"] =1;
    operators["*"] = 2;
    operators["/"] = 2;

}

bool ExpressionUtils::isOperator(const string &exp) {return (operators.count(exp))? 1:0;};

int ExpressionUtils::precedence(string  op){return (operators.count(op))?  operators[op]:0;}
