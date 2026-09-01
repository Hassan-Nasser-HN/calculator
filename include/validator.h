//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_VALIDATOR_H
#define CALCULATOR_VALIDATOR_H
#include <string>

#include "OperatorRegistry.h"
using namespace std;
class validator {

private:
    const OperatorRegistry& operators;

     void removeSpaces(std::string& expression) const;
     bool isEmpty(const string& expression) const;
     bool hasValidCharacters(const string& expression) const;
     bool hasValidOperators(const string& expression)const;
     bool hasBalancedParentheses(const std::string& expression)const;
public:
    explicit validator(const OperatorRegistry& operatorRegistry);

    bool validateExpression(string& expression) const;


};


#endif //CALCULATOR_VALIDATOR_H