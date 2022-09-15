cmake_minimum_required(VERSION 3.16.3)
project(cs236project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cs236project
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h)
