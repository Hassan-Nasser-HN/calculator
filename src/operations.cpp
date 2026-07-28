//
// Created by 20111 on 27/06/2026.
//

#include "../include/operations.h"





double operations::add(double firstNum, double secNum) {return firstNum + secNum;}


double operations::minus(double firstNum, double secNum) {return firstNum - secNum;}


double operations::multiply(double firstNum, double secNum) {return firstNum * secNum;}


double operations::divide(double firstNum, double secNum) {

    if (secNum == 0) throw invalid_argument("Division by zero");
    else return firstNum / secNum;

}


