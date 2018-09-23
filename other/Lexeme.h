//
// Created by Spencer Tuft on 9/20/18.
//

#ifndef LEX_ANA_CS236_BYU_LEXEME_H
#define LEX_ANA_CS236_BYU_LEXEME_H

#include <regex>
#include <string>
#include <iostream>
#include "../src/Token.h"

class Lexeme {
 private:
  std::string id;
  std::regex reg;
  Lexeme *n;
  void (&t)(int &state, std::string &value, std::vector<Token> &tokens);
  static void defFunc(int &state, std::string &value, std::vector<Token> &tokens) {
    std::cout << "Invoked Lexeme default transition function" << std::endl;
  }

 public:
  Lexeme(std::string identifier, std::string expression)
      : id(identifier), reg(std::regex(expression)), t(defFunc) {
    std::cout << "Invoked basic Lexeme constructor" << std::endl;
  }
  Lexeme(std::string identifier, std::string expression, Lexeme *next)
      : id(identifier), reg(std::regex(expression)), n(next), t(defFunc) {
    std::cout << "Invoked chain Lexeme constructor" << std::endl;
  };
  Lexeme(std::string identifier, std::string expression, Lexeme *next, void (&transition)(int &state, std::string &value, std::vector<Token> &tokens))
      : id(identifier), reg(std::regex(expression)), n(next), t(transition) {
    std::cout << "Invoked chain-transition Lexeme constructor" << std::endl;
  };
  void process(int &state, std::string &value, std::vector<Token> &tokens) {
    this->t(state, value, tokens);
  }
  bool match(std::string &value) const {
    return std::regex_match(value, reg);
  }
  std::string getId() const {
    return id;
  }
};

#endif //LEX_ANA_CS236_BYU_LEXEME_H
