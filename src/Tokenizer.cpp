//
// Created by 20111 on 02/07/2026.
//

#include "include/Tokenizer.h"


vector<string> Tokenizer::tokenize(const string& exp) {
    vector<string> result;
    string token;
    for (int i = 0; i < exp.length(); i++) {
        char c=exp[i];
        if (isdigit(c)||c=='.') {
            token.push_back(c);
        }
        else if (c == '-' &&
        (i == 0 ||
         exp[i-1] == '+' ||
         exp[i-1] == '-' ||
         exp[i-1] == '*' ||
         exp[i-1] == '/' ||
         exp[i-1] == '('))
        {
            token.push_back(c);
        }
        else if ( c=='+' || c=='-'  || c=='*' || c=='/') {
            if (!token.empty()) {
                result.push_back(token);
                token.clear();
            }
            token.push_back(c);
            result.push_back(token);
            token.clear();
        }
        else if (c=='(') {
            token.push_back(c);
            result.push_back(token);
            token.clear();
        }
        else if ( c==')') {
            result.push_back(token);
            token.clear();
            token.push_back(c);
            result.push_back(token);
            token.clear();
        }
        else if (isspace(c)) {
            continue;
        }

    }
    if (!token.empty()) {
        result.push_back(token);
    }

    return result;


};