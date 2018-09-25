#include <iostream>
#include <vector>

#include "Lexer.h"
#include "State.h"
#include "DataLog.h"

/**
 * Main process
 * @param argc = argument count
 * @param argv = argument vector
 * @return
 */
int main(int argc, const char **argv) {
  std::string inputFileName = std::string(argv[1]);
  const std::vector<State> states {
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
  Lexer lexer(inputFileName, states);
  std::cout << lexer.toString();
  return 0;
}