//
// Created by 20111 on 02/07/2026.
//

#include "include/parser.h"





vector<string> parser::infix_to_postfix(const vector<string>& exp){
    stack<string> op;
    vector<string> result;

    for (const string& c : exp){

        if (isdigit(c[0])||isdigit(c[1]) || c[0]=='.'){result.push_back(c);}

        else if (c[0] == '('){op.push(c);}

        else if (c[0] == ')'){
            while (!op.empty() && op.top()[0] != '('){
                result.push_back(op.top());
                op.pop();
            }
            if (!op.empty()) op.pop();
        }
        else if (isOperator(c)){

            while (!op.empty() &&op.top()[0] != '(' &&precedence(op.top()) >= precedence(c))
            {
                result.push_back(op.top());
                op.pop();
            }

            op.push(c);
        }
    }


    while (!op.empty())
    {
        result.push_back(op.top());
        op.pop();
    }

    return result;
}
