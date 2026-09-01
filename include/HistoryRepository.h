//
// Created by 20111 on 8/21/2026.
//

#ifndef CALCULATOR_HISTORYREPOSITORY_H
#define CALCULATOR_HISTORYREPOSITORY_H
#include <string>
using namespace std;
class HistoryRepository {

public:
        virtual void record(const string & expression, double result) = 0;
        virtual void printAll() const = 0;
        virtual void clear() = 0;
        virtual ~HistoryRepository() = default;


};


#endif //CALCULATOR_HISTORYREPOSITORY_H