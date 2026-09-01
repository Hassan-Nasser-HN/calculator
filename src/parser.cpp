//
// Created by 20111 on 02/07/2026.
//

#include "include/parser.h"
parser::parser(const OperatorRegistry& operatorRegistry) : operators(operatorRegistry) {}
vector<string> parser::infixToPostfix(const vector<string>& tokens) const{
    stack<string> opStack;
    vector<string> result;

    for (const string& token : tokens){

        bool isNumber = isdigit(token[0]) ||
                         (token.size() > 1 && isdigit(token[1])) ||
                          token[0] == '.';

        if (isNumber) { result.push_back(token);}

        else if (token[0] == '('){opStack.push(token);}


        else if (token[0] == ')'){

            while (!opStack.empty() && opStack.top()[0] != '('){
                result.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
        }
        else if (operators.isOperator(token)) {
            while (!opStack.empty() && opStack.top()[0] != '(' &&
                operators.precedence(opStack.top()) >= operators.precedence(token)) {
                result.push_back(opStack.top());
                opStack.pop();
                }
            opStack.push(token);
        }
    }


    while (!opStack.empty())
    {
        result.push_back(opStack.top());
        opStack.pop();
    }

    return result;
}
