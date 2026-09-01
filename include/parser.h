//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H
#include <string>
#include <vector>
#include <stack>
#include <set>

#include "OperatorRegistry.h"
using namespace std;

class parser:protected OperatorRegistry{
private:
    const OperatorRegistry& operators;
public:
    explicit parser(const OperatorRegistry& operatorRegistry);

    vector<string> infixToPostfix(const vector<string>& tokens) const;






};


#endif //CALCULATOR_PARSER_H