//
// Created by 20111 on 02/07/2026.
//

#include "include/validator.h"


bool validator::validation_expression(const string& test) {

    return !isEmpty(test) &&
          hasValidCharacters(test) &&
          hasBalancedParentheses(test) &&
          hasValidOperators(test);


};

bool validator::isEmpty(const string &expression) {return expression.empty();}

bool validator::hasValidCharacters(const string &expression) {

    static  const  set<char> valid = { '(', ')', '/', '*', '-', '+','.'};
    for (char ch : expression) {
        if (isspace(ch)||isdigit(ch)){continue;}

        else if (!valid.count(ch)) {return false;}
    }
    return true;
}

bool validator::hasValidOperators(const string &expression) {
   static  const  set<string> invalid = {
        "++", "+*", "+/",
         "-+", "**", "*/",
        "//", "/*","..","()",")(" };

    for (int i = 0; i < expression.size(); i++)
    {
        string temp = expression.substr(i, 2);

        if (invalid.count(temp))
            return false;
    }

    return true;
}

bool validator::hasBalancedParentheses(const string& expression) {
    stack<char> st;

    for(char ch : expression){

        if(ch == '(')
            st.push(ch);

        else if(ch == ')'){
            if(st.empty()) return false;

            st.pop();
        }
        else continue;
    }

    return st.empty();
}