//
// Created by 20111 on 7/28/2026.
//

#include "../include/OperatorRegistry.h"

#include "../include/AddOperation.h"
#include "../include/DivideOperation.h"
#include "../include/MultiplyOperation.h"
#include "../include/SubtractOperation.h"
#include <stdexcept>


OperatorRegistry::OperatorRegistry() {
    registerOperation("+", 1, make_shared<AddOperation>());
    registerOperation("-", 1, make_shared<SubtractOperation>());
    registerOperation("*", 2, make_shared<MultiplyOperation>());
    registerOperation("/", 2, make_shared<DivideOperation>());
}



void OperatorRegistry::registerOperation(const string &symbol, int precedenceValue,
                                         shared_ptr<operation> operation) {
    operations[symbol]=OperatorInfo{precedenceValue, move(operation)};
    for (char c : symbol) {
        knownOperatorCharacters.insert(c);
    }
}
bool OperatorRegistry::isOperator(const string &token) const {
    return operations.count(token)>0;
}

int OperatorRegistry::precedence(const string &token) const {
    if (operations.count(token) > 0) {
        return operations.at(token).precedence;
    }
    return 0;
}

double OperatorRegistry::apply(const string &symbol, double firstOperand, double secondOperand) const {
    auto it = operations.find(symbol);
    if (it == operations.end()) {
        throw invalid_argument("Unknown operator: " + symbol);
    }
    return it->second.operation->execute(firstOperand, secondOperand);
}
const std::unordered_set<char>& OperatorRegistry::operatorCharacters() const {
    return knownOperatorCharacters;
}

