//
// Created by 20111 on 02/07/2026.
//

#include "../include/Tokenizer.h"


Tokenizer::Tokenizer(const OperatorRegistry& operatorRegistry) : operators(operatorRegistry) {}

vector<string> Tokenizer::tokenize(const string& exp) const {

    vector<string> result;
    string token;
    for (int i = 0; i < exp.size(); i++) {
        char c=exp[i];

        if (isdigit(c)||c=='.') {token.push_back(c);continue;}

        if (c == '-') {

            bool isUnary = (i == 0);
            if (!isUnary) {
                string previous(1, exp[i - 1]);
                isUnary = operators.isOperator(previous) || exp[i - 1] == '(';
            }
            if (isUnary) {
                token.push_back(c);
            } else {
                if (!token.empty()) {
                    result.push_back(token);
                    token.clear();
                }
                result.push_back("-");
            }

        }

        else if (c == '(') {
            token.push_back(c);
            result.push_back(token);
            token.clear();
        } else if (c == ')') {
            if (!token.empty()) {
                result.push_back(token);
                token.clear();
            }
            result.push_back(std::string(1, c));
        } else {
            std::string current(1, c);
            if (operators.isOperator(current)) {
                if (!token.empty()) {
                    result.push_back(token);
                    token.clear();
                }
                result.push_back(current);
            }
        }
    }

    if (!token.empty()) {
        result.push_back(token);
    }

    return result;

}
