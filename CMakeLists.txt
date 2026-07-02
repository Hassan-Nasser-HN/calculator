cmake_minimum_required(VERSION 4.1)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(calculator
        include/calculator.h
        include/parser.h
        include/Tokenizer.h
        include/validator.h

        src/calculator.cpp
        src/parser.cpp
        src/Tokenizer.cpp
        src/validator.cpp

        main.cpp)
