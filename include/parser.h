//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class parser {
private:
    vector<string> infix_to_postfix(const vector<string>& exp);

    public:
    int precedence(char op);
    bool isOperator(const char& op);




};


#endif //CALCULATOR_PARSER_H