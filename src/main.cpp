#include <iostream>
#include <vector>

#include "Lexer.h"

using namespace std;

/**
 * Main process
 * @param argc = argument count
 * @param argv = argument vector
 * @return
 */
int main(int argc, const char **argv) {
  string inputFileName = string(argv[1]);
  Lexer lexer(inputFileName);

  return 0;
}