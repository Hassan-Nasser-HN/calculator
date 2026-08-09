//
// Created by 20111 on 7/28/2026.
//

#ifndef CALCULATOR_EXPRESSIONUTILS_H
#define CALCULATOR_EXPRESSIONUTILS_H
#include <string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class ExpressionUtils {
    private:
    unordered_map< string,  int> operators;

protected:
    ExpressionUtils();
    bool isOperator(const string& exp);
    int precedence(string  op);

};


#endif //CALCULATOR_EXPRESSIONUTILS_H