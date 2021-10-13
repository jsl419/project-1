CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
project(project-1)
set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(project-1
        prj1/AddAutomaton.cpp
        prj1/AddAutomaton.h
        prj1/Automaton.h
        prj1/ColonAutomaton.cpp
        prj1/ColonAutomaton.h
        prj1/ColonDashAutomaton.cpp
        prj1/ColonDashAutomaton.h
        prj1/CommaAutomaton.cpp
        prj1/CommaAutomaton.h
        prj1/CommentAutomaton.cpp
        prj1/CommentAutomaton.h
        prj1/FactsAutomaton.cpp
        prj1/FactsAutomaton.h
        prj1/IDAutomaton.cpp
        prj1/IDAutomaton.h
        prj1/LeftParenAutomaton.cpp
        prj1/LeftParenAutomaton.h
        prj1/Lexer.cpp
        prj1/Lexer.h
        main.cpp
        prj1/MultiplyAutomaton.cpp
        prj1/MultiplyAutomaton.h
        prj1/PeriodAutomaton.cpp
        prj1/PeriodAutomaton.h
        prj1/QMarkAutomaton.cpp
        prj1/QMarkAutomaton.h
        prj1/QueriesAutomaton.cpp
        prj1/QueriesAutomaton.h
        prj1/RightParenAutomaton.cpp
        prj1/RightParenAutomaton.h
        prj1/RulesAutomaton.cpp
        prj1/RulesAutomaton.h
        prj1/SchemesAutomaton.cpp
        prj1/SchemesAutomaton.h
        prj1/StringAutomaton.cpp
        prj1/StringAutomaton.h
        prj1/Token.cpp
        prj1/Token.h
        Parser.cpp
        Parser.h
        DatalogProgram.cpp DatalogProgram.h Rule.cpp Rule.h Predicate.cpp Predicate.h parameter.cpp parameter.h)