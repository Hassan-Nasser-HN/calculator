//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_TOKENIZER_H
#define CALCULATOR_TOKENIZER_H
#include <string>
#include <vector>
#include "OperatorRegistry.h"
using namespace std;

class Tokenizer{

    public:
    explicit Tokenizer(const OperatorRegistry& operatorRegistry);

    vector<string> tokenize(const string& exp) const;
private:
    const OperatorRegistry& operators;

};


#endif //CALCULATOR_TOKENIZER_H