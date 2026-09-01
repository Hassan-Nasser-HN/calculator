cmake_minimum_required(VERSION 4.1)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(calculator
        include/operation.h
        include/AddOperation.h
        include/MultiplyOperation.h
        include/SubtractOperation.h
        include/DivideOperation.h

        src/AddOperation.cpp
        src/MultiplyOperation.cpp
        src/SubtractOperation.cpp
        src/DivideOperation.cpp

        include/Calculator.h
        include/ConsoleUI.h
        include/OperatorRegistry.h
        include/parser.h
        include/Tokenizer.h
        include/validator.h
        include/Evaluator.h

        src/Calculator.cpp
        src/ConsoleUI.cpp
        src/OperatorRegistry.cpp
        src/parser.cpp
        src/Tokenizer.cpp
        src/validator.cpp
        src/Evaluator.cpp

        include/HistoryRepository.h
        include/FileHistoryRepository.h
        src/FileHistoryRepository.cpp

        main.cpp
)
