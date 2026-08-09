//
// Created by 20111 on 02/07/2026.
//

#include "include/Tokenizer.h"



vector<string> Tokenizer::tokenize(const string& exp) {
    vector<string> result;
    string token;
    for (int i = 0; i < exp.size(); i++) {
        char c=exp[i];

        if (isdigit(c)||c=='.') {token.push_back(c);}

        if (c == '-')
        {
            if (i == 0)
            {
                token.push_back(c);
            }
            else
            {
                string previous(1, exp[i - 1]);

                if (isOperator(previous) ||
                    exp[i - 1] == '(')
                {
                    token.push_back(c);
                }
            }
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
        else
        {
            string current(1, c);

            if (isOperator(current))
            {
                if (!token.empty())
                {
                    result.push_back(token);
                    token.clear();
                }

                result.push_back(current);
            }
        }

    }

    if (!token.empty()) {result.push_back(token);}


    return result;


}

