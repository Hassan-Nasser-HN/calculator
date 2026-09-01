//
// Created by 20111 on 7/30/2026.
//

#ifndef CALCULATOR_HISTORY_H
#define CALCULATOR_HISTORY_H

#include "HistoryRepository.h"
#include <string>

using namespace std;
class FileHistoryRepository :public HistoryRepository{
private:
    string filePath;

public:
    explicit FileHistoryRepository(string filePath = "history.txt");

    void record(const string& expression, double result) override;
    void printAll() const override;
    void clear() override;





};


#endif //CALCULATOR_HISTORY_H