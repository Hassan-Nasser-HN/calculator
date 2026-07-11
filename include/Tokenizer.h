//
// Created by 20111 on 02/07/2026.
//

#ifndef CALCULATOR_TOKENIZER_H
#define CALCULATOR_TOKENIZER_H
#include <string>
#include <vector>
#include <set>
using namespace std;

class Tokenizer {
    public:
    vector<string> tokenize(const string& exp);
private:
    static  bool isOperator(const char& exp);

};


#endif //CALCULATOR_TOKENIZER_H