//
// Created by 20111 on 7/29/2026.
//

#ifndef CALCULATOR_CONSOLEUI_H
#define CALCULATOR_CONSOLEUI_H

#include "Calculator.h"
#include "HistoryRepository.h"



class ConsoleUI {
public:
    explicit ConsoleUI(HistoryRepository& historyRepository);

    void start();

private:
    HistoryRepository& history;
    Calculator calculator;

    void showMenu() const;
    void basicCalculator();
};


#endif //CALCULATOR_CONSOLEUI_H