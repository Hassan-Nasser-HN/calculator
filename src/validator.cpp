//
// Created by 20111 on 02/07/2026.
//

#include "include/validator.h"


bool validator::validation_expression(string test) {


    set<string> invalid = {
        "++", "+*", "+/",
         "-+", "**", "*/",
        "//", "/*","..","()",")("
    };

    for (int i = 0; i < test.length() - 1; i++)
    {
        string temp = test.substr(i, 2);

        if (invalid.count(temp))
            return false;
    }

    return true;
};