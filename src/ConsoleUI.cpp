//
// Created by 20111 on 7/29/2026.
//

#include "../include/ConsoleUI.h"

#include <iostream>

#include "include/validator.h"

using namespace std;

void ConsoleUI::start(){
    int choice;
    do{
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice){
            case 1:
                basicCalculator();
                break;
            case 2:
                history.outputeHistory();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;

    } while (choice != 0);
}


void ConsoleUI::showMenu() {

    cout << "=====================================\n";
    cout << "          Math Application\n";
    cout << "=====================================\n";
    cout << "1. Basic Calculator\n";
    cout<<"2. Show History\n";

    cout << "0. Exit\n";

    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

void ConsoleUI::basicCalculator()
{
    string expression;
    char answer;

    Tokenizer tokenizer;
    parser parser;
    Evaluator evaluator;

    do{
        cout << "\n========== Basic Calculator ==========\n";
        cout << "Enter an expression: ";

        getline(cin, expression);

        if (validator::validation_expression(expression))
        {
            vector<string> tokens = tokenizer.tokenize(expression);

            vector<string> postfix =
                    parser.infix_to_postfix(tokens);

            double result =evaluator.evaluate_postfix(postfix);

            cout << "Result: " << result << endl;
            history.inputeHistory(expression,result);
        }
        else
        {
            cout << "Invalid expression.\n";
        }


        cout << "\nDo you want to perform another calculation? (Y/N): ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (answer == 'Y' || answer == 'y');
}
