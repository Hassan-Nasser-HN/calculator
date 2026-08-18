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

        include/parser.h
        include/Tokenizer.h
        include/validator.h
        include/Evaluator.h


        src/parser.cpp
        src/Tokenizer.cpp
        src/validator.cpp
        src/Evaluator.cpp
        main.cpp
        src/ExpressionUtils.cpp
        include/ExpressionUtils.h
        src/ConsoleUI.cpp
        include/ConsoleUI.h
        src/History.cpp
        include/History.h







)
