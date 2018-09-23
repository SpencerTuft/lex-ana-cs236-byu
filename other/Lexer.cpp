//
// Created by Spencer Tuft on 9/13/18.
//

#include "Lexer.h"

Lexer::Lexer(std::string &fileName, const std::vector<Lexeme> &words) : inputStream(fileName) {
  string value;
  while(inputStream.currentChar() != -1) {
    char c = inputStream.currentChar();
    value.push_back(c);

    for (auto word : words) {
      if (word.match(value)) {
        std::cout << "Match found for [" << value << "] in " << word.getId()<< std::endl;
        word.process(state, value, tokens);
      }
    }

    inputStream.forward();
  }

  std::cout << std::endl << "Done." << std::endl;
}
