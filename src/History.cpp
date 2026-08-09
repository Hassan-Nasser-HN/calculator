//
// Created by 20111 on 7/30/2026.
//

#include "../include/History.h"

void History::inputeHistory(const string &exp, double result) {
    ofstream file("history.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Unable to open history file.\n";
        return;
    }

    file << exp << " = " << result << endl;

    file.close();
}

void History::outputeHistory() {
    ifstream file("history.txt");

    if (!file.is_open())
    {
        cout << "History file not found.\n";
        return;
    }
    string line;
    cout << "\n============ History ============\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void History::clearHistory() {
    ofstream file("history.txt", ios::trunc);

    file.close();

    cout << "History cleared successfully.\n";
}
