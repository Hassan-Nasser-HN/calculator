//
// Created by 20111 on 7/28/2026.
//

#ifndef CALCULATOR_EXPRESSIONUTILS_H
#define CALCULATOR_EXPRESSIONUTILS_H

#include <memory>
#include <string>
#include<unordered_set>
#include<unordered_map>
#include "operation.h"
using namespace std;

class OperatorRegistry {
    private:
    struct  OperatorInfo {
        int precedence;
        shared_ptr<operation> operation;
    };

    unordered_map<string,OperatorInfo> operations;
    unordered_set<char> knownOperatorCharacters;




public:
    void registerOperation(const string& symbol, int precedenceValue,shared_ptr<operation> operation);
    OperatorRegistry();
    bool isOperator(const string& token) const;
    int precedence(const string& token) const;
    double apply(const string& symbol, double firstOperand, double secondOperand) const;

    const unordered_set<char>& operatorCharacters() const;





};


#endif //CALCULATOR_EXPRESSIONUTILS_H