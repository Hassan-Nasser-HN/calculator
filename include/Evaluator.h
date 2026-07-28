//
// Created by 20111 on 7/27/2026.
//

#ifndef CALCULATOR_EVALUATOR_H
#define CALCULATOR_EVALUATOR_H
#include "operations.h"
#include <string>
#include <vector>
#include <stack>
#include <functional>
#include <unordered_map>
using namespace std;
class Evaluator: operations {
    unordered_map<string, function< double(double, double)>> operatorMap;

    public:
    Evaluator();

    double evaluate_postfix(const vector<string>& postfix);
};


#endif //CALCULATOR_EVALUATOR_H