#include <utility>

//
// Created by Spencer Tuft on 9/13/18.
//

#ifndef LEX_ANA_CS236_BYU_TOKEN_H
#define LEX_ANA_CS236_BYU_TOKEN_H

#include <string>

class Token {
 private:
  std::string t = ""; // the token type
  std::string v = ""; // the value of the token
  int l = 0; // the token starting line number
 public:
  Token() = default;
  Token(int lineNumber)
      : l(lineNumber) {}
  Token(std::string &type, char &input)
      : t(type) {
    this->addValue(input);
  };
  Token(std::string &type, std::string &input)
      : t(type) {
    v = input;
  };
  Token(std::string &type, char &input, int line)
      : t(type), l(line) {
    this->addValue(input);
  };
  Token(std::string &type, std::string &input, int line)
      : t(type), l(line) {
    v = input;
  };

  void setLine(int lineNumber) {
    l = lineNumber;
  }
  void setType(std::string type) {
    t = type;
  }
  void addValue(char input) {
    v.push_back(input);
  }
  void setValue(char input) {
    v = input;
  }
  void setValue(std::string input) {
    v = input;
  }
  std::string getValue() const {
    return v;
  }
  std::string toString() const {
    return "(" + t + ",\"" + v + "\"," + std::to_string(l) + ")";
  }
};

#endif //LEX_ANA_CS236_BYU_TOKEN_H
