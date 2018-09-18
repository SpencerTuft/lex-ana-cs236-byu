//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_TOKENIZER_H
#define LEX_ANA_CS236_BYU_TOKENIZER_H

#include <vector>
#include "Token.h"
#include "./InputStream.h"

using namespace std;

class Lexer {
 private:
  InputStream inputStream;
  vector<Token> tokens;

 public:
  Lexer(string& fileName): inputStream(fileName){

  }
};

#endif //LEX_ANA_CS236_BYU_TOKENIZER_H
