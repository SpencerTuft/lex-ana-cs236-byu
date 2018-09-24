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
    State("STRING", fstring),
    State("IDENTIFIER", fidentifier)
//    State("COMMENT", fcomment)
  };
  Lexer lexer(inputFileName, states);
  std::cout << "Token List:" << std::endl << lexer.toString();
  return 0;
}