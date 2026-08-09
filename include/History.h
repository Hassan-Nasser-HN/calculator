//
// Created by 20111 on 7/30/2026.
//

#ifndef CALCULATOR_HISTORY_H
#define CALCULATOR_HISTORY_H
#include <fstream>
#include <string>
#include<iostream>
using namespace std;
class History {
private:



public:
    void inputeHistory(const string& exp,double result);
    void outputeHistory();
    void clearHistory();
};


#endif //CALCULATOR_HISTORY_H