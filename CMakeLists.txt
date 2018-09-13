cmake_minimum_required(VERSION 3.7)
project(lex-ana-cs236-byu)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "*.cpp" "*.h")
add_executable(lex-ana-cs236-byu ${SOURCES})