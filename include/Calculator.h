//
// Created by 20111 on 8/26/2026.
//
#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include "validator.h"
#include"Tokenizer.h"
#include"parser.h"
#include"Evaluator.h"
#include"OperatorRegistry.h"
#include"HistoryRepository.h"

using namespace std;

/**
 * @brief Main calculator class that coordinates all calculator components.
 *
 * The Calculator class is responsible for managing the complete calculation
 * process, starting from expression validation and tokenization to parsing,
 * evaluation, and storing the calculation in history.
 */
class Calculator {
private:

    OperatorRegistry operatorRegistry;
    validator validator;
    Tokenizer tokenizer;
    parser parser;
    Evaluator evaluator;
    HistoryRepository& history;
    public:
    Calculator(HistoryRepository& historyRepository);
    double calculate(string expression);

};


#endif //CALCULATOR_CALCULATOR_H