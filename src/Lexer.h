//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_Lexer_H
#define LEX_ANA_CS236_BYU_Lexer_H

#include <functional>
#include <vector>
#include <iostream>
#include <map>

#include "Token.h"
#include "State.h"
#include "InputStream.h"

typedef std::map<std::string, State> States;

class Lexer {
 private:
  InputStream inputStream;
  Token currentToken = Token(inputStream.getLineNumber());
  std::vector<Token> tokens;
  std::string currentState = "START";
  States states;

 public:
  explicit Lexer(std::string &fileName, std::vector<State> inputStates);
  void analyze();
  std::string toString();
};

#endif //LEX_ANA_CS236_BYU_Lexer_H
