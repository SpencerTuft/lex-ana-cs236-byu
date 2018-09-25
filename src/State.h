//
// Created by Spencer Tuft on 9/21/18.
//

#ifndef LEX_ANA_CS236_BYU_STATE_H
#define LEX_ANA_CS236_BYU_STATE_H

#include <string>
#include "InputStream.h"
#include "Token.h"

class State {
 private:
  std::string id;
  bool (&f)(InputStream &inputStream, Token &token, std::string &state);

 public:
  State(std::string identifier, bool (&transition)(InputStream &inputStream, Token &token, std::string &state));

  bool process(InputStream &inputStream, Token &currentToken, std::string &currentState) {
    return this->f(inputStream, currentToken, currentState);
  }

  std::string getId() { return id; }
};

#endif //LEX_ANA_CS236_BYU_STATE_H
