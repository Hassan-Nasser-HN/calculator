//
// Created by 20111 on 8/26/2026.
//

#include "../include/Calculator.h"
#include <stdexcept>

Calculator::Calculator(HistoryRepository& historyRepository)
    : operatorRegistry(),
      validator(operatorRegistry),
      tokenizer(operatorRegistry),
      parser(operatorRegistry),
      evaluator(operatorRegistry),
      history(historyRepository) {}

double Calculator::calculate(string expression) {
    if (!validator.validateExpression(expression)) {
        throw invalid_argument("Invalid expression.");
    }

    vector<string> tokens = tokenizer.tokenize(expression);
    vector<string> postfix = parser.infixToPostfix(tokens);
    double result = evaluator.evaluatePostfix(postfix);

    history.record(expression, result);
    return result;
}