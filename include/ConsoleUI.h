//
// Created by 20111 on 7/29/2026.
//

#ifndef CALCULATOR_CONSOLEUI_H
#define CALCULATOR_CONSOLEUI_H
#include <iostream>
#include <limits>
#include <include/Tokenizer.h>
#include<include/Parser.h>
#include<include/Evaluator.h>

using namespace std;


class ConsoleUI {
public:
    void start();
private:
  void showMenu();
  void basicCalculator();



};


#endif //CALCULATOR_CONSOLEUI_H