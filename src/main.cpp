#include <iostream>
#include <vector>
#include <string>

#include "Lexer.h"
#include "State.h"
#include "Processes.h"
#include "Routes.h"

/**
 * Main process
 * @param argc = argument count
 * @param argv = argument vector
 * @return
 */
int main(int argc, const char *argv[]) {
  // Define my states
  std::vector<State> states{
      State("WHITESPACE", rwhitespace, pwhitespace),
      State("COLON", rcolon, pcolon),
      State("COMMA", rcomma, pcomma),
      State("PERIOD", rperiod, pperiod),
      State("Q_MARK", rqmark, pqmark),
      State("MULTIPLY", rmultiply, pmultiply),
      State("ADD", radd, padd),
      State("STRING", rstring, pstring),
      State("POSSIBLE_STRING_END", nullptr, ppstring),
      State("IDENTIFIER", ridentifier, pidentifier),
      State("COMMENT", rcomment, pcomment),
      State("PAREN", rparen, pparen),
      State("UNDEFINED", nullptr, pund)
  };
  std::string fileName = argv[1];

  std::string inputFileName = std::string(fileName);
  Lexer lexer(inputFileName, states);
  lexer.analyze();
  std::cout << lexer.toString() << std::endl;
  return 0;
}