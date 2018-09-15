cmake_minimum_required(VERSION 3.8)
project(lex-ana-cs236-byu)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "./src/*.cpp" "./src/*.h")
add_executable(lex-ana-cs236-byu ${SOURCES} src/Token.h src/Lexer.cpp src/Lexer.h)