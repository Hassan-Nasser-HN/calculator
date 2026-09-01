#include "../include/ConsoleUI.h"
#include <iostream>
#include <limits>

using namespace std;

/**
 * @brief Constructs the ConsoleUI.
 *
 * Both the UI and Calculator share the same HistoryRepository,
 * allowing calculations to be stored and displayed consistently.
 *
 * @param historyRepository Reference to the history repository.
 */
ConsoleUI::ConsoleUI(HistoryRepository& historyRepository)
    : history(historyRepository),
      calculator(historyRepository) {}

/**
 * @brief Starts the main application loop.
 *
 * The user can:
 * 1. Open the basic calculator.
 * 2. Display calculation history.
 * 0. Exit the application.
 */
void ConsoleUI::start() {
    int choice;

    do {
        showMenu();

        // Read the user's menu choice.
        cin >> choice;

        // Handle non-numeric input safely.
        if (cin.fail()) {
            cin.clear();
            choice = -1;
        }

        // Remove the remaining characters from the input buffer.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

            case 1:
                // Open the basic calculator.
                basicCalculator();
                break;

            case 2:
                // Display all previously calculated expressions.
                history.printAll();
                break;

            case 0:
                // Exit the application.
                cout << "Goodbye!\n";
                break;

            default:
                // Handle invalid menu choices.
                cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;

    } while (choice != 0);
}

/**
 * @brief Displays the main application menu.
 */
void ConsoleUI::showMenu() const {
    cout << "=====================================\n";
    cout << "          Math Application\n";
    cout << "=====================================\n";
    cout << "1. Basic Calculator\n";
    cout << "2. Show History\n";
    cout << "0. Exit\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

/**
 * @brief Runs the basic calculator interface.
 *
 * Allows the user to enter mathematical expressions and displays
 * the calculated result. Exceptions such as invalid expressions
 * or division by zero are caught and displayed as error messages.
 */
void ConsoleUI::basicCalculator() {
    string expression;
    char answer;

    do {
        cout << "\n========== Basic Calculator ==========\n";
        cout << "Enter an expression: ";

        // Read the complete mathematical expression.
        getline(cin, expression);

        try {
            // Calculate the expression using the Calculator class.
            double result = calculator.calculate(expression);

            cout << "Result: " << result << endl;
        }
        catch (const exception& e) {
            // Handle calculation errors without crashing the application.
            cout << "Error: " << e.what() << endl;
        }

        cout << "\nDo you want to perform another calculation? (Y/N): ";

        cin >> answer;

        // Clear the remaining input before the next expression.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (answer == 'Y' || answer == 'y');
}