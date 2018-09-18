//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_TOKENIZER_H
#define LEX_ANA_CS236_BYU_TOKENIZER_H

#include <vector>
#include <iostream>
#include "Token.h"
#include "./InputStream.h"

using namespace std;

class Lexer {
 private:
  InputStream inputStream;
  vector<Token> tokens;

 public:
  explicit Lexer(string& fileName): inputStream(fileName){
    cout << "Created new Lexer" << endl;
  }
};

#endif //LEX_ANA_CS236_BYU_TOKENIZER_H
