//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_VALIDATOR_H
#define CALCULATOR_VALIDATOR_H
#include <string>
#include <set>
#include <stack>
using namespace std;

class validator {

private:

    static bool isEmpty(const string& expression);
    static bool hasValidCharacters(const string& expression);
    static bool hasValidOperators(const string& expression);
    static bool hasBalancedParentheses(const std::string& expression);
public:
    static bool validation_expression( string& test);
    static void  removeSpaces( string& expression);

};


#endif //CALCULATOR_VALIDATOR_H