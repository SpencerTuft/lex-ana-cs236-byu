//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_TOKENIZER_H
#define LEX_ANA_CS236_BYU_TOKENIZER_H

#include <vector>
#include <fstream>
#include <iostream>
#include "./Token.h"

using namespace std;

class Lexer {
 private:
  vector<Token> tokens;

 public:
  Lexer(vector<char>& input){
    for (int i = 0; i < input.size(); i++){

    }
  }
  ~Lexer() = default;
};

#endif //LEX_ANA_CS236_BYU_TOKENIZER_H
