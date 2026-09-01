//
// Created by 20111 on 27/06/2026.
//
#include "include/ConsoleUI.h"
#include "include/FileHistoryRepository.h"

int main() {
    FileHistoryRepository historyRepository("history.txt");
    ConsoleUI app(historyRepository);
    app.start();
    return 0;
}
