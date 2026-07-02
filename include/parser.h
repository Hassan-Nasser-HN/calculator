//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H
#include <string>
#include <vector>
#include <stack>
using namespace std;

class parser {
    public:
    int precedence(char op);



    vector<string> infix_to_postfix(const vector<string>& exp);
};


#endif //CALCULATOR_PARSER_H