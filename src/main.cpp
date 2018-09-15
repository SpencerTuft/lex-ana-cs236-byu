#include <fstream>
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
  const string inputFile = argv[1];
  ifstream ifs(inputFile.c_str());

  vector<char> input;
  char c;

  // Store characters in memory
  while (!ifs.eof()) {
    ifs.get(c);
    input.push_back(c);
  }
  ifs.close();

  const Lexer lexer(input);

  return 0;
}