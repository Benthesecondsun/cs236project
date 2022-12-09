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
        Token.h CommaAutomaton.cpp CommaAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h Q_MarkAutomaton.cpp Q_MarkAutomaton.h Left_ParenAutomaton.cpp Left_ParenAutomaton.h Right_ParenAutomaton.cpp Right_ParenAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h SchemesAutomaton.cpp SchemesAutomaton.h FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h IdAutomaton.cpp IdAutomaton.h StringAutomaton.cpp StringAutomaton.h CommentAutomaton.cpp CommentAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Rule.cpp Rule.h Header.cpp Header.h MyTuple.cpp MyTuple.h Relation.cpp Relation.h Database.cpp Database.h Interpreter.cpp Interpreter.h Graph.cpp Graph.h node.cpp node.h)
