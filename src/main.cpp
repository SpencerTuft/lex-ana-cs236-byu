#include <iostream>
#include <vector>

#include "Lexer.h"
#include "Lexeme.h"
#include "DataLog.h"

/**
 * Main process
 * @param argc = argument count
 * @param argv = argument vector
 * @return
 */
int main(int argc, const char **argv) {
  string inputFileName = string(argv[1]);
  const vector<Lexeme> language{
      Lexeme("IDENTIFIER", "^[a-zA-Z]$",
             new Lexeme("IDENTIFIER", "^[a-zA-Z][a-zA-Z0-9]*", nullptr, handleIdentifier),
             handleIdentifier)
  };
  Lexer lexer(inputFileName, language);
  return 0;
}