//
// Created by 20111 on 7/30/2026.
//

#include "../include/FileHistoryRepository.h"
#include <fstream>
#include <iostream>
using namespace std;

FileHistoryRepository::FileHistoryRepository(string filePath) : filePath(filePath) {}

void FileHistoryRepository::record(const string& expression, double result) {
    ofstream file(filePath, ios ::app);
    if (!file.is_open()) {
        cout << "Unable to open history file.\n";
        return;
    }
    file << expression << " = " << result << std::endl;
}
void FileHistoryRepository::printAll() const {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "History file not found.\n";
        return;
    }

    cout << "\n============ History ============\n";
    string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void FileHistoryRepository::clear() {
    ofstream file(filePath, ios::trunc);
    cout << "History cleared successfully.\n";
}
