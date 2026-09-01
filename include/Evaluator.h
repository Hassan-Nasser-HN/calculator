//
// Created by 20111 on 7/27/2026.
//

#ifndef CALCULATOR_EVALUATOR_H
#define CALCULATOR_EVALUATOR_H
#include "../include/OperatorRegistry.h"
#include <string>
#include <vector>

using namespace std;
class Evaluator {
private:
    const OperatorRegistry& operators;
    static bool isNumber(const std::string& token);
public:
    Evaluator();
    explicit Evaluator(const OperatorRegistry& operatorRegistry);
    double evaluatePostfix(const vector<string>& postfix) const;

};


#endif //CALCULATOR_EVALUATOR_H