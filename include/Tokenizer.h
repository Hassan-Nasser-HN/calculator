//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_TOKENIZER_H
#define CALCULATOR_TOKENIZER_H
#include <string>
#include <vector>

#include "ExpressionUtils.h"
using namespace std;

class Tokenizer:protected ExpressionUtils{
    public:
    vector<string> tokenize(const string& exp);
private:


};


#endif //CALCULATOR_TOKENIZER_H