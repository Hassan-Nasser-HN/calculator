//
// Created by 20111 on 02/07/2026.
//

#include "../include/validator.h"
#include <unordered_set>
#include <stack>
#include <cctype>

validator::validator(const OperatorRegistry& operatorRegistry) : operators(operatorRegistry) {}



bool validator::validateExpression( string& expression) const {
    removeSpaces(expression);

    return !isEmpty(expression) &&
          hasValidCharacters(expression) &&
          hasBalancedParentheses(expression) &&
          hasValidOperators(expression);

}

void validator::removeSpaces( string &expression) const {
   string temp;
    for (char ch : expression) {
        if (!isspace(ch)) {temp += ch;}
    }
    expression = temp;
}


bool validator::isEmpty(const string &expression) const {
    return expression.empty();
}

bool validator::hasValidCharacters(const string &expression) const{

    const unordered_set<char>& validOperatorChars = operators.operatorCharacters();
     for (char ch : expression) {

        if (isdigit(ch) || ch == '.' || ch == '(' || ch == ')') continue;
        if (validOperatorChars.count(ch)) continue;
        return false;
    }
    return true;



}

bool validator::hasValidOperators(const string &expression) const{

    for (size_t i = 0; i + 1 < expression.size(); i++) {

        std::string first(1, expression[i]);
        std::string second(1, expression[i + 1]);

        if (expression[i] == '.' && expression[i + 1] == '.') return false;
        if (expression[i] == '(' && expression[i + 1] == ')') return false;
        if (expression[i] == ')' && expression[i + 1] == '(') return false;

        if (operators.isOperator(first) && operators.isOperator(second)) {
            bool secondIsUnaryMinus = (expression[i + 1] == '-');
            if (!secondIsUnaryMinus) return false;
        }
    }

    return true;
}

bool validator::hasBalancedParentheses(const string& expression)const {

    stack<char> st;
    for(char ch : expression){

        if(ch == '(')st.push(ch);
        else if(ch == ')'){
            if(st.empty()) return false;
            st.pop();
        }
        else continue;
    }
    return st.empty();
}