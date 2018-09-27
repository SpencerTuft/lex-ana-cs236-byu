#include <iostream>
#include <vector>
#include <string>

#include "Lexer.h"
#include "State.h"
#include "DataLog.h"

/**
 * Main process
 * @param argc = argument count
 * @param argv = argument vector
 * @return
 */
int main(int argc, const char *argv[]) {
  // Define my states
  std::vector<State> states{
      State("START", fstart),
      State("COLON", fcolon),
      State("COMMA", fcomma),
      State("PERIOD", fperiod),
      State("Q_MARK", fqmark),
      State("MULTIPLY", fmultiply),
      State("ADD", fadd),
      State("STRING", fstring),
      State("POSSIBLE_STRING_END", fpstring),
      State("IDENTIFIER", fidentifier),
      State("COMMENT", fcomment),
      State("PAREN", fparen),
      State("UNDEFINED", fund)
  };
  std::string fileName = argv[1];

  std::string inputFileName = std::string(fileName);
  Lexer lexer(inputFileName, states);
  std::cout << lexer.toString() << std::endl;
  return 0;
}