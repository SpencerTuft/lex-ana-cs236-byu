//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_Lexer_H
#define LEX_ANA_CS236_BYU_Lexer_H

#include <functional>
#include <vector>
#include <iostream>

#include "Token.h"
#include "InputStream.h"
#include "Lexeme.h"

class Lexer {
 private:
  int state = 0;
  InputStream inputStream;
  vector<Token> tokens;

 public:
  explicit Lexer(std::string& fileName, const std::vector<Lexeme>& words): inputStream(fileName) {
    string value;
    while(inputStream.currentChar() != -1) {
      value = inputStream.currentChar();

      for (auto word : words) {
        if (word.match(value)) {
          word.process(state, value);
        } else {
          std::cout << "No match found for [" << value << "]" << std::endl;
        }
      }

      inputStream.forward();
    }

    std::cout << std::endl << "Done." << std::endl;
  };
};

#endif //LEX_ANA_CS236_BYU_Lexer_H
